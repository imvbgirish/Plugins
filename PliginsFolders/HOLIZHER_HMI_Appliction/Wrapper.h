#ifndef WRAPPER_H
#define WRAPPER_H

#include <QObject>
#include <QQmlEngine>
#include"AppsFilterModel.h"
#include"CategoryViewModel.h"

class Wrapper : public QObject
{
    Q_OBJECT
public:
    explicit Wrapper(QObject *parent = nullptr);

    CategoryViewModel *categoryViewModel() const;
    void setCategoryViewModel(CategoryViewModel *newCategoryViewModel);

    AppsFilterModel *appsFilterModel() const;
    void setAppsFilterModel(AppsFilterModel *newAppsFilterModel);

signals:
    void categoryViewModelChanged();

    void appsFilterModelChanged();

private:
    CategoryViewModel *m_categoryViewModel;
    AppsFilterModel *m_appsFilterModel;
    Q_PROPERTY(CategoryViewModel *categoryViewModel READ categoryViewModel WRITE setCategoryViewModel NOTIFY categoryViewModelChanged FINAL)
    Q_PROPERTY(AppsFilterModel *appsFilterModel READ appsFilterModel WRITE setAppsFilterModel NOTIFY appsFilterModelChanged FINAL)
};

#endif // WRAPPER_H
