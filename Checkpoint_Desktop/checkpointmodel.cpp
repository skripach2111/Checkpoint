#include "checkpointmodel.h"

CheckpointModel::CheckpointModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int CheckpointModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int CheckpointModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant CheckpointModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case ID:
        return "ID";
    case TITLE:
        return "Название";
    case LOCATION:
        return "Размещение";
    case LVL_ACCESS:
        return "Уровень доступа";
    case FLAG:
        return "FLAG";
    }

    return QVariant();
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
        return model[ index.row() ][ Column( index.column() ) ];
        break;
    }
    default:
    {
        return QVariant();
    }
    }
}

Qt::ItemFlags CheckpointModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void CheckpointModel::append(const int &id, const QString &title, const QString &location, const int &lvlAccess, const bool &flag)
{
    DataHash record;
    record[ ID ] = id;
    record[ TITLE ] = title;
    record[ LOCATION ] = location;
    record[ LVL_ACCESS ] = lvlAccess;
    record[ FLAG ] = flag;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

bool CheckpointModel::select()
{
    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        model.clear();

        int row = model.count();
        beginInsertRows( QModelIndex(), row, row+query.size() );

        DataHash record;
        do
        {
            record[ ID ] = query.value( ID );
            record[ TITLE ] = query.value( TITLE );
            record[ LOCATION ] = query.value( LOCATION );
            record[ LVL_ACCESS ] = query.value( LVL_ACCESS );
            record[ FLAG ] = query.value( FLAG );

            model.append( record );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

void CheckpointModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

bool CheckpointModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
