#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseModule : public QObject
{
    Q_OBJECT

    QSqlDatabase db;
    QString login;

    QSqlTableModel* accessModel;
    QSqlTableModel* accountModel;
    QSqlTableModel* authorizationModel;
    QSqlTableModel* checkpointModel;
    QSqlTableModel* positionModel;
    QSqlTableModel* privilegeModel;
    QSqlTableModel* stateModel;
    QSqlTableModel* workerModel;

public:
    DatabaseModule(QObject *parent = nullptr);

    int getPrivileges();
    bool connect(QString l, QString p);

    QSqlError lastError() { return db.lastError(); }
};

#endif // DATABASEMODULE_H
