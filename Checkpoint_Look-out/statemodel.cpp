#include "statemodel.h"

StateModel::StateModel(QObject *parent) : QAbstractTableModel(parent)
{

}

StateModel::StateModel(const StateModel &modelNew)
{
    for(int i = 0; i < this->model.size(); i++)
        model.append(modelNew.model.at(i));
}

int StateModel::columnCount(const QModelIndex &parent) const
{
    return LAST;
}

int StateModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

QVariant StateModel::data( const QModelIndex& index, int role ) const {
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
    default:
    {
        return QVariant();
    }
    }
}

void StateModel::appendRow(const int &id, const QString &title)
{
    DataHash record;
    record[ ID - Qt::UserRole -1 ] = id;
    record[ TITLE - Qt::UserRole -1 ] = title;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

QHash<int, QByteArray> StateModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[ID] = "id";
    roles[TITLE] = "title";

    return roles;
}
