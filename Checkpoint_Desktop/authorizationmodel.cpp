#include "authorizationmodel.h"

AuthorizationModel::AuthorizationModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int AuthorizationModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int AuthorizationModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant AuthorizationModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case WORKER:
        return "Вошедший";
    case DATE:
        return "Дата";
    case TIME:
        return "Время";
    case STATE:
        return "Состояние";
    case AUTHORIZER:
        return "Дежурный";
    }

    return QVariant();
}

QVariant AuthorizationModel::data( const QModelIndex& index, int role ) const {
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

Qt::ItemFlags AuthorizationModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void AuthorizationModel::append(const int &worker, const QDate &date, const QTime &time, const int &state, const int &authorizer)
{
    DataHash record;
    record[ WORKER ] = worker;
    record[ DATE ] = date;
    record[ TIME ] = time;
    record[ AUTHORIZER ] = authorizer;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

bool AuthorizationModel::select()
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
            record[ WORKER ] = query.value( WORKER );
            record[ DATE ] = query.value( DATE );
            record[ TIME ] = query.value( TIME );
            record[ AUTHORIZER ] = query.value( AUTHORIZER );

            model.append( record );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

void AuthorizationModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

bool AuthorizationModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}