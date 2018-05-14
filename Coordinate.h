#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

//The coordinate class role is to hold the X&Y coordinates for a certain robot.
class Coordinate
{
private:
    int x;
    int y;
    
public:
    //Constructors
    Coordinate(int new_x, int new_y): x(new_x), y(new_y) { } //Default constructor
    Coordinate(const Coordinate& new_coordinate): x(new_coordinate.x), y(new_coordinate.y) { } // Copy constructor

    //Destructor
    ~Coordinate(){}
    
    //Member functions
    inline void print()
    {  
           std::cout << " at: " << x << "," << y << std::endl;  
    };

    bool operator==(const Coordinate &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool operator!=(const Coordinate &rhs) const {
        return !(rhs == *this);
    }

    inline int getX() const {
        return x;
    }

    inline int getY() const {
        return y;
    }

    inline void setX(int x) {
        Coordinate::x = x;
    }

    inline void setY(int y) {
        Coordinate::y = y;
    }

    inline bool outOfBounds() const {
        return x<0 && y<0;
    }

};   

#endif 
