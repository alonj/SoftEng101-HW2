//
// Created by alonj on 5/13/18.
//

#include "RobotDB.h"

const int RobotDB::getRobotIndex(const string &rname) const
{
    int result = -1;
    for (int i = 0; i < _robots.size(); i++)
        if (_robots[i]->getName() == rname)
            result = i;
    return result;
}

const bool RobotDB::existsInCoord(const Coordinate &coord) const
{
    for (RobotVec_cit cit = _robots.begin(); cit != _robots.end(); cit++)
        if ((*cit)->getCoordinate() == coord)
            return true;
    return false;
}

bool RobotDB::moveRobot(const string &rname, const string &direction)
{ // TODO add database restrictions
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    { // if robot exists
        Robot *currRobot = _robots[robotIndex];
        Coordinate newCoords = currRobot->directionToCoord(direction);
        CellType cellStatus = _map->getCellStatus(newCoords);
        if (cellStatus != WALL || !_map->inMapLimit(newCoords))
        {
            if (!_map->inMapLimit(newCoords)) // if robot moves to out of bounds
                currRobot->setCoordinate(Coordinate(-1, -1)); // place in -1,-1
            else currRobot->setCoordinate(newCoords); // otherwise, place in new coords
        }
        return true;
    }
    else return false;
}

bool RobotDB::placeRobot(const string &rname, Coordinate &coordinate)
{
    if (!_map->inMapLimit(coordinate) or _map->getCellStatus(coordinate) == WALL)
        return false;
    int robotIndex = this->getRobotIndex(rname);
    if (robotIndex == -1)
    {
        Robot *newRobot = new Robot(coordinate, rname);
        _robots.push_back(newRobot);
    }
    else
        _robots[robotIndex]->setCoordinate(coordinate);
    return true;
}

void RobotDB::deleteRobot(const std::string &rname)
{
    int robotIndex = this->getRobotIndex(rname);
    if (robotIndex != -1)
    {
        RobotVec_it it = _robots.begin() + robotIndex;
        Robot *robotToDelete = _robots[robotIndex];
        _robots.erase(it);
        delete robotToDelete;
    }
}

void RobotDB::printClean(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    {
        Robot *currRobot = _robots[robotIndex];
        currRobot->printClean();
    }
}

void RobotDB::printLocation(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    {
        Robot *currRobot = _robots[robotIndex];
        currRobot->printLoc();
    }
}

Coordinate RobotDB::directionToCoords(const string &rname, const string &direction)
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    {
        return _robots[robotIndex]->directionToCoord(direction);
    }
}

connection_e RobotDB::robotCommunicable(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
        return _robots[robotIndex]->getConnection();
    else return NON_COMMUNICABLE;
}

bool RobotDB::cleanRobot(const string &rname)
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    {
        Robot *currRobot = _robots[robotIndex];
        Coordinate currCoordinate = currRobot->getCoordinate();
        if (currRobot->getDustBin() == 5)
        {
            currRobot->setCoordinate(Coordinate(0, 0));
            currRobot->zeroDustBin();
            return false;
        }
        CellType currentCellStatus = _map->getCellStatus(currCoordinate);
        _map->cleanDirt(currCoordinate);
        if (currentCellStatus > _map->getCellStatus(currCoordinate))
        {
            currRobot->incScore();
            currRobot->incDustBin();
            return true;
        }
    }
    return false;
}

RobotDB::~RobotDB()
{
    for (RobotVec_it it = _robots.begin(); it != _robots.end(); it++)
    {
        string delName = (*it)->getName();
        deleteRobot(delName);
    }
}

void RobotDB::printMap() const
{
    cout << "Current Map Status:" << endl << ' ';
    for (int i = 0; i < _map->getMap_w(); i++) cout << '-';
    cout << endl;
    for (int i = 0; i < _map->getMap_h(); i++)
    {
        cout << '|';
        for (int j = 0; j < _map->getMap_w(); j++)
        {
            Coordinate currCoord(i, j);
            if (existsInCoord(currCoord) && _map->getCellStatus(currCoord) == DIRT) cout << 'D';
            else if (existsInCoord(currCoord)) cout << 'C';
            else if (_map->getCellStatus(currCoord) == DIRT) cout << 'o';
            else if (_map->getCellStatus(currCoord) == WALL) cout << '#';
            else if (_map->getCellStatus(currCoord) == PATH) cout << ' ';
        }
        cout << '|' << endl;
    }
    cout << ' ';
    for (int i = 0; i < _map->getMap_w(); i++) cout << '-';
    cout << endl;
}



