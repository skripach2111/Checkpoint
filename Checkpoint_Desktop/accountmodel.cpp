#include "accountmodel.h"

AccountModel::AccountModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int AccountModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int AccountModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant AccountModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case LOGIN:
        return "Логин";
    case PRIVILEGE:
        return "Привилегии";
    case WORKER:
        return "Сотрудник";
    }

    return QVariant();
}

QVariant AccountModel::data( const QModelIndex& index, int role ) const {
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
        if(index.column() == PRIVILEGE)
            return privilegeModel->getDataById(model[ index.row() ][ Column( index.column() ) ].toInt(), PrivilegeModel::Column::TITLE);

        if(index.column() == WORKER)
            return workerModel->getDataById(model[ index.row() ][ Column( index.column() ) ].toInt(), WorkerModel::Column::PIB);

        return model[ index.row() ][ Column( index.column() ) ];
    }
    default:
    {
        return QVariant();
    }
    }
}

Qt::ItemFlags AccountModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void AccountModel::append(const QString &login, const int &privilege, const int &worker, const bool &flag)
{
    DataHash account;
    account[ LOGIN ] = login;
    account[ PRIVILEGE ] = privilege;
    account[ WORKER ] = worker;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( account );
    endInsertRows();
}

bool AccountModel::select()
{
    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        model.clear();

        int row = model.count();
        beginInsertRows( createIndex(0, 0), row, row+query.size()-1 );

        DataHash account;
        do
        {
            account[ LOGIN ] = query.value( LOGIN );
            account[ PRIVILEGE ] = query.value( PRIVILEGE );
            account[ WORKER ] = query.value( WORKER );

            model.append( account );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

void AccountModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

bool AccountModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
