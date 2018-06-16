//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/QuickLimitedRobot.h"

void QuickLimitedRobot::doMove(const string &direction, Map *activeMap)
{
    Coordinate result = coordinate;
    int remainingSteps = this->limit;
    Coordinate diffCoord = directionVector(direction);
    while(activeMap->getCellStatus(result) != WALL && activeMap->inMapLimit(result) && remainingSteps > 0)
    {
        result += diffCoord;
        remainingSteps--;
    }
    if(activeMap->inMapLimit(result))
    {
        if(activeMap->getCellStatus(result) == WALL)
            result -= diffCoord;
        this->setCoordinate(result);
    }
    else
        this->setCoordinate(COORD_OUT_OF_BOUNDS);

}