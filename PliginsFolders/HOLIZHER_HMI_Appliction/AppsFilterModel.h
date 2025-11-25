#ifndef APPSFILTERMODEL_H
#define APPSFILTERMODEL_H

#include <QSortFilterProxyModel>
#include"AppViewModel.h"
class AppsFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    AppsFilterModel();
    Q_INVOKABLE void setCategoryFilter(const QString &category);
private:
    AppViewModel *m_appViewModel;
};

#endif // APPSFILTERMODEL_H
