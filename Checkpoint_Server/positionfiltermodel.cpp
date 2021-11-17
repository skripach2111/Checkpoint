#include "positionfiltermodel.h"

PositionFilterModel::PositionFilterModel(QObject *parent)
{

}

void PositionFilterModel::setFilterParam(FilterParam par, QVariant val)
{
    values[par] = val;
    invalidateFilter();
}

void PositionFilterModel::setEnabledFilterParam(FilterParam par, bool flag)
{
    params[par] = flag;

    if(!flag)
        invalidateFilter();
}

bool PositionFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(sourceModel()->index(source_row, PositionModel::Column::FLAG, source_parent).data().toInt() == 1)
        return false;

    bool flag = true;
    QVariant value;

    if(params[ TITLE ])
    {
        value = sourceModel()->index(source_row, PositionModel::Column::TITLE, source_parent).data();
        if(value.isValid())
        {
            if(value.toString().contains(values[TITLE].toString()))
                flag *= 1;
            else
                flag *= 0;
        }
    }

    return flag;
}
