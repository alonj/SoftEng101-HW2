//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/StrongRobot.h"

Coordinate StrongRobot::moveInstructionResult(const string &direction, Map *activeMap) const
{
    Coordinate result = coordinate;
    bool isWall = false;
    int diffX = 0;
    int diffY = 0;
    if (direction == "U" || direction == "UL" || direction == "UR")
        diffX = -1;
    if (direction == "D" || direction == "DL" || direction == "DR")
        diffX = 1;
    if (direction == "L" || direction == "UL" || direction == "DL")
        diffY = -1;
    if (direction == "R" || direction == "UR" || direction == "DR")
        diffY = 1;
    while(!isWall && activeMap->inMapLimit(result))
    {
        result.setX(result.getX() + diffX);
        result.setY(result.getY() + diffY);
        if(activeMap->getCellStatus(result) == WALL)
            isWall = true;
    }
    if(isWall)
    {
        result.setX(result.getX() + diffX);
        result.setY(result.getY() + diffY);
        activeMap->addPath(result);
    }
    return result;
}