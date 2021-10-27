#include "accountfiltermodel.h"

AccountFilterModel::AccountFilterModel(QObject *parent)
{

}

void AccountFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
}

void AccountFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;
}

bool AccountFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool flag = true;
    QVariant value;

    if(params[ LOGIN ])
    {
        value = sourceModel()->index(source_row, AccountModel::Column::LOGIN, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[LOGIN].toString()) != -1)
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ WORKER ])
    {
        value = sourceModel()->index(source_row, AccountModel::Column::WORKER, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[WORKER].toString()) != -1)
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ PRIVILEGE ])
    {
        value = sourceModel()->index(source_row, AccountModel::Column::PRIVILEGE, source_parent).data();
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