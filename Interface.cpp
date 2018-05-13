#include "Interface.h"
#include <vector>
#include <queue>
#include "RobotDB.h"
#include "Map.h"
#include "Printer.h"

//
// Created by alonj on 18-Apr-18.
//

/**
 * Module interprets and classifies user input into appropriate robot methods in RobotDB.h
 */

extern vector<string> robotName;
extern vector<int> robotScore;
extern vector<int> robotBinStatus;
extern int robotCount;

using namespace std;

void CommandRoutine()
{
    string currentCommand;
    string robotID, direction;
    int coordX, coordY;
    cin >> currentCommand;
    while (!cin.eof())
    {
        if (currentCommand == "Move")
        {
            cin >> robotID;
            cin >> direction;
            if (dbRobotInMap(robotID)) // call Move method if robot is in valid coords.
            {
                dbMove(robotID, direction);
                PrintRobotPlace(robotID, dbGetRobotPos(robotID, 'x'),
                                dbGetRobotPos(robotID, 'y'));
            }
        }
        else if (currentCommand == "AddDirt")
        {
            cin >> coordX;
            cin >> coordY;
            if (!dbExistInCoords(coordX, coordY) && inMapLimit(coordX, coordY))
                addDirt(coordX, coordY); // if coordinates valid and no robot exists there, add dirt.
        }
        else if (currentCommand == "Clean")
        {
            cin >> robotID;
            if (dbRobotInMap(robotID))
            {
                dbClean(robotID); // clean coordinates of robot with name robotID.
                PrintClean(robotID, dbGetRobotPos(robotID, 'x'),
                           dbGetRobotPos(robotID, 'y'));
            }
        }
        else if (currentCommand == "Place")
        {
            cin >> robotID;
            cin >> coordX;
            cin >> coordY;
            bool placementSuccess = dbPlace(robotID, coordX, coordY); // place new robot.
            if (placementSuccess)
                PrintRobotPlace(robotID, coordX, coordY);
        }
        else if (currentCommand == "Delete")
        {
            cin >> robotID;
            dbDelete(robotID);
        }
        else if (currentCommand == "MoveMulti")
        {
            string nextDirection;
            vector<string> directionList;
            cin >> robotID;
            cin >> nextDirection;
            while (nextDirection != "end") // save set on instructions into vector.
            {
                directionList.push_back(nextDirection);
                cin >> nextDirection;
            }
            for (vector<string>::iterator it = directionList.begin();
                 it != directionList.end(); it++)
                if (dbRobotInMap(robotID))
                {
                    dbMove(robotID, *it); // Move robot per instructions and print only after "end" instruction received.
                    PrintRobotPlace(robotID, dbGetRobotPos(robotID, 'x'),
                                    dbGetRobotPos(robotID, 'y'));
                }
        }
//        printMap();
        cin >> currentCommand;
    }
}

void StartControl()
{
    robotCount = 0;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
    PrintTable(robotName, robotScore, robotBinStatus);
}
