cmake_minimum_required(VERSION 3.0.0)

project(stocker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt5_DIR "C:\\Qt\\5.15.2\\msvc2019\\lib\\cmake\\Qt5")
set(Qt5Charts_DIR "C:\\Qt\\5.15.2\\msvc2019\\lib\\cmake\\Qt5Charts\\")
find_package(Qt5 COMPONENTS Core Gui Widgets Charts REQUIRED)
find_package(CURL CONFIG REQUIRED)

set(PROJ_INC "inc")
set(PROJ_SRC "src")

include_directories(${PROJ_INC})

set(PROJECT_SOURCES
        ${PROJ_SRC}/main.cpp
        ${PROJ_SRC}/mainwindow.cpp
        ${PROJ_SRC}/avapi.cpp
        ${PROJ_SRC}/QCandlestickChart.cpp

        ${PROJ_INC}/mainwindow_ui.h
        ${PROJ_INC}/mainwindow.h
        ${PROJ_INC}/rapidcsv.h
        ${PROJ_INC}/avapi.h
        ${PROJ_INC}/QCandlestickChart.h
)


add_executable(stocker ${PROJECT_SOURCES})
target_link_libraries(stocker PRIVATE CURL::libcurl Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)