//
// Created by alonj on 5/13/18.
//

#ifndef HW2ATTACHEDCODEFILES_MAP_H
#define HW2ATTACHEDCODEFILES_MAP_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Coordinate.h"

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

using std::string;

typedef int size_type;
typedef int** grid_type;
typedef enum {PATH = 0, WALL = 1, UNDEFINED = 3} CellType;

class Map
{
private:
    grid_type ppGrid;
    size_type size_h;
    size_type size_w;
public:
/** Constructor defaults to gmap as outlined in the HW instructions
 * map width/height default to S_WIDTH, S_HIGH (respectively)
 */
    Map() : size_h(S_HIGH), size_w(S_WIDTH) // default constructor
    {
        size_type initGrid[S_HIGH][S_WIDTH] = {
                {0, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 1, 0, 1},
                {0, 0, 1, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 1, 1, 1}
        };
        ppGrid = new size_type *[S_HIGH];
        for(int i = 0; i < S_HIGH; i++)
            ppGrid[i] = new size_type[S_WIDTH];
        for(int i = 0; i < S_HIGH; i++)
            for(int j = 0; j < S_WIDTH; j++)
                ppGrid[i][j] = initGrid[i][j];
    };

    virtual ~Map(); // destructor

/** Add a wall to the map in the given coordinate
 * @param coord : given coordinate
 */
    void addWall(const Coordinate &coord);

    /** Add a clean path to the map in the given coordinate. if coordinate > 0,0 and outside map, increases map size
 * @param coord : given coordinate
 */
    void addPath(const Coordinate &coord);

/**
 * Check if x,y coordinates are valid. valid - if the coordinates in the map is in the map limits.
 * @return: True if the if coordinates are valid, false otherwise.
 */
    bool inMapLimit(const Coordinate &coord);


/**
 * Get clean/dirty status of cell in parameter coordinates.
 * @param coord : coordinate to return status of.
 * @return : 0 if the cell is clean, 1 if wall, 2 if dirty.
 */
    CellType getCellStatus(const Coordinate &coord);

/**
 * Function copies the map into a map with dimensions set by newHeight, newWidth, and replaces the old one.
 * defaults new cells to 1 (walls)
 * @param newHeight : the new map's height
 * @param newWidth ; the new map's width
 */
    void increaseMapDimension(int newHeight, int newWidth);

/**
 * function to get map height
 * @return value of map_h
 */
    int getMap_h() const;

/**
 * function to get map width
 * @return value of map_w
 */
    int getMap_w() const;
};


#endif //HW2ATTACHEDCODEFILES_MAP_H
