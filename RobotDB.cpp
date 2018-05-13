//
// Created by alonj on 18-Apr-18.
//
#include "Map.h"
#include "RobotDB.h"

/**
 * Module saves robots' attributes, and provides methods to control the robots.
 */

vector<int> robotScore; // the ranks for each Robot
vector<int> robotPosX; // Coordinate X for each robot
vector<int> robotPosY; // Coordinate Y for each robot
vector<int> robotBinStatus; // Dirt bin status (0-5)
vector<string> robotName; // Robot names
int robotCount; // total robot count


int getRobotIndex(string &robotID)
{
    int place = -1;
    for (vector<int>::size_type i = 0; i < robotName.size(); i++)
        if (robotName[i] == robotID)
            place = i;
    return place;
}

int dbGetRobotPos(string &robotID, char type)
{
    int id = getRobotIndex(robotID);
    if (type == 'x')
        return robotPosX[id];
    else if (type == 'y')
        return robotPosY[id];
    else
        return -1;

}

bool dbRobotInMap(string &robotID)
{
    int index = getRobotIndex(robotID);
    return inMapLimit(robotPosX[index], robotPosY[index]);
}

bool dbPlace(string &robotID, int &posX, int &posY)
{
    if (!inMapLimit(posX, posY))
        return false;
    int robotPtr = getRobotIndex(robotID);
    if (robotPtr == -1)
    {
        robotCount++;
        robotName.push_back(robotID);
        robotPosX.push_back(posX);
        robotPosY.push_back(posY);
        robotScore.push_back(0);
        robotBinStatus.push_back(0);
    }
    else
    {
        robotPosX[robotPtr] = posX;
        robotPosY[robotPtr] = posY;
    }
    return true;
}

void dbMove(string &robotID, string &direction)
{
    int currentRobot = getRobotIndex(robotID);
    int currX = robotPosX[currentRobot];
    int currY = robotPosY[currentRobot];
    int newX(currX), newY(currY);
    if (direction == "U" || direction == "UL" || direction == "UR")
        newX = --currX;
    if (direction == "D" || direction == "DL" || direction == "DR")
        newX = ++currX;
    if (direction == "L" || direction == "UL" || direction == "DL")
        newY = --currY;
    if (direction == "R" || direction == "UR" || direction == "DR")
        newY = ++currY;
    if (inMapLimit(newX, newY))
    {
        robotPosX[currentRobot] = newX;
        robotPosY[currentRobot] = newY;
    }
    else
    {
        robotPosX[currentRobot] = -1;
        robotPosY[currentRobot] = -1;
    }
}

void dbClean(string &robotID)
{
    int currentRobot = getRobotIndex(robotID);
    if (robotBinStatus[currentRobot] == 5)
    {
        robotPosX[currentRobot] = 0;
        robotPosY[currentRobot] = 0;
        robotBinStatus[currentRobot] = 0;
        return;
    }
    robotBinStatus[currentRobot]++;
    int currX = robotPosX[currentRobot];
    int currY = robotPosY[currentRobot];
    int currentCellStatus = getCellStatus(currX, currY);
    cleanDirt(currX, currY);
    if (currentCellStatus > getCellStatus(currX, currY))
        robotScore[currentRobot]++;
}

void dbDelete(string &robotID)
{
    int currentRobot = getRobotIndex(robotID);
    if (currentRobot == -1)
        return;
    robotScore.erase(robotScore.begin() + currentRobot - 1);
    robotPosX.erase(robotPosX.begin() + currentRobot - 1);
    robotPosY.erase(robotPosY.begin() + currentRobot - 1);
    robotBinStatus.erase(robotBinStatus.begin() + currentRobot - 1);
    robotName.erase(robotName.begin() + currentRobot - 1);
    robotCount--;
}

bool dbExistInCoords(int &posX, int &posY)
{
    for (vector<int>::size_type i = 0; i < robotCount; i++)
        if (robotPosY[i] == posY && robotPosX[i] == posX)
            return true;
    return false;
}