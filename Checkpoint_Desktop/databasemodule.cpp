#include "databasemodule.h"

#include <QDebug>

DatabaseModule::DatabaseModule(QObject *parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.0.100");
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
        accessModel = new QSqlTableModel(this);
        accessModel->setTable("access");
        accountModel = new QSqlTableModel(this);
        accountModel->setTable("account");
        authorizationModel = new QSqlTableModel(this);
        authorizationModel->setTable("authorization");
        checkpointModel = new QSqlTableModel(this);
        checkpointModel->setTable("checkpoint");
        positionModel = new QSqlTableModel(this);
        positionModel->setTable("position");
        privilegeModel = new QSqlTableModel(this);
        privilegeModel->setTable("privilege");
        stateModel = new QSqlTableModel(this);
        stateModel->setTable("state");
        workerModel = new QSqlTableModel(this);
        workerModel->setTable("worker");
        return true;
    }
    else
        return false;
}
