#include "Wrapper.h"

Wrapper::Wrapper(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;

    m_categoryViewModel =new CategoryViewModel(this);
    m_appsFilterModel = new AppsFilterModel();
}

CategoryViewModel *Wrapper::categoryViewModel() const
{
    return m_categoryViewModel;
}

void Wrapper::setCategoryViewModel(CategoryViewModel *newCategoryViewModel)
{
    if (m_categoryViewModel == newCategoryViewModel)
        return;
    m_categoryViewModel = newCategoryViewModel;
    emit categoryViewModelChanged();
}

AppsFilterModel *Wrapper::appsFilterModel() const
{
    return m_appsFilterModel;
}

void Wrapper::setAppsFilterModel(AppsFilterModel *newAppsFilterModel)
{
    if (m_appsFilterModel == newAppsFilterModel)
        return;
    m_appsFilterModel = newAppsFilterModel;
    emit appsFilterModelChanged();
}
