//
// Created by alonj on 5/13/18.
//

#include "Map.h"

using namespace std;

/**
 * ###################### Module functions ######################
 */

void Map::addDirt(const Coordinate& coord){
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()]=2;
}

void Map::cleanDirt(const Coordinate& coord)
{
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()]=0;
}

void Map::addWall(const Coordinate &coord) {
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()]=1;
}

void Map::addPath(const Coordinate &coord) { // TODO what if map size changes? i.e "NOT inMapLimit"
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()]=0;
}


//########################################################################################

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < S_HIGH && y >= 0 && y < S_WIDTH;
}

