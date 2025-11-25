#include "Wrapper.h"
#include "AppListModel.h"

Wrapper::Wrapper(QObject *parent)
    : QObject{parent}
{
    m_appModel = new AppListModel();
    m_categoriesModel = new CategoriesModel(this);

    m_filterModel = new QSortFilterProxyModel(this);
    m_filterModel->setSourceModel(m_appModel);
    m_filterModel->setFilterRole(AppListModel::Category);
    m_filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

bool Wrapper::loadFromJson(const QString &path)
{
    // qDebug() << "Loading apps from JSON:" << path;

    // JsonParser parser("/home/shankar/QmlPlugins");
    // if (!parser.parseFolders()) {
    //     qWarning() << "Failed to parse folders in" << path;
    //     return false;
    // }

    // QList<App*> appList = parser.getAppDataList();
    // m_appModel->setAppsData(appList);

    // // Debug print
    // for (const auto &app : appList) {
    //     qDebug() << "App Name:" << app->appName()
    //              << "Icon:" << app->icon()
    //              << "Category:" << app->categories();
    // }

    // // Build category list for CategoriesModel
    // QSet<QString> cats;
    // for (const auto &app : appList) {
    //     cats.insert(app->categories());
    // }
    // m_categoriesModel->setCategories(QStringList(cats.begin(), cats.end()));

    // return !appList.isEmpty();
    return false;
}

void Wrapper::setCategoryFilter(const QString &category)
{
    m_filterModel->setFilterFixedString(category);
}

AppListModel *Wrapper::appModel() const
{
    return m_appModel;
}

CategoriesModel *Wrapper::categoriesModel() const
{
    return m_categoriesModel;
}

QSortFilterProxyModel *Wrapper::filteredAppModel() const
{
    return m_filterModel;
}
