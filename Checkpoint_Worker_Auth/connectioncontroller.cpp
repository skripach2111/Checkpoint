#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent)
{
    nNextBlockSize = 0;
    settings = new QSettings("settings.conf", QSettings::NativeFormat);
}

void ConnectionController::getCheckpointModel()
{
    send(CHECKPOINTS);
}

void ConnectionController::getStatesModel()
{
    send(STATES);
}

void ConnectionController::authWorker(int checkpoint, QString inn, int state)
{
    checkpointId = checkpoint;
    this->inn = inn;
    _state = state;
    qDebug() << "SEND AUTH WORKER##########################################################################";
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

    host = QHostAddress(getSettings("Connection/ip_address").toString());
    port = getSettings("Connection/port").toInt();

    if(host.toString().size() == 0)
        host = QHostAddress("127.0.0.1");

    if(port <= 0)
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

QVariant ConnectionController::getSettings(QString name)
{
    if(name == "Connection/ip_address")
        return settings->value(name, "127.0.0.1");
    else if(name == "Connection/port")
        return settings->value(name, 12012);

    return QVariant();
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
    case STATES:
    {
        break;
    }
    case AUTH_WORKER:
    {
        qDebug() << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << modelCheckpoint->data(modelCheckpoint->index(checkpointId, 0), CheckpointModel::Roles::ID);
        out << inn;
        out << modelCheckpoint->data(modelCheckpoint->index(checkpointId, 0), CheckpointModel::Roles::ID).toInt();
        out << modelState->data(modelState->index(_state, 0), StateModel::Roles::ID).toInt();
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
        qDebug() << "########################################################################## nNext: " << nNextBlockSize;
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

        int command;

        in >> command;

        qDebug() << command << ":command ##########################################################################";

        switch (command)
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
            break;
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
        case STATES:
        {
            qDebug() << "STATES ##########################################################################";
            modelState = new StateModel(this);
            qDebug() << "1 ##########################################################################";
            int count = 0;
            QVariant id;
            QVariant title;

            qDebug() << "2 ##########################################################################";

            in >> count;

            qDebug() << count << "count ##########################################################################";

            for(int i = 0; i < count; i++)
            {
                in >> id;
                in >> title;

                qDebug() << "READ ##########################################################################";
                qDebug() << id;
                qDebug() << title;

                modelState->appendRow(id.toInt(), title.toString());
            }

            qDebug() << "3 ##########################################################################";

            emit comingStateModel();
            break;
        }
        case AUTH_WORKER:
        {
            qDebug() << "AUTH_WORKER ##########################################################################";
            QVariant fio;
            QVariant position;
            QVariant lvl_access;
            QVariant date;
            QVariant time;
            QVariant state;
            QVariant color;

            in >> fio;
            in >> position;
            in >> lvl_access;
            in >> date;
            in >> time;
            in >> state;
            in >> color;

            qDebug() << "AUTH WORKER ##########################################################################";
            emit workerAuthoriazationResult(fio.toString(), position.toString(), lvl_access.toString(), date.toDate().toString(), time.toTime().toString(), state.toString(), color.toBool());

            break;
        }
        default:
        {
            qDebug() << "default ##########################################################################";
            qDebug() << in;
            break;
        }
        }

        if(in.atEnd())
            qDebug() << "IN end ###########################################################################";
        else
            qDebug() << "IN not end #######################################################################";
    }
}
