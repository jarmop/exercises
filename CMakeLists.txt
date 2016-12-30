cmake_minimum_required(VERSION 3.5)
project(coding_challenges)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(coding_challenges main.cpp)
add_executable(maine main.cpp)

add_subdirectory(project-euler)

add_executable(cpp-intro-bit-array hackerrank/cpp-intro-bit-array.cpp)
add_executable(ai-bot-building-1 hackerrank/ai-bot-building.cpp)
add_executable(ai-maze-escape hackerrank/ai-maze-escape.cpp)