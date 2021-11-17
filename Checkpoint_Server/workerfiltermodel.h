#ifndef WORKERFILTERMODEL_H
#define WORKERFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "workermodel.h"

class WorkerFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit WorkerFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        INN = 0,
        PIB,
        POSITION,
        LVL_ACCESS,
        VIEW
    };

    enum ViewMode {
        HIDE_DISMISSED = 0,
        SHOW_ALL,
        SHOW_ONLY_DISMISSED
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

#endif // WORKERFILTERMODEL_H
