cmake_minimum_required(VERSION 3.0.0)
project(td2 VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 20)

add_executable(td2 main.cpp)
add_subdirectory(exo1)
add_subdirectory(exo2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
