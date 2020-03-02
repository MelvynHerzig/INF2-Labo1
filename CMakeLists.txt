cmake_minimum_required(VERSION 3.15)
project(Labo1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo1 main.cpp Temps.cpp Temps.h)