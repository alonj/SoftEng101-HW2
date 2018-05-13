//
// Created by alonj on 5/13/18.
//

#ifndef HW2ATTACHEDCODEFILES_ROBOTDB_H
#define HW2ATTACHEDCODEFILES_ROBOTDB_H

#include <vector>
#include "Robot.h"
#include "Map.h"

typedef std::vector<Robot*> RobotVec;
typedef std::vector<Robot*>::iterator RobotVec_it;
typedef std::vector<Robot*>::const_iterator RobotVec_cit;


class RobotDB {
private:
    RobotVec robots;
    Map* map;
    unsigned robotCount;
    Coordinate getRobotCoords(string &rname);
    int getRobotIndex(const string &rname);
public:
    explicit RobotDB(Map *new_map){  map = new_map;
                            robotCount = 0; };
    ~RobotDB() = default;
    void DeleteRobot(const std::string& rname);
    bool AddRobot(string rname, Coordinate robotCoor);
    void MoveRobot(string rname, string direction);
    bool ExistsInCoord(Coordinate &coord);

};


#endif //HW2ATTACHEDCODEFILES_ROBOTDB_H
