//
// Created by alonj on 5/13/18.
//

#include "RobotDB.h"

Coordinate RobotDB::getRobotCoords(string &rname)
{
    for (RobotVec_it it = robots.begin(); it != robots.end(); it++)
        if ((*it)->getName() == rname)
            return (*it)->getCoordinate();
}

int RobotDB::getRobotIndex(const string &rname) {
    int result = -1;
    for (int i = 0; i < robots.size(); i++)
        if(robots[i]->getName() == rname)
            result = i;
    return result;
}

bool RobotDB::ExistsInCoord(Coordinate &coord) {
    for (RobotVec_it it = robots.begin(); it != robots.end() ; it++)
        if ((*it)->getCoordinate() == coord)
            return true;
    return false;
}

void RobotDB::MoveRobot(string rname, string direction) { // TODO add database restrictions
    int robotIndex = this->getRobotIndex(rname);
    robots[robotIndex]->Move(direction);
}

bool RobotDB::AddRobot(string rname, Coordinate robotCoor) {
    int robotIndex = this->getRobotIndex(rname);
    if (!map->inMapLimit(<#initializer#>))
        return false;
    if (robotIndex == -1)
    {
        robotCount++;
        Robot newRobot(robotCoor, rname);
    }
    else
        robots[robotIndex]->setCoordinate(robotCoor);
    return true;
}

void RobotDB::DeleteRobot(const std::string &rname) {
    int robotIndex = this->getRobotIndex(rname);
    RobotVec_it it = robots.begin()+robotIndex;
    Robot* destPtr = robots[robotIndex];
    robots.erase(it);
    delete destPtr;
}



