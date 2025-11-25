#include "AppListModel.h"
#include "Wrapper.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    AppListModel* appModel = new AppListModel;

    QQmlApplicationEngine engine;
    Wrapper wrapper;


    // Expose wrapper to QML
    engine.rootContext()->setContextProperty("wrapper", &wrapper);
    engine.rootContext()->setContextProperty("appModel",appModel);
    // QCoreApplication::applicationDirPath() + "/../../Plugins_build/com/mycompany";
    // engine.addImportPath("/home/pthinks/shankra-cutting-machine-code/QmlPluginsApp/Plugins_build");
    engine.addImportPath(QCoreApplication::applicationDirPath() +"/../../Plugins_build");
    // engine.addImportPath("/home/shankar/QtTrsin/WhatsAppPlugin/bins");
    // engine.addImportPath("/home/shankar/QtTrsin/InstagramPlugin/bins");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
