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
        ppGrid[coord.getX()][coord.getY()] = DIRT;
}

void Map::cleanDirt(const Coordinate &coord)
{
    if (inMapLimit(coord))
        ppGrid[coord.getX()][coord.getY()] = PATH;
}

void Map::addWall(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    if (inMapLimit(coord))
        ppGrid[x][y] = WALL;
    else if (x >= 0 && y >= 0)
    {
        int newHeight = size_h + max((x - size_h), 0);
        int newWidth = size_w + max((y - size_w), 0);
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
            ppGrid[x][y] = PATH;
    }
    else if (x >= 0 && y >= 0)
    {
        int newHeight = size_h + max((x + 1 - size_h), 0);
        int newWidth = size_w + max((y + 1 - size_w), 0);
        increaseMapDimension(newHeight, newWidth);
        ppGrid[x][y] = PATH;
    }
}

bool Map::inMapLimit(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < size_h && y >= 0 && y < size_w;
}

void Map::increaseMapDimension(int newHeight, int newWidth)
{
    if (newHeight > size_h) // if height changes, allocate more rows
        ppGrid = static_cast<grid_type>(realloc(ppGrid, newHeight * sizeof(size_type *)));
    for (int i = 0; i < newHeight; i++)
    {
        if (i < size_h)
        { // in "old" rows,
            if (newWidth > size_w)
            { // if width changes, allocate more columns
                ppGrid[i] = static_cast<int *>(realloc(ppGrid[i], newWidth * sizeof(size_type)));
                for (int j = size_w; j < newWidth; j++) // populate new columns with walls
                    ppGrid[i][j] = WALL;
            }
        }
        else
        { // in "new" rows,
            ppGrid[i] = new size_type[newWidth]; // create a new row
            for (int j = 0; j < newWidth; j++) // populate new row with walls
                ppGrid[i][j] = WALL;
        }
    }
    size_h = newHeight; // update height, width attributes
    size_w = newWidth;
}

CellType Map::getCellStatus(const Coordinate &coord)
{
    int x = coord.getX();
    int y = coord.getY();
    int cellValue = ppGrid[x][y];
    if (cellValue == 0) return PATH;
    else if (cellValue == 1) return WALL;
    else if (cellValue == 2) return DIRT;
    else return UNDEFINED;
}

int Map::getMap_h() const
{
    return size_h;
}

int Map::getMap_w() const
{
    return size_w;
}

Map::~Map()
{
    for(int i = 0; i < size_h; i++)
        delete ppGrid[i];
    delete ppGrid;
}

//########################################################################################