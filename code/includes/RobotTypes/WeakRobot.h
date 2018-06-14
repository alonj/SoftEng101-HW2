//
// Created by alonj on 6/4/18.
//

#ifndef HW2ATTACHEDCODEFILES_WEAKROBOT_H
#define HW2ATTACHEDCODEFILES_WEAKROBOT_H

#include "Robot.h"

class WeakRobot: public Robot
{
public:
    WeakRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type) :
            coordinate(new_coordinate),
            name(new_name),
            type(new_type),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    virtual ~WeakRobot();
    virtual void print();

};

#endif //HW2ATTACHEDCODEFILES_WEAKROBOT_H
