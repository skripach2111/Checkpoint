#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QSettings>
#include <QBuffer>

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QNetworkInterface>
#include <QDataStream>
#include <QString>
#include <QDate>
#include <QTime>

#include "databasemodule.h"

#include "accessfiltermodel.h"
#include "accountfiltermodel.h"
#include "authorizationfiltermodel.h"
#include "checkpointfiltermodel.h"
#include "positionfiltermodel.h"
#include "workerfiltermodel.h"
#include "modelforcombobox.h"
#include "modelforprint.h"

struct Client
{
    QTcpSocket *pSocket;
    bool statusConnection = false;
};

struct Host
{
    QHostAddress ip;
    int port;
};

class AppCore : public QObject
{
    Q_OBJECT

    QSettings *settings;

    DatabaseModule* db;

    QString currentWorkerLogin;

    AccessFilterModel *filterAccess;
    AccountFilterModel *filterAccount;
    AuthorizationFilterModel *filterAuthorization;
    CheckpointFilterModel *filterCheckpoint;
    PositionFilterModel *filterPosition;
    WorkerFilterModel *filterWorker;

    CheckpointModel *modelCheckpoint;
    StateModel *modelState;
    WorkerModel *modelWorker;

    int checkpoint;
    QString inn;
    int _state;

    QString login;

    ModelForComboBox *accessCombobox;
    ModelForComboBox *positionCombobox;
    ModelForComboBox *privilegeCombobox;
    ModelForComboBox *stateCombobox;
    ModelForComboBox *checkpointCombobox;
    ModelForComboBox *workerCombobox;

    Host host;

    QTcpServer* pServer;
    quint16 nNextBlockSize;

    Client client;

    QString lastError;

public:
    explicit AppCore(QObject *parent = nullptr);

    enum Privileges {
        ADMIN = 1,
        BUHGALTER,
        SB,
        VAHTA
    };

    enum COMMAND {
        AUTH_WORKER = 1,
        MESSAGE,
        AUTH,
        LISTEN,
        WORKER,
        ACCOUNT,
        ERROR,
        AUTH_COMPLETE,
        CHECKPOINTS,
        STATES
    };

    void doSendToClientsMessage(COMMAND command);

signals:
    void startServerError(QString message);
    void startServerSuccessful();
    void inputMessage(QString message);
    void serverStop();
    void clientDisconnected();
    void clientConnected();

public slots:
    void slotStart();
    void slotStop();
    void slotClientDisconnected();
    void slotReadClient();
    void slotNewConnection();
};

#endif // APPCORE_H
