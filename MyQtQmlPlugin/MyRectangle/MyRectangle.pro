# TEMPLATE = lib
# TARGET = MyRectangle
# QT += qml quick
# CONFIG += plugin c++11

# TARGET = $$qtLibraryTarget($$TARGET)
# uri = MyPlugin

# # Input
# SOURCES += \
#         myrectangle_plugin.cpp \
#         myitem.cpp

# HEADERS += \
#         myrectangle_plugin.h \
#         myitem.h

# DISTFILES = qmldir

# !equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#     copy_qmldir.target = $$OUT_PWD/qmldir
#     copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
#     copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
#     QMAKE_EXTRA_TARGETS += copy_qmldir
#     PRE_TARGETDEPS += $$copy_qmldir.target
# }

# qmldir.files = qmldir
# unix {
#     installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
#     qmldir.path = $$installPath
#     target.path = $$installPath
#     INSTALLS += target qmldir
# }


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

# --- CREATE FOLDER INSIDE BUILD DIR ---
DESTDIR = $$OUT_PWD/$$replace(uri, \., /)
QMAKE_POST_LINK += mkdir -p $$DESTDIR

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
