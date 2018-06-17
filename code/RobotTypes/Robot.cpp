//
// Created by alonj on 5/13/18.
//

#include "../includes/RobotTypes/Robot.h"

void Robot::doMove(const string &direction, Map *activeMap)
{
    Coordinate diffCoord = directionVector(direction);
    Coordinate result = coordinate;
    result += diffCoord;
    if(!activeMap->inMapLimit(result))
        this->setCoordinate(COORD_OUT_OF_BOUNDS);
    else if(activeMap->getCellStatus(result) != WALL)
        this->setCoordinate(result);
}

Coordinate Robot::directionVector(const string &direction)
{
    int diffX = 0, diffY = 0;
    if(direction[0] == 'U')
        diffX = -1;
    else if(direction[0] == 'D')
        diffX =  1;
    if(direction[0] == 'L' || direction[1] == 'L')
        diffY = -1;
    if(direction[0] == 'R' || direction[1] == 'R')
        diffY =  1;
    return Coordinate(diffX, diffY);
}

