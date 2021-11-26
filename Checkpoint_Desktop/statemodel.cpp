#include "statemodel.h"

#include <QDebug>

StateModel::StateModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int StateModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int StateModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant StateModel::headerData( int section, Qt::Orientation orientation, int role ) const
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
        return model[ index.row() ][ Column( index.column() ) ];
        break;
    }
    case StateModel::Role::Read:
    {
        return model[ index.row() ][ Column( index.column() ) ];
    }
    default:
    {
        return QVariant();
    }
    }
}

Qt::ItemFlags StateModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void StateModel::append( const int& id, const QString& title, const bool& flag ) {
    DataHash state;
    state[ ID ] = id;
    state[ TITLE ] = title;
    state[ FLAG ] = flag;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( state );
    endInsertRows();
}

bool StateModel::select()
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

        DataHash state;
        do
        {
            state[ ID ] = query.value( ID ).toInt();
            state[ TITLE ] = query.value( TITLE ).toString();
            state[ FLAG ] = query.value( FLAG ).toBool();

            model.append( state );

        }while(query.next());

        endInsertRows();
    }

    endResetModel();

    return false;
}

void StateModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

QVariant StateModel::getDataById(int id, Column column)
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[i][ID].toInt() == id)
            return model[i][column];
    }
}

bool StateModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
