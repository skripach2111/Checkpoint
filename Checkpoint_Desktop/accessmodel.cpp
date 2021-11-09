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
    }
    case AccessModel::Role::Read:
    {
        return model[ index.row() ][ Column( index.column() ) ];
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

void AccessModel::appendRow( const QString& title, const int& privilege, const bool& flag ) {
    DataHash access;
    access[ TITLE ] = title;
    access[ PRIVILEGE ] = privilege;
    access[ FLAG ] = flag;
    access[ STATE_ROW ] = StatesRows::ADDED;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( access );
    endInsertRows();
}

void AccessModel::updateRow(int row, const QString &title, const int &privilege, const bool &flag)
{
    beginResetModel();

    model[ row ][ TITLE ] = title;
    model[ row ][ PRIVILEGE ] = privilege;
    model[ row ][ FLAG ] = flag;
    model[ row ][ STATE_ROW ] = (int)StatesRows::EDITED;

    endResetModel();
}

void AccessModel::removeRow(int row)
{
    model[ row ][ STATE_ROW ] = StatesRows::DELETED;
}

bool AccessModel::select()
{
    beginResetModel();
    beginRemoveRows(createIndex(0, 0), 0, model.count());
    while(model.count() != 0)
        model.removeFirst();
    endRemoveRows();

    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        int row = model.count();
        beginInsertRows( createIndex(0, 0), row, row+query.size()-1 );

        DataHash access;
        do
        {
            access[ ID ] = query.value( ID );
            access[ TITLE ] = query.value( TITLE );
            access[ PRIVILEGE ] = query.value( PRIVILEGE );
            access[ FLAG ] = query.value( FLAG );
            access[ STATE_ROW ] = StatesRows::NOT_EDITED;

            model.append( access );

        }while(query.next());

        endInsertRows();
    }

    endResetModel();

    return false;
}


bool AccessModel::saveChanges()
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[ i ][ STATE_ROW ] != StatesRows::NOT_EDITED)
        {
            qDebug() << "!= NOT_EDIT";
            if(model[ i ][ STATE_ROW ] == StatesRows::ADDED)
            {
                qDebug() << "ADDED";
                query.prepare(QString("INSERT INTO %1 (title, privilege, flag) VALUES (:title, :privilege, :flag)").arg(table));
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":privilege", model[ i ][ PRIVILEGE ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::EDITED)
            {
                qDebug() << "EDITED";
                query.prepare(QString("UPDATE %1 SET title = :title, privilege = :privilege, flag = :flag WHERE id = :id").arg(table));
                query.bindValue(":id", model[ i ][ ID ]);
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":privilege", model[ i ][ PRIVILEGE ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::DELETED)
            {
                qDebug() << "DELETED";
                query.prepare(QString("UPDATE %1 SET flag = 1 WHERE id = :id").arg(table));
                query.bindValue(":id", model[ i ][ ID ]);

                query.exec();
            }
        }

        qDebug() << query.lastError();

    return true;
}
}

void AccessModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

QVariant AccessModel::getDataById(int id, Column column)
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[i][ID].toInt() == id)
            return model[i][column];
    }
}

bool AccessModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
