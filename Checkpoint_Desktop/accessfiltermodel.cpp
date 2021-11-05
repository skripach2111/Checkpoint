#include "accessfiltermodel.h"

AccessFilterModel::AccessFilterModel(QObject *parent)
{

}

void AccessFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
    invalidateFilter();
}

void AccessFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;

    if(!flag)
        invalidateFilter();
}

bool AccessFilterModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
{
    if (source_column != AccessModel::Column::ID && source_column != AccessModel::Column::FLAG)
        return true;
    else
        return false;
}

bool AccessFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool flag = true;
    QVariant value;

    if(params[ TITLE ])
    {
        value = sourceModel()->index(source_row, AccessModel::Column::TITLE, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[TITLE].toString()))
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ PRIVILEGE ])
    {
        value = sourceModel()->index(source_row, AccessModel::Column::PRIVILEGE, source_parent).data(AccessModel::Role::Read);
        if(value.isValid())
        {
            if(value.toInt() == values[PRIVILEGE].toInt())
                flag *= 1;
            else
                flag *= 0;
        }
    }

    return flag;
}
