//
// Created by alonj on 5/13/18.
//

#include "includes/Interface.h"
#include <queue>
#include <signal.h>

using namespace std;

void Interface::CommandRoutine()
{
    string currentCommand;
    string rname, direction;
    int coordX, coordY;
    cin >> currentCommand;
    while (!cin.eof())
    {
        if (currentCommand == "Move")
        {
            cin >> rname;
            cin >> direction;
            if (pRobots->robotCommunicable(rname) == COMMUNICABLE)
                if (pRobots->moveRobot(rname, direction)) // if move successful,
                    pRobots->printLocation(rname); // print new location
        }
        else if (currentCommand == "MoveMulti")
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
                if (pRobots->robotCommunicable(rname) == COMMUNICABLE)
                    if (pRobots->moveRobot(rname,
                                            instructionQueue.front())) // Move robot per instructions and print only after "end" instruction received.
                        pRobots->printLocation(rname);
                instructionQueue.pop();
            }
        }
        else if (currentCommand == "MoveBuild")
        {
            cin >> rname;
            cin >> direction;
            if (pRobots->robotCommunicable(rname) == COMMUNICABLE)
            {
                Coordinate rCoord = pRobots->directionToCoords(rname, direction);
                if (_iMap->getCellStatus(rCoord) == WALL)
                    _iMap->addPath(rCoord);
                if (pRobots->moveRobot(rname, direction))
                    pRobots->printLocation(rname);

            }

        }
        else if (currentCommand == "Clean")
        {
            cin >> rname;
            if (pRobots->robotCommunicable(rname) == COMMUNICABLE)
            {
                if (pRobots->cleanRobot(rname))
                    pRobots->printClean(rname);
            }
        }
        else if (currentCommand == "Place")
        {
            cin >> rname;
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (pRobots->placeRobot(rname, rCoord))
                pRobots->printLocation(rname);
        }
        else if (currentCommand == "Delete")
        {
            cin >> rname;
            pRobots->deleteRobot(rname);
        }
        else if (currentCommand == "AddDirt")
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (!pRobots->existsInCoord(rCoord)
                && _iMap->inMapLimit(rCoord)
                && _iMap->getCellStatus(rCoord) != WALL)
                _iMap->addDirt(rCoord);
        }
        else if (currentCommand == "AddWall")
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (!pRobots->existsInCoord(rCoord))
                _iMap->addWall(rCoord);
        }
        else if (currentCommand == "AddPath")
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            _iMap->addPath(rCoord);
        }
//        pRobots->printMap(); // uncomment for debugging
        cin >> currentCommand;
    }
}

void Interface::StartControl(Map *map)
{
    _iMap = map;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
//    PrintTable(robotName, robotScore, robotBinStatus);
}