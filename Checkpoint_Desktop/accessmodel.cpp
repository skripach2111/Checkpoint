#include "accessmodel.h"

AccessModel::AccessModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int AccessModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int AccessModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant AccessModel::headerData( int section, Qt::Orientation orientation, int role ) const
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
    case PRIVILEGE:
        return "Привилегии";
    case FLAG:
        return "FLAG";
    }

    return QVariant();
}

QVariant AccessModel::data( const QModelIndex& index, int role ) const {
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

Qt::ItemFlags AccessModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void AccessModel::append( const int& id, const QString& title, const int& privilege, const bool& flag ) {
    DataHash access;
    access[ ID ] = id;
    access[ TITLE ] = title;
    access[ PRIVILEGE ] = privilege;
    access[ FLAG ] = flag;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( access );
    endInsertRows();
}

bool AccessModel::select()
{
    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        model.clear();

        int row = model.count();
        beginInsertRows( QModelIndex(), row, row+query.size() );

        DataHash access;
        do
        {
            access[ ID ] = query.value( ID );
            access[ TITLE ] = query.value( TITLE );
            access[ PRIVILEGE ] = query.value( PRIVILEGE );
            access[ FLAG ] = query.value( FLAG );

            model.append( access );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

void AccessModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

bool AccessModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
