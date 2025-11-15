TEMPLATE = lib
TARGET = Plugin2
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mycompany.settings

# Convert URI into folder path
uriPath = $$replace(uri, \., /)

# Put .so in com/mycompany/settings/
# DESTDIR = $$PWD/$$uriPath

DESTDIR = $$PWD/../../PluginsURI/$$uriPath


# Input
SOURCES += \
        plugin2_plugin.cpp \
        settings.cpp

HEADERS += \
        plugin2_plugin.h \
        settings.h

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
