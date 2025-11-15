cmake_minimum_required(VERSION 3.16)

project(CPP_Plugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(CPP_Plugin SHARED
  CPP_Plugin_global.h
  cpp_plugin.cpp
  cpp_plugin.h
)

target_link_libraries(CPP_Plugin PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(CPP_Plugin PRIVATE CPP_PLUGIN_LIBRARY)
