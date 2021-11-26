#include "authorizationfiltermodel.h"



AuthorizationFilterModel::AuthorizationFilterModel(QObject *parent)
{

}

void AuthorizationFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
    invalidateFilter();
}

void AuthorizationFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;

    if(!flag)
        invalidateFilter();
}

bool AuthorizationFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool flag = false;
    QVariant value;

        if(params[ STATE_IN ] && !flag)
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data(AuthorizationModel::Role::Read);
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_IN].toInt())
                    flag = true;
            }
        }

         if(params[ STATE_OUT ] && !flag)
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data(AuthorizationModel::Role::Read);
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_OUT].toInt())
                    flag = true;
            }
        }

         if(params[ STATE_NOT_ALLOWED ] && !flag)
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data(AuthorizationModel::Role::Read);
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_NOT_ALLOWED].toInt())
                    flag = true;
            }
        }


    if(params[ WORKER ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::WORKER, source_parent).data(Qt::DisplayRole);
        if(value.isValid())
        {
            if(value.toString().contains(values[WORKER].toString()))
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ AUTHORIZER ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::WORKER, source_parent).data(Qt::DisplayRole);
        if(value.isValid())
        {
            if(value.toString().contains(values[WORKER].toString()))
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ DATE ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::DATE, source_parent).data();
        if(value.isValid())
        {
            if(value == values[DATE])
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ TIME ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::TIME, source_parent).data();
        if(value.isValid())
        {
            if(value == values[TIME])
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ CHECKPOINT ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::CHECKPOINT, source_parent).data(AuthorizationModel::Role::Read);
        if(value.isValid())
        {
            if(value.toInt() == values[CHECKPOINT])
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ LVL_ACCESS ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::WORKER, source_parent).data(AuthorizationModel::Role::Read);
        value = ((AuthorizationModel*)sourceModel())->getDataWorker(value.toString(), WorkerModel::Column::LVL_ACCESS);
        if(value.isValid())
        {
            if(value == values[LVL_ACCESS])
                flag *= 1;
            else
                flag *= 0;
        }
    }

    return flag;
}
