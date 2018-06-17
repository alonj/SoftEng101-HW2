#include <cstdlib>
#include <iostream>

#include "includes/Interface.h"
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