#ifndef AUTHORIZATIONMODEL_H
#define AUTHORIZATIONMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>

class AuthorizationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AuthorizationModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void append( const int& worker, const QDate& date, const QTime& time, const int& state, const int& authorizer );

    bool select();
    void setTable(QString t, QSqlDatabase *database);

    enum Column {
        WORKER = 0,
        DATE,
        TIME,
        STATE,
        AUTHORIZER,
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

#endif // AUTHORIZATIONMODEL_H
