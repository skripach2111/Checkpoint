#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <QObject>
#include <QQuickItem>
#include <QtNetwork>

#include "checkpointmodel.h"
#include "statemodel.h"

class ConnectionController : public QQuickItem
{
    Q_OBJECT

    QTcpSocket *tcpSocket;
    quint16 nNextBlockSize;
    QHostAddress host;
    short unsigned int port;

    Q_PROPERTY(QString login MEMBER _login WRITE setLogin);
    Q_PROPERTY(QString password MEMBER _password WRITE setPassword);
    Q_PROPERTY(CheckpointModel* checkpoint MEMBER modelCheckpoint READ getCheckpoint)
    Q_PROPERTY(StateModel* state MEMBER modelState READ getState)

    QString _login;
    QString _password;

    QString lastError;

    CheckpointModel* modelCheckpoint;
    StateModel* modelState;

    QSettings *settings;

    int checkpointId = -1;
    QString inn;
    int _state;

public:
    explicit ConnectionController(QObject *parent = 0);
    ~ConnectionController() { disconnect(); }

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

    void setLogin(QString l) { _login = l; }
    void setPassword(QString p) { _password = p; }

    Q_INVOKABLE void getCheckpointModel();
    Q_INVOKABLE void getStatesModel();
    Q_INVOKABLE void authWorker(int checkpoint, QString inn, int state);

    CheckpointModel* getCheckpoint() { return modelCheckpoint; }
    StateModel* getState() { return modelState; }

signals:
    void disconnected();
    void connected();
    void errorConnection(QString message);
    void comingCheckpointModel();
    void comingStateModel();
    void workerAuthoriazationResult(QString fio, QString position, QString lvl_access, QString date, QString time, QString state, bool color);

public slots:
    void connect();
    void disconnect();
    void send(COMMAND command);

    void slotReadyRead();
    void slotDisconnected();
    void slotConnected();
    void slotError(QAbstractSocket::SocketError);

    QVariant getSettings(QString name);
    void setSettings(QString name, QVariant value) { settings->setValue(name, value); }
};

#endif // CONNECTIONCONTROLLER_H
