#include "workerfiltermodel.h"
#include <QDebug>
WorkerFilterModel::WorkerFilterModel(QObject *parent)
{

}

void WorkerFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
}

void WorkerFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;
}

bool WorkerFilterModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
{
    if(source_column != WorkerModel::Column::PHOTO && source_column != WorkerModel::Column::FLAG)
        return true;
    else
        return false;
}

bool WorkerFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool flag = true;
    QVariant value;

    if(params[ INN ])
    {
        value = sourceModel()->index(source_row, WorkerModel::Column::INN, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[INN].toString()) != -1)
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ PIB ])
    {
        value = sourceModel()->index(source_row, WorkerModel::Column::PIB, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[PIB].toString()) != -1)
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ POSITION ])
    {
        value = sourceModel()->index(source_row, WorkerModel::Column::POSITION, source_parent).data();
        if(value.isValid())
        {
            if(value.toInt() == values[POSITION].toInt())
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ LVL_ACCESS ])
    {
        value = sourceModel()->index(source_row, WorkerModel::Column::LVL_ACCESS, source_parent).data();
        if(value.isValid())
        {
            if(value.toInt() == values[LVL_ACCESS].toInt())
                flag *= 1;
            else
                flag *= 0;
        }
    }

    if(params[ VIEW ])
    {
        value = sourceModel()->index(source_row, WorkerModel::Column::FLAG, source_parent).data();
        if(value.isValid())
        {
            switch((ViewMode)value.toInt())
            {
            case HIDE_DISMISSED:
            {
                if(value.toInt() == 0)
                    flag *= 1;
                else
                    flag *= 0;
                break;
            }
            case SHOW_ALL:
            {
                break;
            }
            case SHOW_ONLY_DISMISSED:
            {
                if(value.toInt() == 1)
                    flag *= 1;
                else
                    flag *= 0;
                break;
            }
            }
        }
    }

    return flag;
}
