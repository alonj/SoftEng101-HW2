//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H
#define HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H

#include "Robot.h"

/**
 * QuickLimitedRobot class role is a child class of Robot, holds all information and methods for robots of type: Quick Limited.
 */

class QuickLimitedRobot: public Robot
{
private:
    int limit;
public:
    QuickLimitedRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type, int limit):
            Robot(new_coordinate, new_name, new_type),
            limit(limit) {}; // default constructor
    virtual ~QuickLimitedRobot(){}; // default destructor

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
        printType(std::string("LIMITED"));
    };
};

#endif //HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H
