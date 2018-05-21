//
// Created by alonj on 5/13/18.
//

#include "Map.h"
#include <algorithm>

using namespace std;

/**
 * ###################### Module functions ######################
 */

void Map::addDirt(const Coordinate &coord)
{
    if (inMapLimit(coord))
        _gmap[coord.getX()][coord.getY()] = DIRT;
}

void Map::cleanDirt(const Coordinate &coord)
{
    if (inMapLimit(coord))
        _gmap[coord.getX()][coord.getY()] = PATH;
}

void Map::addWall(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        _gmap[x][y] = WALL;
    else if (x >= 0 && y >= 0)
    {
        int newHeight = _mapHeight + max((x - _mapHeight), 0);
        int newWidth = _mapWidth + max((y - _mapWidth), 0);
        increaseMapDimension(newHeight, newWidth);
    }
}

void Map::addPath(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
    {
        if (getCellStatus(coord) != WALL) // don't do anything if cell is not a wall
            return;
        else
            _gmap[x][y] = PATH;
    }
    else if (x >= 0 && y >= 0)
    {
        int newHeight = _mapHeight + max((x + 1 - _mapHeight), 0);
        int newWidth = _mapWidth + max((y + 1 - _mapWidth), 0);
        increaseMapDimension(newHeight, newWidth);
        _gmap[x][y] = PATH;
    }
}

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < _mapHeight && y >= 0 && y < _mapWidth;
}

void Map::increaseMapDimension(int newHeight, int newWidth)
{
    if (newHeight > _mapHeight) // if height changes, allocate more rows
        _gmap = static_cast<grid_type>(realloc(_gmap, newHeight * sizeof(size_type *)));
    for (int i = 0; i < newHeight; i++)
    {
        if (i < _mapHeight)
        { // in "old" rows,
            if (newWidth > _mapWidth)
            { // if width changes, allocate more columns
                _gmap[i] = static_cast<int *>(realloc(_gmap[i], newWidth * sizeof(size_type)));
                for (int j = _mapWidth; j < newWidth; j++) // populate new columns with walls
                    _gmap[i][j] = WALL;
            }
        }
        else
        { // in "new" rows,
            _gmap[i] = new size_type[newWidth]; // create a new row
            for (int j = 0; j < newWidth; j++) // populate new row with walls
                _gmap[i][j] = WALL;
        }
    }
    _mapHeight = newHeight; // update height, width attributes
    _mapWidth = newWidth;
}

CellType Map::getCellStatus(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    int cellValue = _gmap[x][y];
    if (cellValue == 0) return PATH;
    else if (cellValue == 1) return WALL;
    else if (cellValue == 2) return DIRT;
}

int Map::getMap_h() const
{
    return _mapHeight;
}

int Map::getMap_w() const
{
    return _mapWidth;
}

//########################################################################################