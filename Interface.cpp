//
// Created by alonj on 5/13/18.
//

#include "Interface.h"

using namespace std;

void CommandRoutine()
{
    string currentCommand;
    string robotID, direction;
    int coordX, coordY;
    cin >> currentCommand;
    while (!cin.eof())
    {
        if (currentCommand == "Move") // TODO implement in RobotDB.h
        {
        }
        else if (currentCommand == "MoveMulti") // TODO implement in RobotDB.h
        { // Move
        }
        else if (currentCommand == "MoveBuild") // TODO implement in RobotDB.h
        { // Move + AddPath
        }
        else if (currentCommand == "Clean") // TODO implement in RobotDB.h
        {
        }
        else if (currentCommand == "Place") // TODO implement in RobotDB.h
        {
        }
        else if (currentCommand == "Delete") // TODO implement in RobotDB.h
        {
        }
        else if (currentCommand == "AddDirt") // TODO implement in Map.h
        {
        }
        else if (currentCommand == "AddWall") // TODO implement in Map.h
        {
        }
        else if (currentCommand == "AddPath") // TODO implement in Map.h
        {
        }
        cin >> currentCommand;
    }
}

void StartControl(Map* map)
{
    cout << "Start entering commands:" << endl;
    CommandRoutine();
    PrintTable(robotName, robotScore, robotBinStatus);
}