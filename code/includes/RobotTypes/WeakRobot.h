//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_WEAKROBOT_H
#define HW2ATTACHEDCODEFILES_WEAKROBOT_H

#include "Robot.h"


/**
 * WeakRobot class role is a child class of Robot, holds all information and methods for robots of type: Weak.
 */

class WeakRobot: public Robot
{
public:
    WeakRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};// default constructor
    virtual ~WeakRobot(){};// default destructor
//    virtual void doMove(const string &direction, Map *activeMap);

/**
 * function calls print of robot location and type.
 */
    virtual void print()
    {
        printType(std::string("WEAK"));
    };

};

#endif //HW2ATTACHEDCODEFILES_WEAKROBOT_H
