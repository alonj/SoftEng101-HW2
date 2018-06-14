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
            cin >> rname >> direction;
            if (pRobots->robotCommunicable(rname) == COMMUNICABLE)
                if (pRobots->moveRobot(rname, direction)) // if move successful,
                    pRobots->printLocation(rname); // print new location
        }
        else if (currentCommand == "MoveMulti")
        {
            string nextDirection;
            queue<string> instructionQueue;
            cin >> rname >> nextDirection;
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
        else if (   currentCommand == "PlaceRegularRobot"      ||
                    currentCommand == "PlaceQuickRobot"        ||
                    currentCommand == "PlaceQuickLimitedRobot" ||
                    currentCommand == "PlaceStrongRobot"       ||
                    currentCommand == "PlaceWeakRobot"         ||
                    currentCommand == "PlaceSlowRobot"  )
        {
            int limit = 0;
            cin >> rname >> coordX >> coordY;
            Coordinate rcoord(coordX, coordY);
            string rtype = currentCommand.substr(5, currentCommand.find("Robot")-5); // extract robot type from command input
            if(rtype == "QuickLimited")
                cin >> limit;
            if (pRobots->placeRobot(rname, rcoord, rtype, limit))
                pRobots->printLocation(rname);
        }
        else if (currentCommand == "Delete")
        {
            cin >> rname;
            pRobots->deleteRobot(rname);
        }
        else if (currentCommand == "AddWall")
        {
            cin >> coordX >> coordY;
            Coordinate rCoord(coordX, coordY);
            if (!pRobots->existsInCoord(rCoord))
                _iMap->addWall(rCoord);
        }
        else if (currentCommand == "AddPath")
        {
            cin >> coordX >> coordY;
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
}