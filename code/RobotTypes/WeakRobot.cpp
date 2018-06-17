//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/WeakRobot.h"

/*
void WeakRobot::doMove(const string &direction, Map *activeMap)
{
    Coordinate diffCoord = directionVector(direction);
    Coordinate result = coordinate;
    result += diffCoord;
    if(!activeMap->inMapLimit(result))
        this->setCoordinate(COORD_OUT_OF_BOUNDS);
    else if(activeMap->getCellStatus(result) != WALL)
        this->setCoordinate(result);
    else if(activeMap->getCellStatus(result) == WALL)
        delete this;
}*/
