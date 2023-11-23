cmake_minimum_required(VERSION 3.28)

project(RegexToNFA&DFA)	

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_EXE main.cpp)

include_directories(nfa2dfa)
include_directories(printFA)
include_directories(regex2nfa)

add_executable(main ${SOURCE_EXE})

add_subdirectory(nfa2dfa)
add_subdirectory(printFA)
add_subdirectory(regex2nfa)

target_link_libraries(main nfa2dfa)

target_link_libraries(main printFA)

target_link_libraries(main regex2nfa)