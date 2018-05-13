#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Map.h"

using namespace std;


/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
class Robot
{
private:
    Coordinate coordinate;
    const string name;
    int dust_bin;
    
public:
    
    // #################### Class methods ####################
    
    /**
     * function that prints robot location
     */
    inline void printLoc()
    {
        cout << "Robot: " << this->name;
        coordinate.print();
    }

    /**
     * function that prints cleaning message for a certain robot
     */
    inline void printClean()
    {
        cout << "Robot: " << this->name << " is cleaning";
        coordinate.print();
        cout << "dust bin: " << dust_bin << endl;
    }
};

#endif
