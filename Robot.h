#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Map.h"

using namespace std;

typedef enum{COMMUNICABLE = 0, NON_COMMUNICABLE = 1} connection_e;

/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
class Robot
{

private:
    Coordinate coordinate;
    const string name;
    int dust_bin;
    int score;

public:
    // #################### Class methods ####################

    Robot(const Coordinate &coordinate, const string &name) : coordinate(coordinate), name(name) {}

    ~Robot();

    /**
     * function that prints robot location
     */
    inline void printLoc()
    {
        cout << "Robot: " << this->name;
        coordinate.print();
    }

    /**
     * function that prints cleaning message for a certain robot
     */
    inline void printClean()
    {
        cout << "Robot: " << this->name << " is cleaning";
        coordinate.print();
        cout << "dust bin: " << dust_bin << endl;
    }

    /**
     * function changes robot's coordinate in the direction passed to method.
     * @param Direction : Direction in which robot will move.
     */
    void Move(string& Direction);

    /**
     * function returns robot's name
     * @return string of robot name
     */
    inline const string &getName() const {
        return name;
    }

    /**
     * function returns robot's coordinate
     * @return object of Coordinate type
     */
    inline Coordinate getCoordinate() const {
        return coordinate;
    }

    void setCoordinate(const Coordinate &coordinate) {
        Coordinate newCoord(coordinate);
        Robot::coordinate = newCoord;
    }


};

#endif
