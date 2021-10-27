#ifndef AUTHORIZATIONFILTERMODEL_H
#define AUTHORIZATIONFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "workermodel.h"
#include "authorizationmodel.h"

class AuthorizationFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit AuthorizationFilterModel(QObject *parent = nullptr);

    enum FilterParam {
        WORKER = 0,
        AUTHORIZER,
        DATE,
        TIME,
        CHECKPOINT,
        LVL_ACCESS,
        STATE_IN,
        STATE_OUT,
        STATE_NOT_ALLOWED
    };

    void setFilterParam(FilterParam par, QVariant val);
    void setEnabledFilterParam(FilterParam par, bool flag);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QHash <FilterParam, bool> params;
    QHash <FilterParam, QVariant> values;
};

#endif // AUTHORIZATIONFILTERMODEL_H
