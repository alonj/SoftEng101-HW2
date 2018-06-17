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
    if(!map->inMapLimit(coord))
        return result;
    for (RobotVec_cit cit = robots.begin(); cit != robots.end(); cit++)
        if ((*cit)->getCoordinate() == coord)
            {
                if(result != ' ')
                    result = 'M';
                else if((*cit)->getType() == "Limited")
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
        RobotVec_it it = robots.begin()+robotIndex;
        if((*it)->getType() == "Weak") // if Weak-type robot hits a wall, it is deleted.
        {
            Coordinate newCoord = Robot::directionVector(direction);
            newCoord += (*it)->getCoordinate();
            if(map->getCellStatus(newCoord) == WALL)
            {
                delete (*it);
                cout<<"Robot "<<rname<<" is dead" << endl;
                robots.erase(it);
                return false;
            }
        }
        (*it)->doMove(direction, map);
        return true; // true == print location
    }
    else return false; // false == robot doesnt exist, dont print location
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
        else if(type == "Limited")
            newRobot = new QuickLimitedRobot(coordinate, rname, type, limit);
        else if(type == "Strong")
            newRobot = new StrongRobot(coordinate, rname, type);
        else if(type == "Weak")
            newRobot = new WeakRobot(coordinate, rname, type);
        else if(type == "Slow")
            newRobot = new SlowRobot(coordinate, rname, type);
        robots.push_back(newRobot);
    }
    else if (robots[robotIndex]->getType() == type)
    {
        robots[robotIndex]->setCoordinate(coordinate);
        if(type == "Limited")
            {
                deleteRobot(rname);
                Robot* newRobot = new QuickLimitedRobot(coordinate, rname, type, limit);
                robots.push_back(newRobot);
            }
    }
    else
        return false;
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
        currRobot->print();
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
    for(unsigned i = 0; i < robots.size(); i++)
        delete robots[i];
    robots.erase(robots.begin(), robots.end());
}

void RobotDB::debugPrint() const
{
    cout << endl << "Current Robot List: ";
    for (unsigned i = 0; i < robots.size(); i ++)
        cout << ", " << robots[i]->getName() << "(" << robots[i]->getCoordinate().getX() << ',' << robots[i]->getCoordinate().getY() << ")";
    cout << endl;
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
    else return "NULL";
}



