//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_SLOWROBOT_H
#define HW2ATTACHEDCODEFILES_SLOWROBOT_H

#include "Robot.h"

/**
 * SlowRobot class role is a child class of Robot, holds all information and methods for robots of type: Slow.
 */

class SlowRobot: public Robot
{
public:
    SlowRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};// default constructor
    virtual ~SlowRobot(){};// default destructor
//    virtual void doMove(const string &direction, Map *activeMap) const;
    /**
     * function calls print of robot location and type.
     */
    virtual void print()
    {
        printType(std::string("SLOW"));
    };

};

#endif //HW2ATTACHEDCODEFILES_SLOWROBOT_H
