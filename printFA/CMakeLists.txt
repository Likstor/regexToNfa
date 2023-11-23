cmake_minimum_required(VERSION 3.28)

project(printFA)

set(SOURCE_LIB printFA.cpp)

add_library(printFA STATIC ${SOURCE_LIB})