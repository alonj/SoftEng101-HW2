#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using std::string;

/** Add a dirt to the map, meaning place 1 at x,y location
 * @param x: x coordinate
 * @param y: y coordinate
 */
void addDirt(const int x, const int y);

/**
 * Clean dirt in the specified coordinates (i.e change value of cell to 0)
 * @param x : x coordinate
 * @param y : y coordinate
 */
void cleanDirt(const int x, const int y);

/**
 * Check if x,y coordinates are valid. valid - if the coordinates in the map is in the map limits.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if the if coordinates are valid, false otherwise.
 */
bool inMapLimit (int x, int y);


/**
 * Get clean/dirty status of cell in parameter coordinates.
 * @param x: x coordinate
 * @param y : y coordinate
 * @return : 0 if the cell is clean, 1 if dirty.
 */
int getCellStatus(int x, int y);

/**
 * Print map status for debugging.
 * for each cell:
 * 0 if clean (c if also at least 1 robot on cell)
 * 1 if dirty (d if also at least 1 robot on cell)
 */
void printMap();
#endif