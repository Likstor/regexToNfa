cmake_minimum_required(VERSION 3.28)

project(nfa2dfa)

set(SOURCE_LIB nfa2dfa.cpp)

add_library(nfa2dfa STATIC ${SOURCE_LIB})