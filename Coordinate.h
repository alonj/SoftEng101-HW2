#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

//The coordinate class role is to hold the X&Y coordinates for a certain robot.
class Coordinate
{
private:
    int _x;
    int _y;

public:
    //Constructors
    Coordinate(int new_x, int new_y) : _x(new_x), _y(new_y){} //Default constructor
    Coordinate(const Coordinate &new_coordinate) : _x(new_coordinate._x), _y(new_coordinate._y){} // Copy constructor

    //Destructor
    ~Coordinate(){}

    //Member functions
    /**
     * function prints out coordinate attributes (x, y values)
     */
    inline void print()
    {
        std::cout << " at: " << _x << "," << _y << std::endl;
    };

    /**
     * equality operator for coordinates (checks if x1 == x2 AND y1 == y2)
     * @param rhs : other coordinate.
     * @return : true if equal
     */
    bool operator==(const Coordinate &rhs) const
    {
        return _x == rhs._x &&
               _y == rhs._y;
    }

    /**
     * inequality operator for coordinates
     * @param rhs : other coordinate.
     * @return : true if equality is false
     */
    bool operator!=(const Coordinate &rhs) const
    {
        return !(rhs == *this);
    }

    /**
     * getter function for x attribute
     * @return : value of x
     */
    inline int getX() const
    {
        return _x;
    }

    /**
     * getter function for y attribute
     * @return : value of y
     */
    inline int getY() const
    {
        return _y;
    }

    /**
     * setter function for x attribute
     * @param x : new x value
     */
    inline void setX(int x)
    {
        Coordinate::_x = x;
    }

    /**
     * setter function for y attribute
     * @param y : new y value
     */
    inline void setY(int y)
    {
        Coordinate::_y = y;
    }

    /**
     * checks if coordinate is absolutely negative (x AND y are negative)
     * @return : true if coordinate is negative
     */
    inline bool outOfBounds() const
    {
        return _x < 0 && _y < 0;
    }

};

#endif 
