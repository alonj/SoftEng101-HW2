cmake_minimum_required(VERSION 3.9)
project(hw2AttachedCodeFiles)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(hw2AttachedCodeFiles
        code/main.cpp
        code/includes/Coordinate.h
        code/includes/Interface.h
        code/Interface.cpp
        code/includes/RobotTypes/Robot.h
        code/RobotTypes/Robot.cpp
        code/includes/Map.h
        code/Map.cpp
        code/includes/RobotDB.h
        code/RobotDB.cpp
        code/includes/RobotTypes/QuickRobot.h code/includes/RobotTypes/QuickLimitedRobot.h code/includes/RobotTypes/StrongRobot.h code/includes/RobotTypes/WeakRobot.h code/includes/RobotTypes/SlowRobot.h code/RobotTypes/QuickLimitedRobot.cpp code/RobotTypes/QuickRobot.cpp code/RobotTypes/SlowRobot.cpp code/RobotTypes/StrongRobot.cpp code/RobotTypes/WeakRobot.cpp)
