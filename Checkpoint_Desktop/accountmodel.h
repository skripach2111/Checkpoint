#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>

#include "workermodel.h"
#include "privilegemodel.h"

class AccountModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccountModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const QString& login, const QString& password, const int& privilege, const QString& worker);
    void updateRow( int row, const QString& login, const QString& password, const int& privilege, const QString& worker);
    void removeRow( int row );

    QModelIndex getUserByLogin(QString login);

    bool select();
    bool saveChange();
    void setTable(QString t, QSqlDatabase *database);

    void setWorkerModel(WorkerModel *m_worker) { workerModel = m_worker; }
    void setPrivilegeModel(PrivilegeModel *m_privilege) { privilegeModel = m_privilege; }

    enum Column {
        LOGIN = 0,
        PASSWORD,
        PRIVILEGE,
        WORKER,
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

private:

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;

    QString table;

    WorkerModel *workerModel;
    PrivilegeModel *privilegeModel;
};

#endif // ACCOUNTMODEL_H
