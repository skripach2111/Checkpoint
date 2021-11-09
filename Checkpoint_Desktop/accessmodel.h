#ifndef ACCESSMODEL_H
#define ACCESSMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>

class AccessModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccessModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const QString& title, const int& privilege, const bool& flag );
    void updateRow( int row, const QString& title, const int& privilege, const bool& flag );
    void removeRow(int row);

    bool select();
    bool saveChanges();
    void setTable(QString t, QSqlDatabase *database);

    enum Column {
        ID = 0,
        TITLE,
        PRIVILEGE,
        FLAG,
        LAST,
        STATE_ROW
    };

    enum Role {
        Display = 0x1,
        Read
    };

    enum StatesRows {
        NOT_EDITED = 0x1,
        ADDED,
        EDITED,
        DELETED
    };

    QVariant getDataById(int id, Column column);

private:

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;

    QString table;
};

#endif // ACCESSMODEL_H
