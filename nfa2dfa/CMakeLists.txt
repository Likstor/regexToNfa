cmake_minimum_required(VERSION 3.28)

project(nfa2dfa CXX)

set(SOURCE_LIB nfa2dfa.cpp)
set(HEADERS nfa2dfa.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(nfa2dfa ${SOURCE_LIB} ${HEADERS})
target_include_directories(nfa2dfa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})