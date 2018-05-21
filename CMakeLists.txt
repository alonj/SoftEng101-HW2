cmake_minimum_required(VERSION 3.9)
project(hw2AttachedCodeFiles)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(hw2AttachedCodeFiles
        main.cpp
        Coordinate.h
        Interface.h
        Interface.cpp
        Robot.h
        Robot.cpp
        Map.h
        Map.cpp
        RobotDB.h
        RobotDB.cpp
        )
