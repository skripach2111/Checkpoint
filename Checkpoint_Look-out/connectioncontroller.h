#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <QObject>
#include <QQuickItem>
#include <QtNetwork>

#include "checkpointmodel.h"

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

    QString _login;
    QString _password;

    QString lastError;

    CheckpointModel* modelCheckpoint;

    int checkpointId = -1;
    QString inn;

public:
    explicit ConnectionController(QObject *parent = 0);
    ~ConnectionController() { disconnect(); }

    enum COMMAND {
        PING = 1,
        MESSAGE,
        AUTH,
        LISTEN,
        WORKER,
        ACCOUNT,
        ERROR,
        AUTH_COMPLETE,
        CHECKPOINTS,
        STATES,
        AUTH_WORKER
    };

    void setLogin(QString l) { _login = l; }
    void setPassword(QString p) { _password = p; }

    Q_INVOKABLE void getCheckpointModel();
//    Q_INVOKABLE void getStatesModel();
    Q_INVOKABLE void authWorker(int checkpoint, QString inn);

    CheckpointModel* getCheckpoint() { return modelCheckpoint; }

signals:
    void disconnected();
    void connected();
    void errorConnection(QString message);
    void comingCheckpointModel();
    void workerAuthoriazationResult(QString fio, QString position, QString lvl_access, QDate date, QTime time, QString state);

public slots:
    void connect();
    void disconnect();
    void send(COMMAND command);

    void slotReadyRead();
    void slotDisconnected();
    void slotConnected();
    void slotError(QAbstractSocket::SocketError);
};

#endif // CONNECTIONCONTROLLER_H
