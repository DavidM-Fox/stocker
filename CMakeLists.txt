cmake_minimum_required(VERSION 3.5)

project(stocker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
set(Qt5_DIR "C:\\Qt\\5.15.2\\msvc2019\\lib\\cmake\\Qt5")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Charts REQUIRED)
find_package(CURL CONFIG REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        include/stockerAPI.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(stocker
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(stocker SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(stocker
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(stocker PRIVATE CURL::libcurl Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts )
