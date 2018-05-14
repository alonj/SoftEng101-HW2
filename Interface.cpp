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
                if(pRobots->MoveRobot(rname, direction)) // if move successful,
                    pRobots->printLocation(rname); // print new location
        }
        else if (currentCommand == "MoveMulti") // TODO implement in RobotDB.h
        {
            string nextDirection;
            queue<string> dirQueue;
            cin >> rname;
            cin >> nextDirection;
            while (nextDirection != "end") // save set on instructions into vector.
            {
                dirQueue.push(nextDirection);
                cin >> nextDirection;
            }
            while(!dirQueue.empty()){
                if(pRobots->robotCommunicable(rname) == COMMUNICABLE)
                    if(pRobots->MoveRobot(rname, dirQueue.front())) // Move robot per instructions and print only after "end" instruction received.
                        pRobots->printLocation(rname);
                dirQueue.pop();
            }
        }
        else if (currentCommand == "MoveBuild") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> direction;
            if(pRobots->robotCommunicable(rname) == COMMUNICABLE){
                Coordinate rCoord = pRobots->directionToCoords(rname, direction);
                if(iMap->getCellStatus(rCoord) == WALL)
                    iMap->addPath(rCoord);
                if(pRobots->MoveRobot(rname, direction))
                    pRobots->printLocation(rname);
            }

        }
        else if (currentCommand == "Clean") // TODO implement in RobotDB.h
        {
            cin >> rname;
            if(pRobots->robotCommunicable(rname) == COMMUNICABLE){
                pRobots->CleanRobot(rname);
                pRobots->printClean(rname);
            }
        }
        else if (currentCommand == "Place") // TODO implement in RobotDB.h
        {
            cin >> rname;
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (pRobots->PlaceRobot(rname, rCoord))
                pRobots->printLocation(rname);
        }
        else if (currentCommand == "Delete") // TODO implement in RobotDB.h
        {
            cin >> rname;
            pRobots->DeleteRobot(rname);
        }
        else if (currentCommand == "AddDirt") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if(!pRobots->ExistsInCoord(rCoord)
               && iMap->inMapLimit(rCoord)
               && iMap->getCellStatus(rCoord) != WALL)
                iMap->addDirt(rCoord);
        }
        else if (currentCommand == "AddWall") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            if(!pRobots->ExistsInCoord(rCoord))
                iMap->addWall(rCoord);
        }
        else if (currentCommand == "AddPath") // TODO implement in Map.h
        {
            cin >> coordX;
            cin >> coordY;
            Coordinate rCoord(coordX, coordY);
            iMap->addPath(rCoord);
        }
        cin >> currentCommand;
    }
}

void Interface::StartControl(Map* map)
{
    iMap = map;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
//    PrintTable(robotName, robotScore, robotBinStatus);
}