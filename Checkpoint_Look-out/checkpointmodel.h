#ifndef CHECKPOINTMODEL_H
#define CHECKPOINTMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>

class CheckpointModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CheckpointModel(QObject *parent = nullptr);

    virtual int rowCount( const QModelIndex& parent ) const;
    virtual QVariant data( const QModelIndex& index, int role ) const;
    virtual QHash<int, QByteArray> roleNames() const;

    void appendRow( const int& id, const QString& title, const QString& location, const QString& lvlAccess);

    enum Roles {
        ID = Qt::UserRole + 1,
        TITLE,
        LOCATION,
        LVL_ACCESS
    };

private:

    typedef QHash< int, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;
};

#endif // CHECKPOINTMODEL_H
