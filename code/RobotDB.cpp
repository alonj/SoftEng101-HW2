//
// Created by alonj on 5/13/18.
//

#include "includes/RobotDB.h"

int RobotDB::getRobotIndex(const string &rname) const
{
    int result = -1;
    for (unsigned i = 0; i < robots.size(); i++)
        if (robots[i]->getName() == rname)
            result = i;
    return result;
}

char RobotDB::existsInCoord(const Coordinate &coord) const
{
    char result = ' ';
    for (RobotVec_cit cit = robots.begin(); cit != robots.end(); cit++)
        if ((*cit)->getCoordinate() == coord)
            {
                if(result != ' ')
                    result = 'M';
                else if((*cit)->getType() == "QuickLimited")
                    result = 'L';
                else if((*cit)->getType() == "Strong")
                    result = 'T';
                else result = (*cit)->getType()[0];
            }
    return result;
}

bool RobotDB::moveRobot(const string &rname, const string &direction)
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    { // if robot exists
        Robot *currRobot = robots[robotIndex];
        string currRobotType = currRobot->getType();
        Coordinate newCoords = currRobot->moveInstructionResult(direction, map);
        CellType cellStatus = map->getCellStatus(newCoords);
        if (cellStatus == WALL && currRobot->getType() == "Weak")
        { // if Weak-type hits a wall, it is deleted and a specific msg printed, no need to print location. return.
            delete currRobot;
            return false;
        }
        else if (cellStatus != WALL || !map->inMapLimit(newCoords))
        {
            if (!map->inMapLimit(newCoords)) // if robot moves to out of bounds
                currRobot->setCoordinate(Coordinate(-1, -1)); // place in -1,-1
            else currRobot->setCoordinate(newCoords); // otherwise, place in new coords
        }
        return true;
    }
    else return false;
}

bool RobotDB::placeRobot(const string &rname, Coordinate &coordinate, string &type, int limit = 0)
{
    if (!map->inMapLimit(coordinate) or map->getCellStatus(coordinate) == WALL)
        return false;
    int robotIndex = this->getRobotIndex(rname);
    if (robotIndex == -1)
    {
        Robot* newRobot;
        if(type == "Regular")
            newRobot = new Robot(coordinate, rname, type);
        else if(type == "Quick")
            newRobot = new QuickRobot(coordinate, rname, type);
        else if(type == "QuickLimited")
            newRobot = new QuickLimitedRobot(coordinate, rname, type, limit);
        else if(type == "Strong")
            newRobot = new StrongRobot(coordinate, rname, type);
        else if(type == "Weak")
            newRobot = new WeakRobot(coordinate, rname, type);
        else if(type == "Slow")
            newRobot = new SlowRobot(coordinate, rname, type);
        robots.push_back(newRobot);
    }
    else
        robots[robotIndex]->setCoordinate(coordinate);
    return true;
}

void RobotDB::deleteRobot(const std::string &rname)
{
    int robotIndex = this->getRobotIndex(rname);
    if (robotIndex != -1)
    {
        RobotVec_it it = robots.begin() + robotIndex;
        Robot *robotToDelete = robots[robotIndex];
        robots.erase(it);
        delete robotToDelete;
    }
}

void RobotDB::printLocation(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    {
        Robot *currRobot = robots[robotIndex];
        currRobot->printLoc();
    }
}

connection_e RobotDB::robotCommunicable(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
        return robots[robotIndex]->getConnection();
    else return NON_COMMUNICABLE;
}


RobotDB::~RobotDB()
{
    while(!robots.empty())
    {
        RobotVec_it it = robots.begin();
        robots.erase(robots.begin());
        delete *it;
    }
}

void RobotDB::printMap() const
{
    cout << "Current Map Status:" << endl << ' ';
    for (int i = 0; i < map->getMap_w(); i++) cout << '-';
    cout << endl;
    for (int i = 0; i < map->getMap_h(); i++)
    {
        cout << '|';
        for (int j = 0; j < map->getMap_w(); j++)
        {
            Coordinate currCoord(i, j);
            char robotInCoord = existsInCoord(currCoord);
            if (robotInCoord != ' ') cout << robotInCoord;
            else if (map->getCellStatus(currCoord) == WALL) cout << '#';
            else if (map->getCellStatus(currCoord) == PATH) cout << ' ';
        }
        cout << '|' << endl;
    }
    cout << ' ';
    for (int i = 0; i < map->getMap_w(); i++) cout << '-';
    cout << endl;
}

string RobotDB::robotType(const string &rname) const
{
    int robotIndex = getRobotIndex(rname);
    if (robotIndex != -1)
    { // if robot exists
        Robot *currRobot = robots[robotIndex];
        return currRobot->getType();
    }
}



