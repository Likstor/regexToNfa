cmake_minimum_required(VERSION 3.28)

project(regex2nfa CXX)

set(SOURCE_LIB regex2nfa.cpp)
set(HEADERS regex2nfa.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(regex2nfa ${SOURCE_LIB} ${HEADERS})
target_include_directories(regex2nfa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})