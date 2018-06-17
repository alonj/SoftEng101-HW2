//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/QuickRobot.h"

void QuickRobot::doMove(const string &direction, Map *activeMap)
{
    Coordinate result = coordinate;
    Coordinate diffCoord = directionVector(direction);
    while(activeMap->inMapLimit(result) && activeMap->getCellStatus(result) != WALL)
        result += diffCoord;
    if(activeMap->inMapLimit(result))
    {
        result -= diffCoord;
        this->setCoordinate(result);
    }
    else
        this->setCoordinate(COORD_OUT_OF_BOUNDS);
}