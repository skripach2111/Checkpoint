#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>

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

    void append( const QString& login, const int& privilege, const int& worker, const bool& flag );

    bool select();
    void setTable(QString t, QSqlDatabase *database);

    void setWorkerModel(WorkerModel *m_worker) { workerModel = m_worker; }
    void setPrivilegeModel(PrivilegeModel *m_privilege) { privilegeModel = m_privilege; }

    enum Column {
        LOGIN = 0,
        PRIVILEGE,
        WORKER,
        LAST
    };

    enum Role {
        Display = 0x1,
        Read
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
