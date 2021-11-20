#include "checkpointmodel.h"

CheckpointModel::CheckpointModel(QObject *parent) : QAbstractTableModel(parent)
{

}

CheckpointModel::CheckpointModel(const CheckpointModel &modelNew)
{
    for(int i = 0; i < this->model.size(); i++)
        model.append(modelNew.model.at(i));
}

int CheckpointModel::columnCount(const QModelIndex &parent) const
{
    return LAST;
}

int CheckpointModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

QVariant CheckpointModel::data( const QModelIndex& index, int role ) const {
//    if(
//            !index.isValid() ||
//            m_persons.count() <= index.row() ||
//            ( role != Qt::DisplayRole && role != Qt::EditRole )
//            ) {
//        return QVariant();
//    }

    if(!index.isValid())
        return QVariant();

    switch (role)
    {
    case Qt::DisplayRole:
    {
        return model[ index.row() ][ index.column() ];
    }
    case ID:
    {
        return model[ index.row() ][ ID - Qt::UserRole -1 ];
    }
    case TITLE:
    {
        return model[ index.row() ][ TITLE - Qt::UserRole -1 ];
    }
    case LOCATION:
    {
        return model[ index.row() ][ LOCATION - Qt::UserRole -1 ];
    }
    case LVL_ACCESS:
    {
        return model[ index.row() ][ LVL_ACCESS - Qt::UserRole -1 ];
    }
    default:
    {
        return QVariant();
    }
    }
}

void CheckpointModel::appendRow(const int &id, const QString &title, const QString &location, const QString &lvlAccess)
{
    DataHash record;
    record[ ID - Qt::UserRole -1 ] = id;
    record[ TITLE - Qt::UserRole -1 ] = title;
    record[ LOCATION - Qt::UserRole -1 ] = location;
    record[ LVL_ACCESS - Qt::UserRole -1 ] = lvlAccess;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

QHash<int, QByteArray> CheckpointModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[ID] = "id";
    roles[TITLE] = "title";
    roles[LOCATION] = "location";
    roles[LVL_ACCESS] = "lvl_access";

    return roles;
}
