#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Map.h"

using namespace std;

typedef enum
{
    COMMUNICABLE = 0, NON_COMMUNICABLE = 1
} connection_e;

/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
class Robot
{

private:
    Coordinate _coordinate;
    const string _name;
    int _dust_bin;
    int _score;
    connection_e _connection;

public:
    // #################### Class methods ####################

    Robot(const Coordinate &coordinate, const string &name) : _coordinate(coordinate), _name(name),
                                                              _connection(COMMUNICABLE), _dust_bin(0) {}

    ~Robot(){};

    /**
     * function that prints robot location
     */
    inline void printLoc()
    {
        cout << "Robot: " << this->_name;
        _coordinate.print();
    }

    /**
     * function that prints cleaning message for a certain robot
     */
    inline void printClean()
    {
        cout << "Robot: " << this->_name << " is cleaning";
        _coordinate.print();
        cout << "dust bin: " << _dust_bin << endl;
    }

    /**
     * function changes robot's coordinate in the direction passed to method.
     * @param direction : Direction in which robot will move.
     */
    Coordinate directionToCoord(const string &direction) const;

    /**
     * function returns robot's name
     * @return string of robot name
     */
    inline const string &getName() const
    {
        return _name;
    }

    /**
     * function returns robot's coordinate
     * @return object of Coordinate type
     */
    inline Coordinate getCoordinate() const
    {
        return _coordinate;
    }

    /**
     * functions sets robot's coordinate; if new coordinate is negative, sets connection status to NON_COMMUNICABLE.
     * @param coordinate : new robot's coordinate
     */
    inline void setCoordinate(const Coordinate &coordinate)
    {
        Robot::_coordinate = coordinate;
        if (coordinate.outOfBounds())
            _connection = NON_COMMUNICABLE;
    }

    /**
     * getter function for "connection" attribute
     * @return : value of connection (COMMUNICABLE / NON_COMMUNICABLE)
     */

    inline connection_e getConnection() const
    {
        return _connection;
    }

    /**
     * getter function for dust bin attribute
     * @return : value of dust_bin (0 to 5)
     */
    inline int getDustBin() const
    {
        return _dust_bin;
    }

    /**
     * increment function for dust_bin attribute
     */
    inline void incDustBin()
    {
        _dust_bin++;
    }

    /**
     * zeroing function for dust_bin attribute
     */
    inline void zeroDustBin()
    {
        _dust_bin = 0;
    }

    /**
     * increment function for score attribute
     */
    inline void incScore()
    {
        _score++;
    }
};

#endif
