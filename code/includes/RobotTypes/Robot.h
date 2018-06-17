#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "../Coordinate.h"
#include "../Map.h"

#define COORD_OUT_OF_BOUNDS Coordinate(-1,-1)

using namespace std;

typedef enum{COMMUNICABLE = 0, NON_COMMUNICABLE = 1} connection_e;

/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
class Robot
{

protected:
    Coordinate coordinate;
    const string name;
    string type;
    connection_e connection_status;
public:
    // #################### Class methods ####################

    Robot(const Coordinate& coordinate, const string& new_name, string& new_type) : coordinate(coordinate),
                                                                                    name(new_name),
                                                                                    type(new_type),
                                                              connection_status(COMMUNICABLE) {} // default constructor

    virtual ~Robot(){}; // destructor

    /**
     * function prints robot type and location
     */
    virtual void print()
    {
        printType(std::string("REGULAR"));
    };

    /**
     * function changes robot's coordinate in the direction passed to method.
     * @param direction : Direction in which robot will move.
     */
    virtual void doMove(const string &direction, Map *activeMap);

    /**
     * function returns robot's name
     * @return string of robot name
     */
    inline const string &getName() const
    {
        return name;
    }

    /**
     * function returns robot's coordinate
     * @return object of Coordinate type
     */
    inline Coordinate getCoordinate() const
    {
        return coordinate;
    }

    /**
     * functions sets robot's coordinate; if new coordinate is negative, sets connection status to NON_COMMUNICABLE.
     * @param coordinate : new robot's coordinate
     */
    inline void setCoordinate(const Coordinate &coordinate)
    {
        Robot::coordinate = coordinate;
        if (coordinate.outOfBounds())
            connection_status = NON_COMMUNICABLE;
    }

    /**
     * getter function for "connection" attribute
     * @return : value of connection (COMMUNICABLE / NON_COMMUNICABLE)
     */

    inline connection_e getConnection() const
    {
        return connection_status;
    }

    /**
     * function returns type of robot
     * @return string of robot Type
     */
    const string &getType() const
    {
        return type;
    }

    /**
     * function returns an integer vector (x,y) of values in range [-1,1] according to the direction string input
     * @param direction : U, D, L, R or any legal combination (8 total)
     * @return Coordinate object of direction.
     */
    static Coordinate directionVector(const string &direction);

protected:
    /**
     * function prints location and type of Robot
     * @param type_name : type to print
     */
    virtual void printType(const std::string & type_name)
    {
        std::cout << "Robot: " << this-> name << " Type: " << type_name;
            coordinate.print();
    };
};

#endif
