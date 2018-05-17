//
// Created by alonj on 5/13/18.
//

#include "Map.h"
#include <algorithm>

using namespace std;

/**
 * ###################### Module functions ######################
 */

void Map::addDirt(const Coordinate& coord){
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()] = 2;
}

void Map::cleanDirt(const Coordinate& coord)
{
    if (inMapLimit(coord))
        gmap[coord.getX()*map_w + coord.getY()] = 0;
}

void Map::addWall(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        gmap[x][y] = 1;
    else if(x >=0 && y >= 0){
        int newHeight = map_h + std::max((x-map_h),0);
        int newWidth = map_w + std::max((y-map_w),0);
        increaseMapDimension(newHeight, newWidth);
    }
}

void Map::addPath(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord)){
        if (getCellStatus(coord) != WALL) // don't do anything if cell is not a wall
            return;
        else
            gmap[x*map_w + y]=0;
    }
    else if(x >= 0 && y >= 0){
        int newHeight = map_h + std::max((x+1-map_h),0);
        int newWidth = map_w + std::max((y+1-map_w),0);
        increaseMapDimension(newHeight, newWidth);
        gmap[x][y] = PATH;
    }
}

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < map_h && y >= 0 && y < map_w;
}

void Map::increaseMapDimension(int newHeight, int newWidth) {
    if(newHeight > map_h) // if height changes, allocate more rows
        gmap = static_cast<grid_type>(realloc(gmap, newHeight * sizeof(size_type*)));
    for(int i = 0; i < newHeight; i++) {
        if(i < map_h){ // in "old" rows,
            if(newWidth > map_w){ // if width changes, allocate more columns
                gmap[i] = static_cast<int *>(realloc(gmap[i], newWidth * sizeof(size_type)));
                for(int j = map_w; j < newWidth; j++) // populate new columns with walls
                    gmap[i][j] = WALL;
            }
        }
        else{ // in "new" rows,
            gmap[i] = new size_type[newWidth]; // create a new row
            for(int j = 0; j < newWidth; j++) // populate new row with walls
                gmap[i][j] = WALL;
        }
    }
    map_h = newHeight; // update height, width attributes
    map_w = newWidth;
}

cell_type Map::getCellStatus(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    int numeric_status = gmap[x][y];
    if(numeric_status == 0) return PATH;
    else if (numeric_status == 1) return WALL;
    else if (numeric_status == 2) return DIRT;
}

int Map::getMap_h() const {
    return map_h;
}

int Map::getMap_w() const {
    return map_w;
}

//########################################################################################