//
// Created by alonj on 6/14/18.
//

#include "../includes/RobotTypes/QuickLimitedRobot.h"

Coordinate QuickLimitedRobot::moveInstructionResult(const string &direction, Map *activeMap) const
{
    Coordinate result = coordinate;
    int remainingSteps = this->limit;
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
    while(activeMap->getCellStatus(result) != WALL && activeMap->inMapLimit(result) && remainingSteps > 0)
    {
        result.setX(result.getX() + diffX);
        result.setY(result.getY() + diffY);
        remainingSteps--;
    }
    return result;
}