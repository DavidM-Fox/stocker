cmake_minimum_required(VERSION 3.0.0)
project(stocker VERSION 0.1.0)

include(CTest)
include(CPack)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

enable_testing()

# Read the following link! vcpkg working with VS Code
# https://gamefromscratch.com/vcpkg-cpp-easy-mode-step-by-step-tutorial/

# From vcpkg

find_package(CURL CONFIG REQUIRED)
find_package(Qt5Widgets)

add_executable(stocker main.cpp)
target_link_libraries(stocker PRIVATE CURL::libcurl Qt5::Widgets)
