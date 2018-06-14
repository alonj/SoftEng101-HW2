//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_STRONGROBOT_H
#define HW2ATTACHEDCODEFILES_STRONGROBOT_H

#include "Robot.h"

class StrongRobot: public Robot
{
public:
    StrongRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};
    virtual ~StrongRobot(){};
    virtual Coordinate moveInstructionResult(const string &direction) const;
    virtual void print()
    {
        printType(std::string("STRONG"));
    };

};

#endif //HW2ATTACHEDCODEFILES_STRONGROBOT_H
