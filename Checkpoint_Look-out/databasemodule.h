#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include <QObject>
#include <QQuickItem>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>

#include "accessmodel.h"
#include "accountmodel.h"
#include "authorizationmodel.h"
#include "checkpointmodel.h"
#include "positionmodel.h"
#include "privilegemodel.h"
#include "statemodel.h"
#include "workermodel.h"

class DatabaseModule : public QQuickItem
{
    Q_OBJECT
public:
    DatabaseModule();

    Q_INVOKABLE int getPrivileges();
    Q_INVOKABLE bool connect(QString l, QString p);
    Q_INVOKABLE void disconnect() { db.close(); }

    Q_INVOKABLE QSqlError lastError() { return db.lastError(); }

    Q_INVOKABLE void setHostAddress(QString address) { db.setHostName(address); _hostName = address; }
    Q_INVOKABLE void setHostPort(int port) { db.setPort(port); _hostPort = port; }

    Q_PROPERTY(QString hostAddress MEMBER _hostName WRITE setHostAddress);
    Q_PROPERTY(int hostPort MEMBER _hostPort WRITE setHostPort);

    void selectTables();

    Q_INVOKABLE bool authorizationUser(QString login, QString password);

    AccessModel* getAccessModel();
    AccountModel* getAccountModel();
    AuthorizationModel* getAuthorizationModel();
    CheckpointModel* getCheckpointModel();
    PositionModel* getPositionModel();
    PrivilegeModel* getPrivilegeModel();
    StateModel* getStateModel();
    WorkerModel* getWorkerModel();

private:
    QSqlDatabase db;
    QString login;

    AccessModel* accessModel;
    AccountModel* accountModel;
    AuthorizationModel* authorizationModel;
    CheckpointModel* checkpointModel;
    PositionModel* positionModel;
    PrivilegeModel* privilegeModel;
    StateModel* stateModel;
    WorkerModel* workerModel;

    QString _hostName;
    int _hostPort;
};

#endif // DATABASEMODULE_H
