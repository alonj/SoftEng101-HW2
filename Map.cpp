#include <iostream>
#include "Map.h"
#include <string>
#include "RobotDB.h"

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

/**
 * Module enables actions and checks on the map itself.
 */

using namespace std;

int gmap [S_HIGH][S_WIDTH] =
{
{ 0 , 1 , 1 , 1 , 1 , 1 , 1},
{ 1 , 0 , 0 , 0 , 1 , 0 , 1},
{ 0 , 0 , 1 , 1 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 1 , 1 , 0 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 0 , 1 , 1 , 1 , 1 , 1}
} ;

/**
 * ###################### Module functions ######################
 */

void addDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
        gmap[x][y]=1;
}

void cleanDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
        gmap[x][y]=0;
}

//########################################################################################

bool inMapLimit (const int x, const int y)
{
    return x >= 0 && x < S_HIGH && y >= 0 && y < S_WIDTH;
}

int getCellStatus(int x, int y){return gmap[x][y];}

void printMap(){
    cout<<"Current Map Status:"<<endl;
    for(int i = 0; i < S_HIGH; i ++){
        for(int j = 0; j < S_WIDTH ; j++){
            if(dbExistInCoords(i, j) && gmap[i][j] == 1) cout<<'d';
            else if(dbExistInCoords(i, j)) cout<<'c';
            else cout<<gmap[i][j];
        }
        cout<<endl;
    }
}