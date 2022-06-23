#ifndef MODELFORPRINTCHECKPOINT_H
#define MODELFORPRINTCHECKPOINT_H

#include <QAbstractTableModel>
#include <QObject>

class ModelForPrintCheckpoint : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelForPrintCheckpoint(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const QString& title, const QString& qr_code);

    enum Column {
        TITLE = 0,
        QR_CODE,
        LAST
    };

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;
};

#endif // MODELFORPRINTCHECKPOINT_H
