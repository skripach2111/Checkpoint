#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent)
{
    nNextBlockSize = 0;
}

void ConnectionController::getCheckpointModel()
{
    send(CHECKPOINTS);
}

void ConnectionController::authWorker(int checkpoint, QString inn)
{
    checkpointId = checkpoint;
    this->inn = inn;
    send(AUTH_WORKER);
}

void ConnectionController::connect()
{
    tcpSocket = new QTcpSocket();
    nNextBlockSize = 0;

    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    QObject::connect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    QObject::connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
    QObject::connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));

    host = QHostAddress("192.168.0.101");
    port = 12012;

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
    case AUTH_WORKER:
    {
        qDebug() << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << modelCheckpoint->data(modelCheckpoint->index(checkpointId, 0), CheckpointModel::Roles::ID);
        out << inn;
        out << modelCheckpoint->data(modelCheckpoint->index(checkpointId, 0), CheckpointModel::Roles::ID);
        break;
    }
    }

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
}

void ConnectionController::slotReadyRead()
{
    qDebug() << "slotReadyRead ##########################################################################";

    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_13);

    if (nNextBlockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < sizeof(quint16))
        {
            return;
        }

        in >> nNextBlockSize;
    }

    if (tcpSocket->bytesAvailable() < nNextBlockSize)
    {
        qDebug() << "break ##########################################################################";
        return;
    }
    else
    {
        qDebug() << "########################################################################## nNext: " << nNextBlockSize;

        nNextBlockSize = 0;

        int COMMAND;

        in >> COMMAND;
        qDebug() << COMMAND << ":command ##########################################################################";

        switch (COMMAND)
        {
        case AUTH_COMPLETE:
        {
            qDebug() << "AUTH_COMPLETE ##########################################################################";
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
            qDebug() << "ERROR ##########################################################################";
            in >> lastError;
            emit errorConnection(lastError);
        }
        case CHECKPOINTS:
        {
            qDebug() << "CHECKPOINTS ##########################################################################";
            modelCheckpoint = new CheckpointModel(this);

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

                modelCheckpoint->appendRow(id.toInt(), title.toString(), location.toString(), lvl_access.toString());
            }

            emit comingCheckpointModel();
            break;
        }
        case AUTH_WORKER:
        {
            qDebug() << "AUTH_WORKER ##########################################################################";
            QString fio;
            QString position;
            QString lvl_access;
            QString date;
            QString time;
            QString state;

            in >> fio;
            in >> position;
            in >> lvl_access;
            in >> date;
            in >> time;
            in >> state;

            qDebug() << "AUTH WORKER ##########################################################################";
            emit workerAuthoriazationResult(fio, position, lvl_access, QDate::fromString(date), QTime::fromString(time), state);

            break;
        }
        default:
        {
            qDebug() << "default ##########################################################################";
            qDebug() << in;
            break;
        }
        }
    }
}
