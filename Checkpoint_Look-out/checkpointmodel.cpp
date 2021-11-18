#include "checkpointmodel.h"

CheckpointModel::CheckpointModel(QObject *parent) : QAbstractTableModel(parent)
{

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

    }
    case LVL_ACCESS:
    {

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
