//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_WEAKROBOT_H
#define HW2ATTACHEDCODEFILES_WEAKROBOT_H

#include "Robot.h"

class WeakRobot: public Robot
{
public:
    WeakRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type):
            Robot(new_coordinate, new_name, new_type){};
    virtual ~WeakRobot(){cout<<"Robot "<<name<<"is dead";};
    virtual Coordinate moveInstructionResult(const string &direction) const;
    virtual void print()
    {
        printType(std::string("WEAK"));
    };

};

#endif //HW2ATTACHEDCODEFILES_WEAKROBOT_H
