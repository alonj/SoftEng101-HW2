//
// Created by alonj on 18-Apr-18.
//

#ifndef HW1ATTACHEDCODEFILES_ROBOTDB_H
#define HW1ATTACHEDCODEFILES_ROBOTDB_H

#include <vector>
#include <string>

using namespace std;

/**
 * Change position of selected (existing) robot
 * @param robotID : name of selected robot.
 * @param direction : direction of movement.
 */
void dbMove(string &robotID, string &direction);

/**
 * Place a new robot on the map.
 * @param robotID : name of new robot.
 * @param posX : x-coordinate position of robot.
 * @param posY : y-coordinate position of robot.
 * @return : false if placed in illegal coordinates (i.e failed placement), true otherwise.
 */
bool dbPlace(string &robotID, int &posX, int &posY);

/**
 * Clean cell where the selected robot is at.
 * @param robotID : name of robot to clean cell at.
 */
void dbClean(string &robotID);

/**
 * Delete existing robot.
 * @param robotID : name of robot for deletion.
 */
void dbDelete(string &robotID);

/**
 * Check if a robot is currently in given coordinates.
 * @param posX : Coordinate X.
 * @param posY : Coordinate Y.
 * @return : True if robot exists there.
 */
bool dbExistInCoords(int &posX, int &posY);

/**
 * Check if selected robot is within map limits.
 * @param robotID : Robot to check.
 * @return : True if robot is in valid coordinates.
 */
bool dbRobotInMap(string &robotID);

/**
 * Get the coordinates of selected robot.
 * @param robotID : Name of selected robot.
 * @param type : either 'x' or 'y', for coordinates x and y, respectively.
 * @return : Coordinate value x or y.
 */
int dbGetRobotPos(string &robotID, char type);

#endif //HW1ATTACHEDCODEFILES_ROBOTDB_H
