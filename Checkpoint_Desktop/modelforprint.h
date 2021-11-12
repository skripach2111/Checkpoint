#ifndef MODELFORPRINT_H
#define MODELFORPRINT_H

#include <QAbstractTableModel>
#include <QObject>

class ModelForPrint : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelForPrint(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendRow( const QString& pib, const QString& position, const QString& lvl_access, const QByteArray& photo, const QByteArray& qr_code);

    enum Column {
        PIB = 0,
        POSITION,
        LVL_ACCESS,
        PHOTO,
        QR_CODE,
        LAST
    };

    typedef QHash< Column, QVariant > DataHash;
    typedef QList< DataHash > DataList;
    DataList model;
};

#endif // MODELFORPRINT_H
