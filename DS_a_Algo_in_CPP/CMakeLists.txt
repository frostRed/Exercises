cmake_minimum_required(VERSION 3.6)
project(DS_a_Algo_in_CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
#add_executable(DS_a_Algo_in_CPP ${SOURCE_FILES} ch1/1-1.cpp)
add_executable(1-1.cpp ch1/1-1.cpp)
add_executable(1-2.cpp ch1/1-2.cpp)
add_executable(1-3.cpp ch1/1-3.cpp)
add_executable(1-5.cpp ch1/1-5.cpp)
add_executable(1-13.cpp ch1/1-13.cpp)
