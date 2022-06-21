#include "appcore.h"

AppCore::AppCore(QObject *parent)
{
    db = new DatabaseModule(this);

    settings = new QSettings("settings.conf", QSettings::NativeFormat);
    db->setHostAddress(settings->value("Connection/ip_address", "213.110.121.129").toString());
    db->setHostPort(settings->value("Connection/port", 3306).toInt());
    db->setDbName(settings->value("Connection/db_name", "checkpoints").toString());

        const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
        for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
                host.ip = address;
        }

//    host.ip = QHostAddress("127.0.0.1");
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
    qDebug() << "readClient";
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
        case STATES:
        {
            qDebug() << "STATES";
            doSendToClientsMessage(STATES);
            break;
        }
        case AUTH_WORKER:
        {
            qDebug() << "AUTH_WORKER";

            in >> inn;
            in >> checkpoint;
            in >> _state;

            qDebug() << "DO SEND AUTH WORKER";

            doSendToClientsMessage(COMMAND::AUTH_WORKER);
            break;
        }
        default:
        {
            break;
        }
        }

        if(in.atEnd())
            qDebug() << "IN end";
        else
            qDebug() << "IN not end";

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
    out << (quint16)0;
    out << command;

    qDebug() << command << ":COMMAND";

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

        int count = 0;

        out << (int)0;

        for(int i = 0; i < modelCheckpoint->rowCount(QModelIndex()); i++)
        {
            if(modelCheckpoint->index(i, CheckpointModel::Column::FLAG).data().toInt() != 1)
            {
                count++;
                out << modelCheckpoint->index(i, CheckpointModel::Column::ID).data();
                out << modelCheckpoint->index(i, CheckpointModel::Column::TITLE).data();
                out << modelCheckpoint->index(i, CheckpointModel::Column::LOCATION).data();
                out << modelCheckpoint->index(i, CheckpointModel::Column::LVL_ACCESS).data(CheckpointModel::Role::Read);

                qDebug() << modelCheckpoint->index(i, CheckpointModel::Column::ID).data() << modelCheckpoint->index(i, CheckpointModel::Column::TITLE).data() << modelCheckpoint->index(i, CheckpointModel::Column::LOCATION).data() << modelCheckpoint->index(i, CheckpointModel::Column::LVL_ACCESS).data(CheckpointModel::Role::Read);
            }
        }

        out.device()->seek(sizeof (quint16) + sizeof (command));
        out << count;

        break;
    }
    case STATES:
    {
        modelState = db->getStateModel();
        modelState->select();

        int count = 0;

        out << (int)0;

        for(int i = 0; i < modelState->rowCount(QModelIndex())-1; i++)
        {
            if(modelState->index(i, StateModel::Column::FLAG).data().toInt() != 1)
            {
                count++;
                out << modelState->index(i, StateModel::Column::ID).data();
                out << modelState->index(i, StateModel::Column::TITLE).data();
            }
        }

        out.device()->seek(sizeof (quint16) + sizeof (command));
        out << count;

        break;
    }
    case AUTH_WORKER:
    {
        qDebug() << "AUTH WORKER";
        db->selectTables();

        QVariant fio;
        QVariant position;
        QVariant lvl_acces;
        QVariant dateAuth;
        QVariant timeAuth;
        QVariant state;
        QVariant color;

        qDebug() << "1";
        qDebug() << "inn: " << inn;
        qDebug() << "checkpoint: " << checkpoint;

        fio = db->getWorkerModel()->getDataById(inn, WorkerModel::Column::PIB);
        qDebug() << "fio" << fio;
        position = db->getPositionModel()->getDataById(db->getWorkerModel()->getDataById(inn, WorkerModel::Column::POSITION).toInt(), PositionModel::Column::TITLE);
        qDebug() << "position" << position;
        lvl_acces = db->getAccessModel()->getDataById(db->getWorkerModel()->getDataById(inn, WorkerModel::Column::LVL_ACCESS).toInt(), AccessModel::Column::TITLE);
        qDebug() << "lvl_access" << lvl_acces;
        dateAuth = QDate::currentDate();
        qDebug() << "dateAuth" << dateAuth;
        timeAuth = QTime::currentTime();
        qDebug() << "timeAuth" << timeAuth;

        qDebug() << "2";

        if(db->getAccessModel()->getDataById(db->getCheckpointModel()->getDataById(checkpoint, CheckpointModel::Column::LVL_ACCESS).toInt(), AccessModel::Column::PRIVILEGE).toInt() >=
                db->getAccessModel()->getDataById(db->getWorkerModel()->getDataById(inn, WorkerModel::Column::LVL_ACCESS).toInt(), AccessModel::Column::PRIVILEGE).toInt())
        {
            state = "Допущен";
            color = true;
            out << fio;
            out << position;
            out << lvl_acces;
            out << dateAuth;
            out << timeAuth;
            out << state;
            out << color;
            qDebug() << "OUT";

            db->getAuthorizationModel()->appendRow(inn, dateAuth.toDate(), timeAuth.toTime(), _state, db->getWorkerModel()->getDataById(db->getAccountModel()->index(db->getAccountModel()->getUserByLogin(login).row(), AccountModel::Column::WORKER).data(AccountModel::Role::Read).toString(), WorkerModel::Column::INN).toString(), checkpoint);
        }
        else
        {
            state = "Недопущен";
            color = false;
            out << fio;
            out << position;
            out << lvl_acces;
            out << dateAuth;
            out << timeAuth;
            out << state;
            out << color;
            qDebug() << "OUT";
            db->getAuthorizationModel()->appendRow(inn, dateAuth.toDate(), timeAuth.toTime(), 3, db->getWorkerModel()->data(db->getAccountModel()->getUserByLogin(login), Qt::DisplayRole).toString(), checkpoint);
        }

        qDebug() << "3";

        db->getAuthorizationModel()->saveChanges();

        qDebug() << "break";

        break;
    }
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    qDebug() << "size: " << arrBlock.size();
    qDebug() << "uint16 size: " << quint16(arrBlock.size() - sizeof(quint16));

    client.pSocket->write(arrBlock);
}