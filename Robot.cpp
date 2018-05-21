//
// Created by alonj on 5/13/18.
//

#include "Robot.h"

Coordinate Robot::directionToCoord(const string &direction) const {
    Coordinate result = _coordinate;
    int currX = _coordinate.getX();
    int currY = _coordinate.getY();
    if (direction == "U" || direction == "UL" || direction == "UR")
        result.setX(--currX);
    if (direction == "D" || direction == "DL" || direction == "DR")
        result.setX(++currX);
    if (direction == "L" || direction == "UL" || direction == "DL")
        result.setY(--currY);
    if (direction == "R" || direction == "UR" || direction == "DR")
        result.setY(++currY);
    return result;
}

