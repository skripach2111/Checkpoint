#ifndef STATEMODEL_H
#define STATEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>

class StateModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit StateModel(QObject *parent = nullptr);
    StateModel(const StateModel &modelNew);

    int columnCount( const QModelIndex& parent ) const;
    virtual int rowCount( const QModelIndex& parent ) const;
    virtual QVariant data( const QModelIndex& index, int role ) const;
    virtual QHash<int, QByteArray> roleNames() const;

    void appendRow( const int& id, const QString& title);

    enum Roles {
        ID = Qt::UserRole + 1,
        TITLE,
        LAST = 2
    };

private:

    typedef QHash< int, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;
};

#endif // STATEMODEL_H
