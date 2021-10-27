#ifndef CHECKPOINTFILTERMODEL_H
#define CHECKPOINTFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "checkpointmodel.h"

class CheckpointFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CheckpointFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        TITLE = 0,
        LVL_ACCESS,
    };

    void setFilterParam(FilterParam par, QVariant val);
    void setEnabledFilterParam(FilterParam par, bool flag);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QHash <FilterParam, bool> params;
    QHash <FilterParam, QVariant> values;
};

#endif // CHECKPOINTFILTERMODEL_H
