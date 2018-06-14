//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H
#define HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H

#include "Robot.h"

class QuickLimitedRobot: public Robot
{
private:
    int limit;
public:
    QuickLimitedRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type, int limit):
            Robot(new_coordinate, new_name, new_type),
            limit(limit) {};
    virtual ~QuickLimitedRobot(){};
    virtual Coordinate moveInstructionResult(const string &direction) const;
    virtual void print()
    {
        printType(std::string("QUICK_LIMITED"));
    };
};

#endif //HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H
