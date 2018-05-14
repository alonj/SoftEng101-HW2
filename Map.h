//
// Created by alonj on 5/13/18.
//

#ifndef HW2ATTACHEDCODEFILES_MAP_H
#define HW2ATTACHEDCODEFILES_MAP_H

#include <iostream>
#include <string>
#include "Coordinate.h"

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

using std::string;

typedef int size_type;
typedef int** grid_type;

int gmap [S_HIGH][S_WIDTH] =
        {
                { 0 , 1 , 1 , 1 , 1 , 1 , 1},
                { 1 , 2 , 2 , 0 , 1 , 0 , 1},
                { 0 , 0 , 1 , 1 , 1 , 2 , 1},
                { 1 , 0 , 0 , 0 , 0 , 0 , 1},
                { 1 , 1 , 1 , 2 , 1 , 0 , 1},
                { 1 , 0 , 0 , 0 , 0 , 2 , 1},
                { 1 , 0 , 1 , 1 , 1 , 1 , 1}
        } ;

class Map {
private:
    int* amap;
    int map_h;
    int map_w;
public:
/** Constructor defaults to gmap as outlines in the HW instructions
 * map width/height default to S_WIDTH, S_HIGH (respectively)
 */
    Map(){  amap = *gmap;
            map_h = S_HIGH;
            map_w = S_WIDTH;};

/** Add a wall to the map in the given coordinate
 * @param coord : given coordinate
 */
    void addWall(const Coordinate& coord);

    /** Add a clean path to the map in the given coordinate. if coordinate > 0,0 and outside map, increases map size
 * @param coord : given coordinate
 */
    void addPath(const Coordinate& coord);

/** Add a dirt to the map, meaning place 1 at x,y location. if coordinate > 0,0 and outside map, increases map size
 * @param coord: coordinate to add wall in
 */
    void addDirt(const Coordinate& coord);

/**
 * Clean dirt in the specified coordinates (i.e change value of cell to 0)
 * @param coord : coordinate to clean dirt in
 */
    void cleanDirt(const Coordinate& coord);

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
    inline int getCellStatus(Coordinate& coord){return gmap[coord.getX()][coord.getY()];};


    /**
     * Function copies the map into a map with dimensions set by newHeight, newWidth, and replaces the old one.
     * defaults new cells to 1 (walls)
     * @param newHeight : the new map's height
     * @param newWidth ; the new map's width
     */
    void increaseMapDimension(int newHeight, int newWidth);
};


#endif //HW2ATTACHEDCODEFILES_MAP_H