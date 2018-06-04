#include <cstdlib>
#include <iostream>

#include "includes/Interface.h" // TODO move all files to single directory
#include "includes/RobotDB.h"
#include "includes/Map.h"


int main(int argc, char *argv[])
{
    Map* map = new Map();
    RobotDB* pRobots = new RobotDB(map);
    Interface control(pRobots);

    control.StartControl(map);

    delete pRobots;
    delete map;

    return EXIT_SUCCESS;
}