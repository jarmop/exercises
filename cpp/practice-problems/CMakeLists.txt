cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project (practice-problems)
include_directories(${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
add_executable(interview_cake interview_cake.cpp)
add_executable(cprogramming cprogramming.cpp)
add_executable(leetcode leetcode.cpp)
add_executable(glassdoor-google glassdoor-google.cpp)
add_executable(selected-problems selected-problems.cpp)
add_executable(cracking-the-coding-interview cracking-the-coding-interview.cpp)
target_link_libraries(cracking-the-coding-interview ${CMAKE_SOURCE_DIR}/include/googletest/build/googlemock/gtest/libgtest.a)