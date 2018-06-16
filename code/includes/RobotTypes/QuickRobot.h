//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_QUICKROBOT_H
#define HW2ATTACHEDCODEFILES_QUICKROBOT_H

#include "Robot.h"

class QuickRobot: public Robot
{
public:
    QuickRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};
    virtual ~QuickRobot(){};
    virtual void doMove(const string &direction, Map *activeMap);
    virtual void print()
    {
        printType(std::string("QUICK"));
    };
};

#endif //HW2ATTACHEDCODEFILES_QUICKROBOT_H
