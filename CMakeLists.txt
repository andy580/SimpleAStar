cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)

project(SimpleAStar)

add_executable(astar src/main.cpp src/display.cpp src/parse.cpp src/search.cpp)
