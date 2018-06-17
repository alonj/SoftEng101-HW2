//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_QUICKROBOT_H
#define HW2ATTACHEDCODEFILES_QUICKROBOT_H

#include "Robot.h"

/**
 * QuickRobot class role is a child class of Robot, holds all information and methods for robots of type: Quick.
 */

class QuickRobot: public Robot
{
public:

    QuickRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){}; // default constructor
    virtual ~QuickRobot(){}; // default destructor

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
        printType(std::string("QUICK"));
    };
};

#endif //HW2ATTACHEDCODEFILES_QUICKROBOT_H
