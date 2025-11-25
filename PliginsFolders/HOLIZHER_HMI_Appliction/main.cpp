#include <QGuiApplication>
#include <QQmlApplicationEngine>
// #include"CategoryDataModel.h"
// #include "AppDataModel.h"
#include"Wrapper.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    // CategoryDataModel c;
    // AppDataModel ac;
    QQmlApplicationEngine engine;
    qmlRegisterType<Wrapper>("com.example.wrapper", 1, 0, "Wrapper");
    engine.addImportPath("/home/pthinks/Desktop/ranganatha-workspace/HOLIZHER/HOLIZHER_HMI_Appliction/Apps_plugin_builds");
    // engine.addImportPath("/home/pthinks/Desktop/ranganatha-workspace/HOLIZHER/HOLIZHER_HMI_Appliction/Apps_Plugins/contactsP");
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
