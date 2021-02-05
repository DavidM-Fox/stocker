cmake_minimum_required(VERSION 3.0.0)
project(stocker VERSION 0.1.0)

include(CTest)
enable_testing()

# Read the following link! vcpkg working with VS Code
#https://gamefromscratch.com/vcpkg-cpp-easy-mode-step-by-step-tutorial/

include_directories(C:/dev/vcpkg/installed/x86-windows/include)
link_directories(C:/dev/vcpkg/installed/x86-windows/lib)

add_executable(stocker main.cpp)
target_link_libraries(stocker libcurl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
