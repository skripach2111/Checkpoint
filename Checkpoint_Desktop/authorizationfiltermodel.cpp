#include "authorizationfiltermodel.h"



AuthorizationFilterModel::AuthorizationFilterModel(QObject *parent)
{

}

void AuthorizationFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
}

void AuthorizationFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;
}

bool AuthorizationFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool flag = true;
    QVariant value;

    if(params[ WORKER ])
    {
        value = sourceModel()->index(source_row, AuthorizationModel::Column::WORKER, source_parent).data(Qt::DisplayRole);
        if(value.isValid())
        {
            if(value.toString().contains(values[WORKER].toString()) != -1)
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
            if(value.toString().contains(values[WORKER].toString()) != -1)
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
        value = sourceModel()->index(source_row, AuthorizationModel::Column::CHECKPOINT, source_parent).data();
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
        value = sourceModel()->index(source_row, AuthorizationModel::Column::WORKER, source_parent).data();
        value = ((AuthorizationModel*)sourceModel())->getDataWorker(value.toInt(), WorkerModel::Column::LVL_ACCESS);
        if(value.isValid())
        {
            if(value == values[LVL_ACCESS])
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ STATE_IN ] || params[ STATE_OUT ] || params[ STATE_NOT_ALLOWED ])
    {
        if(params[ STATE_IN ])
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data();
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_IN])
                    flag += 1;
            }
        }

        if(params[ STATE_OUT ])
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data();
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_OUT])
                    flag += 1;
            }
        }

        if(params[ STATE_NOT_ALLOWED ])
        {
            value = sourceModel()->index(source_row, AuthorizationModel::Column::STATE, source_parent).data();
            if(value.isValid())
            {
                if(value.toInt() == values[STATE_NOT_ALLOWED])
                    flag += 1;
            }
        }
    }
    else
        flag *= 0;

    return flag;
}
