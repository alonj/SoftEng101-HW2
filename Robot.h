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
    connection_e connection;

public:
    // #################### Class methods ####################

    Robot(const Coordinate &coordinate, const string &name) : coordinate(coordinate), name(name), connection(COMMUNICABLE), dust_bin(0) {}

    ~Robot(){};

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
     * @param direction : Direction in which robot will move.
     */
    Coordinate dirToCoord(string &direction);

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

    /**
     * functions sets robot's coordinate; if new coordinate is negative, sets connection status to NON_COMMUNICABLE.
     * @param coordinate : new robot's coordinate
     */
    inline void setCoordinate(const Coordinate &coordinate) {
        Coordinate newCoord(coordinate);
        Robot::coordinate = newCoord;
        if(coordinate.outOfBounds())
            connection = NON_COMMUNICABLE;
    }

    inline connection_e getConnection() const {
        return connection;
    }

    inline int getDust_bin() const {
        return dust_bin;
    }

    inline int getScore() const {
        return score;
    }

    inline void incDust_bin() { dust_bin++; }
    inline void zeroDust_bin() { dust_bin = 0; }
    inline void incScore() { score++; }
};

#endif
