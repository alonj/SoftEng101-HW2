//
// Created by alonj on 5/13/18.
//

#include "Interface.h"
#include <queue>

using namespace std;

void Interface::CommandRoutine()
{
    string currentCommand;
    string rname, direction;
    int coordX, coordY;
    cin >> currentCommand;
    while (!cin.eof())
    {
        if (currentCommand == "Move") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> direction;
            if (_pRobots->robotCommunicable(rname) == COMMUNICABLE)
                if (_pRobots->moveRobot(rname, direction)) // if move successful,
                    _pRobots->printLocation(rname); // print new location
        }
        else if (currentCommand == "MoveMulti") // TODO implement in RobotDB.h
        {
            string nextDirection;
            queue<string> instructionQueue;
            cin >> rname;
            cin >> nextDirection;
            while (nextDirection != "end") // save set on instructions into vector.
            {
                instructionQueue.push(nextDirection);
                cin >> nextDirection;
            }
            while (!instructionQueue.empty())
            {
                if (_pRobots->robotCommunicable(rname) == COMMUNICABLE)
                    if (_pRobots->moveRobot(rname,
                                            instructionQueue.front())) // Move robot per instructions and print only after "end" instruction received.
                        _pRobots->printLocation(rname);
                instructionQueue.pop();
            }
        }
        else if (currentCommand == "MoveBuild") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> direction;
            if (_pRobots->robotCommunicable(rname) == COMMUNICABLE)
            {
                Coordinate rCoord = _pRobots->directionToCoords(rname, direction);
                if (_interfaceMap->getCellStatus(rCoord) == WALL)
                    _interfaceMap->addPath(rCoord);
                if (_pRobots->moveRobot(rname, direction))
                    _pRobots->printLocation(rname);

            }

        }
        else if (currentCommand == "Clean") // TODO implement in RobotDB.h
        {
            cin >> rname;
            if (_pRobots->robotCommunicable(rname) == COMMUNICABLE)
            {
                if (_pRobots->cleanRobot(rname))
                    _pRobots->printClean(rname);
            }
        }
        else if (currentCommand == "Place") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (_pRobots->placeRobot(rname, rCoord))
                _pRobots->printLocation(rname);
        }
        else if (currentCommand == "Delete") // TODO implement in RobotDB.h
        {
            cin >> rname;
            _pRobots->deleteRobot(rname);
        }
        else if (currentCommand == "AddDirt") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (!_pRobots->existsInCoord(rCoord)
                && _interfaceMap->inMapLimit(rCoord)
                && _interfaceMap->getCellStatus(rCoord) != WALL)
                _interfaceMap->addDirt(rCoord);
        }
        else if (currentCommand == "AddWall") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (!_pRobots->existsInCoord(rCoord))
                _interfaceMap->addWall(rCoord);
        }
        else if (currentCommand == "AddPath") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            _interfaceMap->addPath(rCoord);
        }
        _pRobots->printMap();
        cin >> currentCommand;
    }
}

void Interface::StartControl(Map *map)
{
    _interfaceMap = map;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
//    PrintTable(robotName, robotScore, robotBinStatus);
}