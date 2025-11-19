
TEMPLATE = lib
TARGET = MyRectangle
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = MyPlugin

SOURCES += \
        myrectangle_plugin.cpp \
        myitem.cpp

HEADERS += \
        myrectangle_plugin.h \
        myitem.h

DISTFILES = qmldir

DESTDIR = $$PWD/bins/MyPlugin
# --- COPY QMLDIR Automatically ---
copy_qmldir.commands = $(COPY_FILE) "$$PWD/qmldir" "$$DESTDIR/qmldir"
QMAKE_EXTRA_TARGETS += copy_qmldir
POST_TARGETDEPS += copy_qmldir

# --- SYSTEM INSTALL OPTION (only for make install) ---
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

RESOURCES += \
    qml.qrc
