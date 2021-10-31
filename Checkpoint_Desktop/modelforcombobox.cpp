#include "modelforcombobox.h"

ModelForComboBox::ModelForComboBox(QObject *parent) : QAbstractTableModel(parent)
{
    startText = "-";
}

int ModelForComboBox::rowCount(const QModelIndex &parent) const
{
    return sourceModel->rowCount()+1;
}

int ModelForComboBox::columnCount(const QModelIndex &parent) const
{
    return sourceModel->columnCount();
}

QVariant ModelForComboBox::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() == 0)
    {
        if(role != Qt::DisplayRole)
            return QVariant();
        return startText;
    }

    return sourceModel->data(sourceModel->index(index.row()-1, index.column()), role);
}
