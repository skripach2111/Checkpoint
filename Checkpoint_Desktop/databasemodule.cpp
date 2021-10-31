#include "databasemodule.h"

#include <QDebug>

DatabaseModule::DatabaseModule(QObject *parent)
{
    db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("checkpoints");
}

int DatabaseModule::getPrivileges()
{
    QSqlQuery *qu;
    qu->prepare("SELECT privilege FROM account WHERE login = :login");
    qu->bindValue(":login", login);
    qu->exec();

    if(qu->next())
        return qu->value(0).toInt();
    else
        return 0;
}

bool DatabaseModule::connect(QString l, QString p)
{
    db.setUserName(l);
    db.setPassword(p);

    if(db.open())
    {
        accessModel = new AccessModel(this);
        accessModel->setTable("access", &db);
        accountModel = new AccountModel(this);
        accountModel->setTable("account", &db);
        authorizationModel = new AuthorizationModel(this);
        authorizationModel->setTable("authorization", &db);
        checkpointModel = new CheckpointModel(this);
        checkpointModel->setTable("checkpoint", &db);
        positionModel = new PositionModel(this);
        positionModel->setTable("position", &db);
        privilegeModel = new PrivilegeModel(this);
        privilegeModel->setTable("privilege", &db);
        stateModel = new StateModel(this);
        stateModel->setTable("state", &db);
        workerModel = new WorkerModel(this);
        workerModel->select();
        workerModel->setTable("worker", &db);

        accountModel->setPrivilegeModel(privilegeModel);
        accountModel->setWorkerModel(workerModel);
        authorizationModel->setWorkerModel(workerModel);
        checkpointModel->setAccesModel(accessModel);
        workerModel->setAccessModel(accessModel);
        workerModel->setPositionModel(positionModel);

        return true;
    }
    else
        return false;
}

AccessModel *DatabaseModule::getAccessModel()
{
    accessModel->select();
    return accessModel;
}

AccountModel *DatabaseModule::getAccountModel()
{
    accountModel->select();
    return accountModel;
}

AuthorizationModel *DatabaseModule::getAuthorizationModel()
{
    authorizationModel->select();
    return authorizationModel;
}

CheckpointModel *DatabaseModule::getCheckpointModel()
{
    checkpointModel->select();
    return checkpointModel;
}

PositionModel *DatabaseModule::getPositionModel()
{
    positionModel->select();
    return positionModel;
}

PrivilegeModel *DatabaseModule::getPrivilegeModel()
{
    privilegeModel->select();
    return privilegeModel;
}

StateModel *DatabaseModule::getStateModel()
{
    stateModel->select();
    return stateModel;
}

WorkerModel *DatabaseModule::getWorkerModel()
{
    workerModel->select();
    return workerModel;
}
