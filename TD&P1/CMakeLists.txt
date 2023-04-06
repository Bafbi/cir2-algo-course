cmake_minimum_required(VERSION 3.0.0)
project(td1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(td1 main.cpp)
add_subdirectory(exo1)
add_subdirectory(exo2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
