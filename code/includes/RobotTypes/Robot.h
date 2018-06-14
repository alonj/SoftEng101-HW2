#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "../Coordinate.h"
#include "../Map.h"

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
    connection_e _connection;
public:
    // #################### Class methods ####################

    Robot(const Coordinate &coordinate, const string &new_name, string &new_type) : coordinate(coordinate),
                                                                                    name(new_name),
                                                                                    type(new_type),
                                                              _connection(COMMUNICABLE) {} // default constructor

    virtual ~Robot(){}; // destructor
//    Robot();

    virtual void print()
    {
        printType(std::string("REGULAR"));
    };

    /**
     * function that prints robot location
     */
    inline void printLoc()
    {
        cout << "Robot: " << this->name;
        coordinate.print();
    }

    /**
     * function changes robot's coordinate in the direction passed to method.
     * @param direction : Direction in which robot will move.
     */
    virtual Coordinate moveInstructionResult(const string &direction, Map *activeMap) const;

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

    const string &getType() const
    {
        return type;
    }

protected:
    virtual void printType(const std::string & type_name)
    {
        std::cout << "Robot: " << this-> name << " Type: " << type_name;
            coordinate.print();
    };

};

#endif
