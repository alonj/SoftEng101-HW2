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
        gmap[coord.getX()][coord.getY()] = DIRT;
}

void Map::cleanDirt(const Coordinate& coord)
{
    if (inMapLimit(coord))
        gmap[coord.getX()][coord.getY()] = PATH;
}

void Map::addWall(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        gmap[x][y] = WALL;
    else if(x >=0 && y >= 0){
        int newHeight = mapHeight + max((x-mapHeight),0);
        int newWidth = mapWidth + max((y-mapWidth),0);
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
            gmap[x][y]=PATH;
    }
    else if(x >= 0 && y >= 0){
        int newHeight = mapHeight + max((x+1-mapHeight),0);
        int newWidth = mapWidth + max((y+1-mapWidth),0);
        increaseMapDimension(newHeight, newWidth);
        gmap[x][y] = PATH;
    }
}

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < mapHeight && y >= 0 && y < mapWidth;
}

void Map::increaseMapDimension(int newHeight, int newWidth) {
    if(newHeight > mapHeight) // if height changes, allocate more rows
        gmap = static_cast<grid_type>(realloc(gmap, newHeight * sizeof(size_type*)));
    for(int i = 0; i < newHeight; i++) {
        if(i < mapHeight){ // in "old" rows,
            if(newWidth > mapWidth){ // if width changes, allocate more columns
                gmap[i] = static_cast<int *>(realloc(gmap[i], newWidth * sizeof(size_type)));
                for(int j = mapWidth; j < newWidth; j++) // populate new columns with walls
                    gmap[i][j] = WALL;
            }
        }
        else{ // in "new" rows,
            gmap[i] = new size_type[newWidth]; // create a new row
            for(int j = 0; j < newWidth; j++) // populate new row with walls
                gmap[i][j] = WALL;
        }
    }
    mapHeight = newHeight; // update height, width attributes
    mapWidth = newWidth;
}

CellType Map::getCellStatus(const Coordinate &coord) {
    int x = coord.getX();
    int y = coord.getY();
    int cellValue = gmap[x][y];
    if(cellValue == 0) return PATH;
    else if (cellValue == 1) return WALL;
    else if (cellValue == 2) return DIRT;
}

int Map::getMap_h() const {
    return mapHeight;
}

int Map::getMap_w() const {
    return mapWidth;
}

//########################################################################################