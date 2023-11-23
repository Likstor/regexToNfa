cmake_minimum_required(VERSION 3.28)

project(printFA CXX)

set(SOURCE_LIB printFA.cpp)
set(HEADERS printFA.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(printFA ${SOURCE_LIB} ${HEADERS})
target_include_directories(printFA PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})