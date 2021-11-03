#include "positionmodel.h"

PositionModel::PositionModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int PositionModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int PositionModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant PositionModel::headerData( int section, Qt::Orientation orientation, int role ) const
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
    case FLAG:
        return "FLAG";
    }

    return QVariant();
}

QVariant PositionModel::data( const QModelIndex& index, int role ) const {
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
    case PositionModel::Role::Read:
    {
        return model[ index.row() ][ Column( index.column() ) ];
    }
    default:
    {
        return QVariant();
    }
    }
}

Qt::ItemFlags PositionModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void PositionModel::updateRow(int row, const int &id, const QString &title, const bool &flag)
{
    beginResetModel();

    model[ row ][ TITLE ] = title;
    model[ row ][ FLAG ] = flag;
    model[ row ][ STATE_ROW ] = StatesRows::EDITED;

    endResetModel();
}

void PositionModel::appendRow( const int& id, const QString& title, const bool& flag ) {
    DataHash record;
    record[ ID ] = id;
    record[ TITLE ] = title;
    record[ FLAG ] = flag;
    record[ STATE_ROW ] = StatesRows::ADDED;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

bool PositionModel::select()
{
    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        model.clear();

        int row = model.count();
        beginInsertRows( createIndex(0, 0), row, row+query.size()-1 );

        DataHash record;
        do
        {
            record[ ID ] = query.value( ID ).toInt();
            record[ TITLE ] = query.value( TITLE ).toString();
            record[ FLAG ] = query.value( FLAG ).toBool();
            record[ STATE_ROW ] = StatesRows::NOT_EDITED;

            model.append( record );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

bool PositionModel::submit()
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[ i ][ STATE_ROW ] != StatesRows::NOT_EDITED)
        {
            if(model[ i ][ STATE_ROW ] == StatesRows::ADDED)
            {
                query.prepare("INSERT INTO :table (title, flag) VALUES(:title, :flag)");
                query.bindValue(":table", table);
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::EDITED)
            {
                query.prepare("UPDATE :table SET title = :title, flag = :flag WHERE id = :id");
                query.bindValue(":table", table);
                query.bindValue(":id", model[ i ][ ID ]);
                query.bindValue(":title", model[ i ][ TITLE ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::DELETED)
            {
                query.prepare("UPDATE :table SET flag = 1 WHERE id = :id");
                query.bindValue(":table", table);
                query.bindValue(":id", model[ i ][ ID ]);

                query.exec();
            }
        }
    }

    return true;
}

void PositionModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

QVariant PositionModel::getDataById(int id, Column column)
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[i][ID].toInt() == id)
            return model[i][column];
    }
}

bool PositionModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
