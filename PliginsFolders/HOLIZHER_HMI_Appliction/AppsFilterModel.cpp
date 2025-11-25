#include "AppsFilterModel.h"
#include<QDebug>
AppsFilterModel::AppsFilterModel() {

    m_appViewModel=new AppViewModel();
    setSourceModel(m_appViewModel);
    setFilterRole(AppViewModel::Category);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void AppsFilterModel::setCategoryFilter(const QString &category)
{
    qDebug()<<Q_FUNC_INFO<<"text ;"<<category;
    setFilterFixedString(category);

}

