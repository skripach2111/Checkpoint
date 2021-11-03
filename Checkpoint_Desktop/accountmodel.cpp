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
    case AccountModel::Role::Read:
    {
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

void AccountModel::appendRow(const QString &login, const QString& password, const int &privilege, const int &worker)
{
    DataHash account;
    account[ LOGIN ] = login;
    account[ PRIVILEGE ] = privilege;
    account[ WORKER ] = worker;
    account[ PASSWORD ] = password;
    account[ STATE_ROW ] = StatesRows::ADDED;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( account );
    endInsertRows();
}

void AccountModel::updateRow(int row, const QString &login, const QString& password, const int &privilege, const int &worker)
{
    beginResetModel();

    model[ row ][ PRIVILEGE ] = privilege;
    model[ row ][ WORKER ] = worker;
    model[ row ][ PASSWORD ] = password;
    model[ row ][ STATE_ROW ] = StatesRows::EDITED;

    endResetModel();
}

void AccountModel::removeRow(int row)
{
    model[ row ][ STATE_ROW ] = StatesRows::DELETED;
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
            account[ PASSWORD ] = query.value( PASSWORD );
            account[ STATE_ROW ] = StatesRows::NOT_EDITED;

            model.append( account );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

bool AccountModel::submit()
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[ i ][ STATE_ROW ] != StatesRows::NOT_EDITED)
        {
            if(model[ i ][ STATE_ROW ] == StatesRows::ADDED)
            {
                query.prepare("INSERT INTO :table (login, password, privilege, worker) VALUES(:login, :password, :privilege, :worker)");
                query.bindValue(":table", table);
                query.bindValue(":login", model[ i ][ LOGIN ]);
                query.bindValue(":password", model[ i ][ PASSWORD ]);
                query.bindValue(":privilege", model[ i ][ PRIVILEGE ]);
                query.bindValue(":worker", model[ i ][ WORKER ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::EDITED)
            {
                query.prepare("UPDATE :table SET password = :password, privilege = :privilege, worker = :worker WHERE login = :login");
                query.bindValue(":table", table);
                query.bindValue(":login", model[ i ][ LOGIN ]);
                query.bindValue(":password", model[ i ][ PASSWORD ]);
                query.bindValue(":privilege", model[ i ][ PRIVILEGE ]);
                query.bindValue(":worker", model[ i ][ WORKER ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::DELETED)
            {
                query.prepare("DELETE FROM :table WHERE login = :login");
                query.bindValue(":table", table);
                query.bindValue(":login", model[ i ][ LOGIN ]);

                query.exec();
            }
        }
    }

    return true;
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
