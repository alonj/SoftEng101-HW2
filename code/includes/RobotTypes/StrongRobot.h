//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_STRONGROBOT_H
#define HW2ATTACHEDCODEFILES_STRONGROBOT_H

#include "Robot.h"

/**
 * StrongRobot class role is a child class of Robot, holds all information and methods for robots of type: Strong.
 */

class StrongRobot: public Robot
{
public:
    StrongRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};// default constructor
    virtual ~StrongRobot(){};// default destructor

/**
 * function changes robot coordinates according to its special ruleset
 * @param direction : direction in which robot will move
 * @param activeMap : map object where robot is currently on.
 */
    virtual void doMove(const string &direction, Map *activeMap);

/**
 * function calls print of robot location and type.
 */
    virtual void print()
    {
        printType(std::string("STRONG"));
    };

};

#endif //HW2ATTACHEDCODEFILES_STRONGROBOT_H
