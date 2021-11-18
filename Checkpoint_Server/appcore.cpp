#include "appcore.h"

AppCore::AppCore(QObject *parent)
{
    db = new DatabaseModule(this);

    settings = new QSettings("settings.conf", QSettings::NativeFormat);
    db->setHostAddress(settings->value("Connection/ip_address", "213.110.121.129").toString());
    db->setHostPort(settings->value("Connection/port", 3306).toInt());
    db->setDbName(settings->value("Connection/db_name", "checkpoints").toString());

//    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
//    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
//            host.ip = address;
//    }

    host.ip = QHostAddress("127.0.0.1");
    host.port = 12012;
    nNextBlockSize = 0;
}

void AppCore::slotStart()
{
    pServer = new QTcpServer(this);

    if (!pServer->listen(host.ip, host.port)) {
        pServer->close();
        emit startServerError("Unable to start server!");
        qDebug() << "Unable to start server!";
        qDebug() << host.ip;
        return;
    }

    if(!db->connect("userCheckpoint", "user_checkpoint"))
    {
        qDebug() << "Не удалось подключиться к серверу!";
        return;
    }

    emit startServerSuccessful();

    qDebug() << "Start server successful!";
    qDebug() << "Server ip: " << host.ip;

    connect(pServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
}

void AppCore::slotNewConnection()
{
    qDebug() << "New connection";

    if(!client.statusConnection)
    {
        client.pSocket = pServer->nextPendingConnection();
        client.statusConnection = true;

        connect(client.pSocket, SIGNAL(disconnected()), this, SLOT(slotClientDisconnected()));
        connect(client.pSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

        emit clientConnected();
    }
}

void AppCore::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_13);

    for (;;) {
        if (!nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }

            in >> nNextBlockSize;
        }

        if (pClientSocket->bytesAvailable() < nNextBlockSize) {
            break;
        }

        COMMAND command;
        in >> command;

        switch (command)
        {
        case AUTH:
        {
            qDebug() << "AUTH";
            QString login;
            QString password;

            in >> login;
            in >> password;

            QString error = db->authorizationUser(login, password);

            if(!error.isEmpty())
            {
                lastError = error;
                doSendToClientsMessage(ERROR);
                nNextBlockSize = 0;
                slotClientDisconnected();
                return;
            }

            switch (db->getPrivileges()) {
            case Privileges::VAHTA:
            {
                qDebug() << "AUTH_COMPLETE";
                doSendToClientsMessage(AUTH_COMPLETE);
                break;
            }
            default:
            {
                qDebug() << "ERROR";
                lastError = "Вы не можете использовать это приложение!";
                doSendToClientsMessage(ERROR);
                nNextBlockSize = 0;
                slotClientDisconnected();
                return;
            }
            }

            break;
        }
        case CHECKPOINTS:
        {
            qDebug() << "CHECKPOINTS";
            doSendToClientsMessage(CHECKPOINTS);
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

void AppCore::slotStop()
{
    //client.pSocket->disconnect();
    client.statusConnection = false;

    pServer->disconnect();
}

void AppCore::slotClientDisconnected()
{
    qDebug() << "client disconect";
    client.statusConnection = false;
    client.pSocket->disconnect();
    client.pSocket->close();
}

void AppCore::doSendToClientsMessage(COMMAND command)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_13);
    out << (quint16)0 << command;

    switch (command) {
    case ERROR:
    {
        out << lastError;
        break;
    }
    case AUTH_COMPLETE:{
        break;
    }
    case CHECKPOINTS:
    {
        db->getCheckpointModel()->select();
        modelCheckpoint = db->getCheckpointModel();
        out << modelCheckpoint->rowCount(QModelIndex());

        for(int i = 0; i < modelCheckpoint->rowCount(QModelIndex()); i++)
        {
            out << modelCheckpoint->index(i, CheckpointModel::Column::ID).data();
            out << modelCheckpoint->index(i, CheckpointModel::Column::TITLE).data();
            out << modelCheckpoint->index(i, CheckpointModel::Column::LOCATION).data();
            out << modelCheckpoint->index(i, CheckpointModel::Column::LVL_ACCESS).data(CheckpointModel::Role::Read);
        }

        break;
    }
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    out.device()->seek(arrBlock.size()-1);

    client.pSocket->write(arrBlock);
}
