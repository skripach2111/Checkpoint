#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <QObject>
#include <QQuickItem>
#include <QtNetwork>

class ConnectionController : public QQuickItem
{
    Q_OBJECT

    QTcpSocket *tcpSocket;
    quint16 nNextBlockSize;
    QHostAddress host;
    short unsigned int port;

    Q_PROPERTY(QString login MEMBER _login WRITE setLogin);
    Q_PROPERTY(QString password MEMBER _password WRITE setPassword);

    QString _login;
    QString _password;

    QString lastError;

public:
    explicit ConnectionController(QObject *parent = 0);

    enum COMMAND {
        PING = 1,
        MESSAGE,
        AUTH,
        LISTEN,
        WORKER,
        ACCOUNT,
        ERROR,
        AUTH_COMPLETE
    };

    void setLogin(QString l) { _login = l; }
    void setPassword(QString p) { _password = p; }

signals:
    void disconnected();
    void connected();
    void errorConnection(QString message);

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
