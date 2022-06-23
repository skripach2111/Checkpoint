#include "modelforprintcheckpoint.h"

ModelForPrintCheckpoint::ModelForPrintCheckpoint(QObject *parent) : QAbstractTableModel(parent)
{

}

int ModelForPrintCheckpoint::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return model.count();
}

int ModelForPrintCheckpoint::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return LAST;
}

QVariant ModelForPrintCheckpoint::data(const QModelIndex &index, int role) const
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

QVariant ModelForPrintCheckpoint::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case TITLE:
        return "TITLE";
    case QR_CODE:
        return "QR_CODE";
    }

    return QVariant();
}

void ModelForPrintCheckpoint::appendRow(const QString &title, const QString &qr_code)
{
    DataHash record;
    record[ TITLE ] = title;
    record[ QR_CODE ] = qr_code;

    int row = model.count();
    beginInsertRows( QModelIndex(), row, row );
    model.append( record );
    endInsertRows();
}

Qt::ItemFlags ModelForPrintCheckpoint::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );


    return flags;
}
