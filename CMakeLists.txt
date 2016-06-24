cmake_minimum_required(VERSION 3.5)
project(coding_challenges)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(coding_challenges main.cpp)
add_executable(maine main.cpp)
add_executable(project-euler-3 project-euler/problem3.cpp)
add_executable(project-euler-4 project-euler/problem4.cpp)
add_executable(project-euler-5 project-euler/problem5.cpp)
add_executable(project-euler-6 project-euler/problem6.cpp)
add_executable(project-euler-10 project-euler/problem10.cpp)

add_executable(cpp-intro-bit-array hackerrank/cpp-intro-bit-array.cpp)
add_executable(ai-bot-building-1 hackerrank/ai-bot-building.cpp)
add_executable(ai-maze-escape hackerrank/ai-maze-escape.cpp)