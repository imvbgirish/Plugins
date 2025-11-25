TEMPLATE = lib
TARGET = ChromePlugin
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mycompany.qmlcomponents
DESTDIR = $$PWD/../../Plugins_build/com/mycompany/chrome
# Input
SOURCES += \
        Chrome.cpp \
        ChromePlugin_plugin.cpp \
        MyItem.cpp

HEADERS += \
        Chrome.h \
        ChromePlugin_plugin.h \
        MyItem.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

RESOURCES += \
    Chrome.qrc \
    ChromeItem.qrc
