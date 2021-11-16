#ifndef POSITIONFILTERMODEL_H
#define POSITIONFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "positionmodel.h"

class PositionFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit PositionFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        TITLE = 0,
    };

    void setFilterParam(FilterParam par, QVariant val);
    void setEnabledFilterParam(FilterParam par, bool flag);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QHash <FilterParam, bool> params;
    QHash <FilterParam, QVariant> values;
};

#endif // POSITIONFILTERMODEL_H
