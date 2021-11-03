#include "workermodel.h"

WorkerModel::WorkerModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int WorkerModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int WorkerModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant WorkerModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case INN:
        return "ИНН";
    case PHOTO:
        return "Фото";
    case PIB:
        return "ФИО";
    case DATE_OF_BIRTH:
        return "Дата рождения";
    case PLACE_OF_REGISTRATION:
        return "Место регистрации";
    case PLACE_OF_RESIDENCE:
        return "Место проживания";
    case NUMBER_PASSPORT:
        return "Серия и номер пасспорта";
    case POSITION:
        return "Должность";
    case LVL_ACCESS:
        return "Уровень доступа";
    case FLAG:
        return "FLAG";
    }

    return QVariant();
}

QVariant WorkerModel::data( const QModelIndex& index, int role ) const {
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
        if(index.column() == POSITION)
            return positionModel->getDataById(model[ index.row() ][ Column( index.column() ) ].toInt(), PositionModel::Column::TITLE);

        if(index.column() == LVL_ACCESS)
            return accessModel->getDataById(model[ index.row() ][ Column( index.column() ) ].toInt(), AccessModel::Column::TITLE);

        return model[ index.row() ][ Column( index.column() ) ];
    }
    case WorkerModel::Role::Read:
    {
        return model[ index.row() ][ Column( index.column() ) ];
    }
    default:
    {
        return QVariant();
    }
    }
}

Qt::ItemFlags WorkerModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}

void WorkerModel::appendRow(const int &inn, const QByteArray &photo, const QString &pib, const QDate &dateOfBirth, const QString &placeOfRegistration, const QString &placeOfResidence, const QString &numberPassport, const int &position, const int &lvlAcess, const bool &flag)
{
    DataHash person;
    person[ INN ] = inn;
    person[ PHOTO ] = photo;
    person[ PIB ] = pib;
    person[ DATE_OF_BIRTH ] = dateOfBirth;
    person[ PLACE_OF_REGISTRATION ] = placeOfRegistration;
    person[ PLACE_OF_RESIDENCE ] = placeOfResidence;
    person[ NUMBER_PASSPORT ] = numberPassport;
    person[ POSITION ] = position;
    person[ LVL_ACCESS ] = lvlAcess;
    person[ FLAG ] = flag;
    person[ STATE_ROW ] = StatesRows::ADDED;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( person );
    endInsertRows();
}

void WorkerModel::updatedRow(int row, const int &inn, const QByteArray &photo, const QString &pib, const QDate &dateOfBirth, const QString &placeOfRegistration, const QString &placeOfResidence, const QString &numberPassport, const int &position, const int &lvlAcess, const bool &flag)
{
    beginResetModel();

    model[ row ][ PHOTO ] = photo;
    model[ row ][ PIB ] = pib;
    model[ row ][ DATE_OF_BIRTH ] = dateOfBirth;
    model[ row ][ PLACE_OF_REGISTRATION ] = placeOfRegistration;
    model[ row ][ PLACE_OF_RESIDENCE ] = placeOfResidence;
    model[ row ][ NUMBER_PASSPORT ] = numberPassport;
    model[ row ][ POSITION ] = position;
    model[ row ][ LVL_ACCESS ] = lvlAcess;
    model[ row ][ FLAG ] = flag;
    model[ row ][ STATE_ROW ] = StatesRows::EDITED;

    endResetModel();
}

void WorkerModel::removeRow(int row)
{
    model[ row ][ STATE_ROW ] = StatesRows::DELETED;
}

bool WorkerModel::select()
{
    query.prepare(QString("SELECT * FROM %1").arg(table));
    query.exec();
    if(query.next())
    {
        model.clear();

        int row = model.count();
        beginInsertRows( createIndex(0, 0), row, row+query.size()-1 );

        DataHash person;
        do
        {
            person[ INN ] = query.value( INN );
            person[ PHOTO ] = query.value( PHOTO );
            person[ PIB ] = query.value( PIB );
            person[ DATE_OF_BIRTH ] = query.value( DATE_OF_BIRTH );
            person[ PLACE_OF_REGISTRATION ] = query.value( PLACE_OF_REGISTRATION );
            person[ PLACE_OF_RESIDENCE ] = query.value( PLACE_OF_RESIDENCE );
            person[ NUMBER_PASSPORT ] = query.value( NUMBER_PASSPORT );
            person[ POSITION ] = query.value( POSITION );
            person[ LVL_ACCESS ] = query.value( LVL_ACCESS );
            person[ FLAG ] = query.value( FLAG );
            person[ STATE_ROW ] = StatesRows::NOT_EDITED;

            model.append( person );

        }while(query.next());

        endInsertRows();

        return true;
    }

    return false;
}

bool WorkerModel::submit()
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[ i ][ STATE_ROW ] != StatesRows::NOT_EDITED)
        {
            if(model[ i ][ STATE_ROW ] == StatesRows::ADDED)
            {
                query.prepare("INSERT INTO :table (inn, photo, pib, dateOfBirth, placeOfRegistration, placeOfResidence, numberPassport, position, lvlAccess, flag) "
                              "VALUES(:inn, :photo, :pib, :dateOfBirth, :placeOfRegistration, :placeOfResidence, :numberPassport, :position, :lvlAccess, :flag)");

                query.bindValue(":table", table);
                query.bindValue(":inn", model[ i ][ INN ]);
                query.bindValue(":photo", model[ i ][ PHOTO ]);
                query.bindValue(":pib", model[ i ][ PIB ]);
                query.bindValue(":dateOfBirth", model[ i ][ DATE_OF_BIRTH ]);
                query.bindValue(":placeOfRegistration", model[ i ][ PLACE_OF_REGISTRATION ]);
                query.bindValue(":placeOfResidence", model[ i ][ PLACE_OF_RESIDENCE ]);
                query.bindValue(":numberPassport", model[ i ][ NUMBER_PASSPORT ]);
                query.bindValue(":position", model[ i ][ POSITION ]);
                query.bindValue(":lvlAccess", model[ i ][ LVL_ACCESS ]);
                query.bindValue(":flag", model[ i ][ FLAG ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::EDITED)
            {
                query.prepare("UPDATE :table SET photo = :photo,  pib = :pib, dateOfBirth = :dateOfBirth, placeOfRegistration = :placeOfRegistration,"
                              "placeOfResidence = :placeOfResidence, numberPassport = :numberPassport, position = :position, lvlAccess = :lvlAccess"
                              "WHERE inn = :inn");

                query.bindValue(":table", table);
                query.bindValue(":inn", model[ i ][ INN ]);
                query.bindValue(":photo", model[ i ][ PHOTO ]);
                query.bindValue(":pib", model[ i ][ PIB ]);
                query.bindValue(":dateOfBirth", model[ i ][ DATE_OF_BIRTH ]);
                query.bindValue(":placeOfRegistration", model[ i ][ PLACE_OF_REGISTRATION ]);
                query.bindValue(":placeOfResidence", model[ i ][ PLACE_OF_RESIDENCE ]);
                query.bindValue(":numberPassport", model[ i ][ NUMBER_PASSPORT ]);
                query.bindValue(":position", model[ i ][ POSITION ]);
                query.bindValue(":lvlAccess", model[ i ][ LVL_ACCESS ]);

                query.exec();
            }
            else if(model[ i ][ STATE_ROW ] == StatesRows::DELETED)
            {
                query.prepare("UPDATE :table SET flag = 1 WHERE inn = :inn");

                query.bindValue(":table", table);
                query.bindValue(":inn", model[ i ][ INN ]);

                query.exec();
            }
        }
    }

    return true;
}

void WorkerModel::setTable(QString t, QSqlDatabase *database)
{
    table = t;
    db = database;
}

QVariant WorkerModel::getDataById(int inn, Column column)
{
    for(int i = 0; i < model.size(); i++)
    {
        if(model[i][INN].toInt() == inn)
            return model[i][column];
    }
}

bool WorkerModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || model.count() <= index.row() ) {
        return false;
    }

    model[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}
