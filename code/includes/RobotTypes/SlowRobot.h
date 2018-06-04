//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_SLOWROBOT_H
#define HW2ATTACHEDCODEFILES_SLOWROBOT_H

#include "Robot.h"

class SlowRobot: public Robot
{
    SlowRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type) :
            coordinate(new_coordinate),
            name(new_name),
            type(new_type),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    SlowRobot(const Coordinate& new_coordinate, const std::string& new_name) :
            coordinate(new_coordinate),
            name(new_name),
            type("slow"),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    virtual ~SlowRobot();
    virtual void print();

};

#endif //HW2ATTACHEDCODEFILES_SLOWROBOT_H
