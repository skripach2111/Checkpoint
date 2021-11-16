#ifndef ACCESSFILTERMODEL_H
#define ACCESSFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "accessmodel.h"

class AccessFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit AccessFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        TITLE = 0,
        PRIVILEGE
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

#endif // ACCESSFILTERMODEL_H
