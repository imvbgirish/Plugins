cmake_minimum_required(VERSION 3.16)

project(Plugin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_library(Plugin SHARED)   # This makes it usable by any app without linking it directly.

# qt_add_library(Plugin STATIC)      A static QML plugin must be linked directly into the application executable that uses it.
                                    # The QML engine can’t load .a files dynamically at runtime.

qt_add_qml_module(Plugin
    URI Plugin
    VERSION 1.0
    QML_FILES GirishControls.qml
    SOURCES girish.cpp girish.h
)

set_target_properties(Plugin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(Plugin
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Plugin
    PRIVATE Qt6::Quick)

target_include_directories(Plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

