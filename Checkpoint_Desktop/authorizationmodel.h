#ifndef AUTHORIZATIONMODEL_H
#define AUTHORIZATIONMODEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractTableModel>
#include <QObject>
#include <QDate>

#include "workermodel.h"
#include "statemodel.h"
#include "checkpointmodel.h"

class AuthorizationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AuthorizationModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const int& worker, const QDate& date, const QTime& time, const int& state, const int& authorizer, const int& checkpoint );

    bool select();
    bool submit();
    void setTable(QString t, QSqlDatabase *database);

    void setWorkerModel(WorkerModel *m_worker) { workerModel = m_worker; }
    void setStateModel(StateModel *m_state) { stateModel = m_state; }
    void setCheckpointModel(CheckpointModel *m_checkpoint) { checkpointModel = m_checkpoint; }

    enum Column {
        WORKER = 0,
        DATE,
        TIME,
        STATE,
        AUTHORIZER,
        CHECKPOINT,
        LAST,
        STATE_ROW
    };

    enum Role {
        Display = 0x1,
        Read
    };

    enum StatesRows {
        NOT_EDITED = 0x1,
        ADDED,
        EDITED,
        DELETED
    };

    QVariant getDataWorker(QString inn, WorkerModel::Column column);

private:

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;

    QSqlDatabase *db;
    QSqlQuery query;

    QString table;

    WorkerModel *workerModel;
    StateModel *stateModel;
    CheckpointModel *checkpointModel;
};

#endif // AUTHORIZATIONMODEL_H
