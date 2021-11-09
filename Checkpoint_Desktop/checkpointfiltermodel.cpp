#include "checkpointfiltermodel.h"

CheckpointFilterModel::CheckpointFilterModel(QObject *parent)
{

}

void CheckpointFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
    invalidateFilter();
}

void CheckpointFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;

    if(!flag)
        invalidateFilter();
}

bool CheckpointFilterModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
{
    if (source_column != CheckpointModel::Column::ID && source_column != CheckpointModel::Column::FLAG)
        return true;
    else
        return false;
}

bool CheckpointFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(sourceModel()->index(source_row, CheckpointModel::Column::FLAG, source_parent).data().toInt() == 1)
        return false;

    bool flag = true;
    QVariant value;

    if(params[ TITLE ])
    {
        value = sourceModel()->index(source_row, CheckpointModel::Column::TITLE, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[TITLE].toString()))
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ LVL_ACCESS ])
    {
        value = sourceModel()->index(source_row, CheckpointModel::Column::LVL_ACCESS, source_parent).data(AccessModel::Role::Read);
        if(value.isValid())
        {
            if(value.toInt() == values[LVL_ACCESS].toInt())
                flag *= 1;
            else
                flag *= 0;
        }
    }

    return flag;
}
