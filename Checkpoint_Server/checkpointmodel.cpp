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
        if(index.column() == LVL_ACCESS)
            return accessModel->getDataById(model[ index.row() ][ Column( index.column() ) ].toInt(), AccessModel::Column::TITLE);

        return model[ index.row() ][ Column( index.column() ) ];
    }
    case CheckpointModel::Role::Read:
    {
        return model[ index.row() ][ Column( index.column() ) ];
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

void CheckpointModel::updateRow(int row, const QString &title, const QString &location, const int &lvlAccess, const bool &flag)
{
    beginResetModel();

    model[ row ][ TITLE ] = title;
    model[ row ][ LOCATION ] = location;
    model[ row ][ LVL_ACCESS ] = lvlAccess;
    model[ row ][ FLAG ] = flag;
    model[ row ][ STATE_ROW ] = StatesRows::EDITED;

    endResetModel();
}

void CheckpointModel::removeRow(int row)
{
    model[ row ][ FLAG ] = 1;
    model[ row ][ STATE_ROW ] = StatesRows::DELETED;
}

void CheckpointModel::appendRow(const int &id, const QString &title, const QString &location, const int &lvlAccess, const bool &flag)
{
    DataHash record;
    record[ ID ] = id;
    record[ TITLE ] = title;
    record[ LOCATION ] = location;
    record[ LVL_ACCESS ] = lvlAccess;
    record[ FLAG ] = flag;
    record[ STATE_ROW ] = StatesRows::ADDED;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

bool CheckpointModel::select()
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

        DataHash record;
        do
        {
            record[ ID ] = query.value( ID );
            record[ TITLE ] = query.value( TITLE );
            record[ LOCATION ] = query.value( LOCATION );
            record[ LVL_ACCESS ] = query.value( LVL_ACCESS );
            record[ FLAG ] = query.value( FLAG );
            record[ STATE_ROW ] = StatesRows::NOT_EDITED;

            model.append( record );

        }while(query.next());

        endInsertRows();
    }

    endResetModel();

    return false;
}

bool CheckpointModel::saveChanges()
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[ i ][ STATE_ROW ] != StatesRows::NOT_EDITED)
        {
            if(model[ i ][ STATE_ROW ] == StatesRows::ADDED)
            {
                query.prepare(QString("INSERT INTO %1 (title, location, lvlAccess, flag) VALUES(:title, :location, :lvlAccess, :flag)").arg(table));
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":location", model[ i ][ LOCATION ]);
                query.bindValue(":lvlAccess", model[ i ][ LVL_ACCESS ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::EDITED)
            {
                query.prepare(QString("UPDATE %1 SET title = :title, location = :location, lvlAccess = :lvlAccess, flag = :flag WHERE id = :id").arg(table));
                query.bindValue(":id", model[ i ][ ID ]);
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":location", model[ i ][ LOCATION ]);
                query.bindValue(":lvlAccess", model[ i ][ LVL_ACCESS ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::DELETED)
            {
                query.prepare(QString("UPDATE %1 SET flag = 1 WHERE id = :id").arg(table));
                query.bindValue(":id", model[ i ][ ID ]);

                query.exec();
            }
        }
    }

    return true;
}

void CheckpointModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

QVariant CheckpointModel::getDataById(int id, Column column)
{
    for(int i = 0; i < model.size(); i++)
        if(id == model[ i ][ ID ].toInt())
            return model[ i ][ column ];
}

bool CheckpointModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
