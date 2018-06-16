//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_SLOWROBOT_H
#define HW2ATTACHEDCODEFILES_SLOWROBOT_H

#include "Robot.h"

class SlowRobot: public Robot
{
public:
    SlowRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};
    virtual ~SlowRobot(){};
//    virtual void doMove(const string &direction, Map *activeMap) const;
    virtual void print()
    {
        printType(std::string("SLOW"));
    };

};

#endif //HW2ATTACHEDCODEFILES_SLOWROBOT_H
