cmake_minimum_required(VERSION 3.20)
project(hw09 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw09
        hw9.c
        maze.c
        maze.h
        mazehelper.c
        mazehelper.h
        path.c
        path.h
        solver.c
        solver.h)
