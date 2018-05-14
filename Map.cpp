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
        amap[coord.getX()*map_w + coord.getY()] = 2;
}

void Map::cleanDirt(const Coordinate& coord)
{
    if (inMapLimit(coord))
        amap[coord.getX()*map_w + coord.getY()] = 0;
}

void Map::addWall(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        amap[x*map_w + y] = 1;
    else if(x >=0 && y >= 0){
        int newHeight = map_h + std::max((x-map_h),0);
        int newWidth = map_w + std::max((y-map_w),0);
        increaseMapDimension(newHeight, newWidth);
    }
}

void Map::addPath(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        amap[x*map_w + y]=0;
    else if(x >=0 && y >= 0){
        int newHeight = map_h + std::max((x-map_h),0);
        int newWidth = map_w + std::max((y-map_w),0);
        increaseMapDimension(newHeight, newWidth);
        amap[x*map_w + y] = 0;
    }
}

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < S_HIGH && y >= 0 && y < S_WIDTH;
}

void Map::increaseMapDimension(int newHeight, int newWidth) {
    int* newMap = new int[newHeight*newWidth];
    for (int i = 0; i < map_h; i++) // copy the existing map into the new larger map
        for (int j = 0; j < map_w ; j++)
            newMap[i*map_w + j] = amap[i*map_w + j];
    for (int i = map_h; i < newHeight; i++)  // every new cell is a wall (value = 1)
        for (int j = map_w; j < newWidth; j++)
            newMap[i*map_w + j] = 1;
    amap = newMap; // replace the existing map and its attributes in the object
    map_h = newHeight;
    map_w = newWidth;
}

cell_status Map::getCellStatus(Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    int numeric_status = amap[x*map_w + y];
    switch(numeric_status){
        case 0: return CLEAN;
        case 1: return WALL;
        default: return DIRTY;
    }

}

//########################################################################################