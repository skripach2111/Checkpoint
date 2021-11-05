#ifndef ACCOUNTFILTERMODEL_H
#define ACCOUNTFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "accountmodel.h"

class AccountFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit AccountFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        LOGIN = 0,
        WORKER,
        PRIVILEGE
    };

    void setFilterParam(FilterParam par, QVariant val);
    void setEnabledFilterParam(FilterParam par, bool flag);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;


private:
    QHash <FilterParam, bool> params;
    QHash <FilterParam, QVariant> values;
};

#endif // ACCOUNTFILTERMODEL_H
