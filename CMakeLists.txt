cmake_minimum_required(VERSION 3.0.0)
project(stocker VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(stocker main.cpp)
target_link_libraries(stocker curl)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
