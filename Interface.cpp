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
            if(pRobots->robotCommunicable(rname) == COMMUNICABLE)
                if(pRobots->moveRobot(rname, direction)) // if move successful,
                    pRobots->printLocation(rname); // print new location
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
            while(!instructionQueue.empty()){
                if(pRobots->robotCommunicable(rname) == COMMUNICABLE)
                    if(pRobots->moveRobot(rname, instructionQueue.front())) // Move robot per instructions and print only after "end" instruction received.
                        pRobots->printLocation(rname);
                instructionQueue.pop();
            }
        }
        else if (currentCommand == "MoveBuild") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> direction;
            if(pRobots->robotCommunicable(rname) == COMMUNICABLE){
                Coordinate rCoord = pRobots->directionToCoords(rname, direction);
                if(interfaceMap->getCellStatus(rCoord) == WALL)
                    interfaceMap->addPath(rCoord);
                if(pRobots->moveRobot(rname, direction))
                    pRobots->printLocation(rname);

            }

        }
        else if (currentCommand == "Clean") // TODO implement in RobotDB.h
        {
            cin >> rname;
            if(pRobots->robotCommunicable(rname) == COMMUNICABLE){
                if(pRobots->cleanRobot(rname))
                    pRobots->printClean(rname);
            }
        }
        else if (currentCommand == "Place") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (pRobots->placeRobot(rname, rCoord))
                pRobots->printLocation(rname);
        }
        else if (currentCommand == "Delete") // TODO implement in RobotDB.h
        {
            cin >> rname;
            pRobots->deleteRobot(rname);
        }
        else if (currentCommand == "AddDirt") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if(!pRobots->existsInCoord(rCoord)
               && interfaceMap->inMapLimit(rCoord)
               && interfaceMap->getCellStatus(rCoord) != WALL)
                interfaceMap->addDirt(rCoord);
        }
        else if (currentCommand == "AddWall") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if(!pRobots->existsInCoord(rCoord))
                interfaceMap->addWall(rCoord);
        }
        else if (currentCommand == "AddPath") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            interfaceMap->addPath(rCoord);
        }
        pRobots->printMap();
        cin >> currentCommand;
    }
}

void Interface::StartControl(Map* map)
{
    interfaceMap = map;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
//    PrintTable(robotName, robotScore, robotBinStatus);
}