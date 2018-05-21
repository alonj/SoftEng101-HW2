//
// Created by alonj on 5/13/18.
//

#ifndef HW2ATTACHEDCODEFILES_ROBOTDB_H
#define HW2ATTACHEDCODEFILES_ROBOTDB_H


#include <vector>
#include "Robot.h"
#include "Map.h"

typedef std::vector<Robot *> RobotVec;
typedef std::vector<Robot *>::iterator RobotVec_it;
typedef std::vector<Robot *>::const_iterator RobotVec_cit;

class RobotDB
{
private:
    RobotVec _robots;
    Map *_map;

    /**
     * function returns index of specified robot name in the robot vector "robots" of
     * current object
     * @param rname : name of the specified robot
     * @return integer index in vector
     */
    const int getRobotIndex(const string &rname) const;

public:
    explicit RobotDB(Map *newMap) // default constructor
    {
        _map = newMap;
    };

    ~RobotDB(); // destructor

    /**
     * function removes specified robot from the robot vector "robots"
     * @param rname : name of the specified robot
     */
    void deleteRobot(const string &rname);

    /**
     * function places specified robot (moves robot if exists, new robot if not)
     * in specified coordinate
     * @param rname : name of specified robot
     * @param coordinate : coordinate to place robot in
     * @return true if placement coordinates are valid
     */
    bool placeRobot(const string &rname, Coordinate &coordinate);

    /**
     * function moves robot one cell in the specified direction
     * @param rname : name of specified robot
     * @param direction : direction to move in (u, l, r, d or any combination thereof)
     * @return : true if robot name is valid (exists)
     */
    bool moveRobot(const string &rname, const string &direction);

    /**
     * function checks if a robot exists in specified coordinates
     * @param coord : specified coordinates
     * @return : true if exists
     */
    const bool existsInCoord(const Coordinate &coord) const;

    /**
     * function cleans cell in the coordinates of the specified robot (i.e:
     * turns cell value to 0 (PATH))
     * @param rname : name of the specified robot
     * @return : true if robot exists AND dust bin not full (value < 5)
     */
    bool cleanRobot(const string &rname);

    /**
     * function prints "clean" message with the specified robot name and coordinates
     * @param rname : name of specified robot
     */
    void printClean(const string &rname) const;

    /**
     * function prints "location" message with the specified robot name and coordinates
     * @param rname : name of specified robot
     */
    void printLocation(const string &rname) const;

    /**
     * function converts a given direction from a robot, into a coordinate object
     * for example, robot coordinates = (2,2), given direction R, return is (2,3)
     * @param rname : name of specified robot which coordinates serve as starting point
     * @param direction : direction to move from known coordinates
     * @return : coordinate object of the given direction from the robot
     */
    Coordinate directionToCoords(const string &rname, const string &direction);

    /**
     * function returns communicability status of specified robot
     * @param rname : name of specified robot
     * @return : value of robot's "connection" attribute, if robot exists
     */
    connection_e robotCommunicable(const string &rname) const;

    /**
     * function prints entire map's status.
     * " " for path (C if also exists robot in coordinates)
     * "o" for dirt (D if also exists robot in coordinates)
     * "#" for wall.
     *
     * used for debugging
     */
    void printMap() const;
};


#endif //HW2ATTACHEDCODEFILES_ROBOTDB_H
