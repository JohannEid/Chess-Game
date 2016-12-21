cmake_minimum_required(VERSION 3.6)
project(Chess_Game_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp object.cpp object.h Header.h Board.cpp Board.h)
add_executable(Chess_Game_ ${SOURCE_FILES})