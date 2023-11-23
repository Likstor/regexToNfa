cmake_minimum_required(VERSION 3.28)

project(regex2nfa)

set(SOURCE_LIB regex2nfa.cpp)

add_library(regex2nfa STATIC ${SOURCE_LIB})