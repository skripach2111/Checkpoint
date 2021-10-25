#ifndef CHECKPOINTMODEL_H
#define CHECKPOINTMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>

class CheckpointModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CheckpointModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void append( const int& id, const QString& title, const QString& location, const int& lvlAccess, const bool& flag );

    bool select();
    void setTable(QString t, QSqlDatabase *database);

    enum Column {
        ID = 0,
        TITLE,
        LOCATION,
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

#endif // CHECKPOINTMODEL_H
