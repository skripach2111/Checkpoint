#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent)
{
    nNextBlockSize = 0;
}

void ConnectionController::getCheckpointModel()
{
    send(CHECKPOINTS);
}

void ConnectionController::connect()
{
    tcpSocket = new QTcpSocket();
    nNextBlockSize = 0;

    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    QObject::connect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    QObject::connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
    QObject::connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));

    host = QHostAddress("127.0.0.1");
    port = 12012;

    checkpointModel = new CheckpointModel(this);
    checkpointComboBox->setSourceModel(checkpointModel);

    tcpSocket->connectToHost(host, port);
}

void ConnectionController::slotConnected()
{
    send(AUTH);
}

void ConnectionController::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                             "The host was not found." :
                             err == QAbstractSocket::RemoteHostClosedError ?
                                 "The remote host is closed." :
                                 err == QAbstractSocket::ConnectionRefusedError ?
                                     "The connection was refused." :
                                     QString(tcpSocket->errorString())
                                     );

    emit errorConnection(strError);
}

void ConnectionController::disconnect()
{
    tcpSocket->disconnectFromHost();
    emit disconnected();
}

void ConnectionController::slotDisconnected()
{
    disconnect();
}

void ConnectionController::send(COMMAND command)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out << (quint16)0 << command;

    switch(command)
    {
    case AUTH:
    {
        out << _login << _password;
        break;
    }
    case CHECKPOINTS:
    {
        break;
    }
    }

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

void ConnectionController::slotReadyRead()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_13);
    for (;;)
    {
        if (!nNextBlockSize)
        {
            if (tcpSocket->bytesAvailable() < sizeof(quint16))
            {
                break;
            }

            in >> nNextBlockSize;
        }

        if (tcpSocket->bytesAvailable() < nNextBlockSize)
        {
            break;
        }

        int COMMAND;

        in >> COMMAND;

        switch (COMMAND)
        {
        case AUTH_COMPLETE:
        {
            emit connected();

//            Notification *Notification = new class Notification();
//            Notification->setNotification(message);

//            if(!this->isVisible() || !this->isHidden() || !this->isActiveWindow())
//            {

//            }

            break;
        }
        case ERROR:
        {
            in >> lastError;
            emit errorConnection(lastError);
        }
        case CHECKPOINTS:
        {
            int count = 0;
            QVariant id;
            QVariant title;
            QVariant location;
            QVariant lvl_access;

            in >> count;

            for(int i = 0; i < count; i++)
            {
                in >> id;
                in >> title;
                in >> location;
                in >> lvl_access;


            }

            emit comingCheckpointModel();
            break;
        }
        default:
        {
            break;
        }
        }

        nNextBlockSize = 0;
    }
}
