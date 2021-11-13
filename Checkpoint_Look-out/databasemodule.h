#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include <QObject>
#include <QQuickItem>

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>

#include "../Checkpoint_Desktop/accessfiltermodel.h"
#include "../Checkpoint_Desktop/accountfiltermodel.h"
#include "../Checkpoint_Desktop/authorizationfiltermodel.h"
#include "../Checkpoint_Desktop/checkpointfiltermodel.h"
#include "../Checkpoint_Desktop/modelforcombobox.h"
#include "../Checkpoint_Desktop/positionfiltermodel.h"
#include "../Checkpoint_Desktop/statemodel.h"
#include "../Checkpoint_Desktop/workerfiltermodel.h"

class DatabaseModule : public QQuickItem
{
    Q_OBJECT
public:
    DatabaseModule();

    Q_INVOKABLE int getPrivileges();
    Q_INVOKABLE bool connect(QString l, QString p);
    Q_INVOKABLE void disconnect() { db.close(); }

    Q_INVOKABLE QSqlError lastError() { return db.lastError(); }

    Q_INVOKABLE void setHostAddress(QString address) { db.setHostName(address); }
    Q_INVOKABLE void setHostPort(int port) { db.setPort(port); }

    void selectTables();

    Q_INVOKABLE QString authorizationUser(QString login, QString password);

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
};

#endif // DATABASEMODULE_H
