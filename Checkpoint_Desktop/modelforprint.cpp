#include "modelforprint.h"

ModelForPrint::ModelForPrint(QObject *parent) : QAbstractTableModel(parent)
{

}

int ModelForPrint::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int ModelForPrint::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant ModelForPrint::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch (role)
    {
    case Qt::DisplayRole:
    {
        return model[ index.row() ][ Column( index.column() ) ];
        break;
    }
    default:
    {
        return QVariant();
    }
    }
}

QVariant ModelForPrint::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case PHOTO:
        return "PHOTO";
    case PIB:
        return "PIB";
    case POSITION:
        return "POSITION";
    case LVL_ACCESS:
        return "LVL_ACCESS";
    case QR_CODE:
        return "QR_CODE";
    }

    return QVariant();
}

void ModelForPrint::appendRow(const QString &pib, const QString &position, const QString &lvl_access, const QByteArray &photo, const QByteArray &qr_code)
{
    DataHash record;
    record[ PIB ] = pib;
    record[ POSITION ] = position;
    record[ LVL_ACCESS ] = lvl_access;
    record[ PHOTO ] = photo;
    record[ QR_CODE ] = qr_code;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

Qt::ItemFlags ModelForPrint::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}
