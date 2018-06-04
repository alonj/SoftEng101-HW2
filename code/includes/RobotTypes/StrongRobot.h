//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_STRONGROBOT_H
#define HW2ATTACHEDCODEFILES_STRONGROBOT_H

#include "Robot.h"

class StrongRobot: public Robot
{
    StrongRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type) :
            coordinate(new_coordinate),
            name(new_name),
            type(new_type),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    StrongRobot(const Coordinate& new_coordinate, const std::string& new_name) :
            coordinate(new_coordinate),
            name(new_name),
            type("strong"),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    virtual ~StrongRobot();
    virtual void print();

};

#endif //HW2ATTACHEDCODEFILES_STRONGROBOT_H
