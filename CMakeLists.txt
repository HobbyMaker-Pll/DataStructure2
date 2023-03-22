cmake_minimum_required(VERSION 3.0.0)
project(DataStructure VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DataStructure main.c Ex01.c Ex02.c Ex03.c Ex04.c Ex05.c Ex06.c Ex07.c Ex08.c Ex09.c Ex10_11.c)
set_property(TARGET DataStructure PROPERTY C_STANDARD 99)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
