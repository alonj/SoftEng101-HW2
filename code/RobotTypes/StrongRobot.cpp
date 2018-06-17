//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/StrongRobot.h"

void StrongRobot::doMove(const string &direction, Map *activeMap)
{
    Coordinate result = coordinate;
    bool isWall = false;
    Coordinate diffCoord = directionVector(direction);
    while(!isWall && activeMap->inMapLimit(result))
    {
        result += diffCoord;
        if(activeMap->getCellStatus(result) == WALL)
            isWall = true;
    }
    if(!activeMap->inMapLimit(result))
        this->setCoordinate(COORD_OUT_OF_BOUNDS);
    else if(isWall)
    {
        activeMap->addPath(result);
        this->setCoordinate(result);
    }
}