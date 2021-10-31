#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

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

class DatabaseModule : public QObject
{
    Q_OBJECT

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

public:
    DatabaseModule(QObject *parent = nullptr);

    int getPrivileges();
    bool connect(QString l, QString p);

    QSqlError lastError() { return db.lastError(); }

    void setHostAddress(QString address) { db.setHostName(address); }
    void setHostPort(int port) { db.setPort(port); }

    AccessModel* getAccessModel();
    AccountModel* getAccountModel();
    AuthorizationModel* getAuthorizationModel();
    CheckpointModel* getCheckpointModel();
    PositionModel* getPositionModel();
    PrivilegeModel* getPrivilegeModel();
    StateModel* getStateModel();
    WorkerModel* getWorkerModel();
};

#endif // DATABASEMODULE_H
