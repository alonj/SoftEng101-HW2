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
    QuickLimitedRobot(const Coordinate& new_coordinate, const std::string& new_name, std::string& new_type, int limit) :
            coordinate(new_coordinate),
            name(new_name),
            type(new_type),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE),
            limit(limit){};
    QuickLimitedRobot(const Coordinate& new_coordinate, const std::string& new_name) :
            coordinate(new_coordinate),
            name(new_name),
            type("quicklim"),
            dust_bin(0),
            _score(0),
            _connection(COMMUNICABLE) {};
    virtual ~QuickLimitedRobot();
    virtual void print();
};

#endif //HW2ATTACHEDCODEFILES_QUICKLIMITEDROBOT_H