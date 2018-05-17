//
// Created by alonj on 5/13/18.
//

#include "RobotDB.h"

Coordinate RobotDB::getRobotCoords(string &rname)
{
    for (RobotVec_cit cit = robots.begin(); cit != robots.end(); cit++)
        if ((*cit)->getName() == rname)
            return (*cit)->getCoordinate();
}

int RobotDB::getRobotIndex(const string &rname) {
    int result = -1;
    for (int i = 0; i < robots.size(); i++)
        if(robots[i]->getName() == rname)
            result = i;
    return result;
}

bool RobotDB::ExistsInCoord(Coordinate &coord) {
    for (RobotVec_cit cit = robots.begin(); cit != robots.end() ; cit++)
        if ((*cit)->getCoordinate() == coord)
            return true;
    return false;
}

bool RobotDB::MoveRobot(string rname, string direction) { // TODO add database restrictions
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1){ // if robot exists
        Robot* currRobot = robots[robotIndex];
        Coordinate newCoords = currRobot->dirToCoord(direction);
        cell_type cellStatus = map->getCellStatus(newCoords);
        if (cellStatus != WALL || !map->inMapLimit(newCoords)){
            if(!map->inMapLimit(newCoords)) // if robot moves to out of bounds
                currRobot->setCoordinate(Coordinate(-1,-1)); // place in -1,-1
            else currRobot->setCoordinate(newCoords); // otherwise, place in new coords
        }
        return true;
    }
    else return false;
}

bool RobotDB::PlaceRobot(string rname, Coordinate coordinate) {
    if (!map->inMapLimit(coordinate) or map->getCellStatus(coordinate) == WALL)
        return false;
    int robotIndex = this->getRobotIndex(rname);
    if (robotIndex == -1)
    {
        Robot* newRobot = new Robot(coordinate, rname);
        robots.push_back(newRobot);
    }
    else
        robots[robotIndex]->setCoordinate(coordinate);
    return true;
}

void RobotDB::DeleteRobot(const std::string &rname) {
    int robotIndex = this->getRobotIndex(rname);
    if(robotIndex != -1){
        RobotVec_it it = robots.begin()+robotIndex;
        Robot* destPtr = robots[robotIndex];
        robots.erase(it);
        delete destPtr;
    }
}

void RobotDB::printClean(string &rname) {
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1){
        Robot* currRobot = robots[robotIndex];
        currRobot->printClean();
    }
}

void RobotDB::printLocation(string &rname) {
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1){
        Robot* currRobot = robots[robotIndex];
        currRobot->printLoc();
    }
}

Coordinate RobotDB::directionToCoords(string &rname, string &dir) {
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1) {
        return robots[robotIndex]->dirToCoord(dir);
    }
}

connection_e RobotDB::robotCommunicable(string &rname) {
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1)
        return robots[robotIndex]->getConnection();
    else return NON_COMMUNICABLE;
}

bool RobotDB::CleanRobot(string &rname) {
    int robotIndex = getRobotIndex(rname);
    if(robotIndex != -1){
        Robot* currRobot = robots[robotIndex];
        Coordinate currCoordinate = currRobot->getCoordinate();
        if (currRobot->getDust_bin() == 5)
        {
            currRobot->setCoordinate(Coordinate(0,0));
            currRobot->zeroDust_bin();
            return false;
        }
        cell_type currentCellStatus = map->getCellStatus(currCoordinate);
        map->cleanDirt(currCoordinate);
        if (currentCellStatus > map->getCellStatus(currCoordinate)) {
            currRobot->incScore();
            currRobot->incDust_bin();
            return true;
        }
    }
    return false;
}

RobotDB::~RobotDB() {
    for(RobotVec_it it = robots.begin(); it != robots.end(); it++){
        DeleteRobot((*it)->getName());
    }
}



