cmake_minimum_required(VERSION 3.9)
project(hw2AttachedCodeFiles)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw2AttachedCodeFiles
        Coordinate.h
        Interface.h
        main.cpp
        Robot.h
        Interface.cpp
        Map.cpp
        RobotDB.cpp
        RobotDB.h)
