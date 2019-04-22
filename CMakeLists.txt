cmake_minimum_required(VERSION 3.13)
project(graph_maze)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph_maze main.cpp graph.cpp graph.h graph.template maze.cpp maze.h graph_helpers.cpp)