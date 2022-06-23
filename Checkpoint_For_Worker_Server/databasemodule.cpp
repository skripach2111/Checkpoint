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
    QSqlQuery qu;
    qu.prepare("SELECT privilege FROM account WHERE login = :login");
    qu.bindValue(":login", login);
    qu.exec();

    qDebug() << qu.lastError();

    if(qu.next())
        return qu.value(0).toInt();
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

void DatabaseModule::selectTables()
{
    accessModel->select();
    accountModel->select();
    authorizationModel->select();
    checkpointModel->select();
    positionModel->select();
    privilegeModel->select();
    stateModel->select();
    workerModel->select();
}

QString DatabaseModule::authorizationUser(QString login, QString password)
{
    QSqlQuery query;

    query.prepare("SELECT password FROM worker WHERE login = :login");
    query.bindValue(":login", login);
    query.exec();

    if(query.next())
    {
        if(query.value(0).toString() == password)
        {
            this->login = login;
            return QString();
        }
        else
            return "Неверный логин или пароль!";
    }
    else
        return "Пользователь не найден!";
}

AccessModel *DatabaseModule::getAccessModel()
{
    return accessModel;
}

AccountModel *DatabaseModule::getAccountModel()
{
    return accountModel;
}

AuthorizationModel *DatabaseModule::getAuthorizationModel()
{
    return authorizationModel;
}

CheckpointModel *DatabaseModule::getCheckpointModel()
{
    return checkpointModel;
}

PositionModel *DatabaseModule::getPositionModel()
{
    return positionModel;
}

PrivilegeModel *DatabaseModule::getPrivilegeModel()
{
    return privilegeModel;
}

StateModel *DatabaseModule::getStateModel()
{
    return stateModel;
}

WorkerModel *DatabaseModule::getWorkerModel()
{
    return workerModel;
}
