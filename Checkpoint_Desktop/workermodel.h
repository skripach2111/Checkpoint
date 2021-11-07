#ifndef WORKERMODEL_H
#define WORKERMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>
#include <QBuffer>

#include "accessmodel.h"
#include "positionmodel.h"

class WorkerModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit WorkerModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const int& inn, const QByteArray& photo, const QString& pib, const QDate& dateOfBirth, const QString& placeOfRegistration,
                 const QString& placeOfResidence, const QString& numberPassport, const int& position,
                 const int& lvlAcess, const bool& flag);
    void updatedRow( int row, const int& inn, const QByteArray& photo, const QString& pib, const QDate& dateOfBirth, const QString& placeOfRegistration,
                 const QString& placeOfResidence, const QString& numberPassport, const int& position,
                 const int& lvlAcess, const bool& flag);

    void removeRow(int row);

    bool select();
    bool saveChanges();
    void setTable(QString t, QSqlDatabase *database);

    void setAccessModel(AccessModel *m_access) { accessModel = m_access; }
    void setPositionModel(PositionModel *m_position) { positionModel = m_position; }

    enum Column {
        INN = 0,
        PHOTO,
        PIB,
        DATE_OF_BIRTH,
        PLACE_OF_REGISTRATION,
        PLACE_OF_RESIDENCE,
        NUMBER_PASSPORT,
        POSITION,
        LVL_ACCESS,
        FLAG,
        STATE_ROW,
        LAST
    };

    enum Role {
        Display = 0x1,
        Read
    };

    enum StatesRows {
        NOT_EDITED = 0,
        ADDED,
        EDITED,
        DELETED
    };

    QVariant getDataById(int inn, Column column);

private:

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;

    QString table;

    AccessModel *accessModel;
    PositionModel *positionModel;
};

#endif // WORKERMODEL_H
