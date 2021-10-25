#ifndef WORKERMODEL_H
#define WORKERMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>

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

    void append( const int& inn, const QByteArray& photo, const QString& pib, const QDate& dateOfBirth, const QString& placeOfRegistration,
                 const QString& placeOfResidence, const QString& numberPassport, const int& position,
                 const int& lvlAcess, const bool& flag);

    bool select();
    void setTable(QString t, QSqlDatabase *database);

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
        LAST
    };

private:

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;

    QString table;
};

#endif // WORKERMODEL_H
