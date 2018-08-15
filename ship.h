/* 
 * File:   ship.h
 * Author: Chris Mabon
 * Prof. M. Penta
 * Created on November 13, 2014, 5:24 PM
 */

#ifndef SHIP_H
#define	SHIP_H

#include <string>

enum directions {UP = 0, DOWN = 1, LEFT = 2 , RIGHT = 3} ;

class ship 
{
public:
    ship();
    ship(int pSize, int pX, int pY, int pDir, int pDmg, std::string pName, bool pSunk);
    ship(int pSize, int pX, int pY, int pDir, int pDmg, std::string pName) ;
    virtual ~ship() ;
    
    void setSize(int pSize) ; // getters
    void setX(int pX) ;
    void setY(int pY) ;
    void setDir(int pDir) ;
    void setDmg(int pDmg) ;
    void setName(std::string pName) ;
    void setSunk(bool pSunk) ;
    
    int getSize() const ; // setters
    int getX() const ;
    int getY() const ;
    int getDir() const ;
    int getDmg() const ;
    std::string getName() const ;
    bool getSunk() const ;
    
    void incrementDmg() ; // increments damage by 1 to given ship
    void incrementDir() ; // changes direction in this order: DOWN, LEFT, RIGHT, UP
    void incrementX() ; // moves the ship to the right
    void incrementY() ; // moves the ship down
    
    void decrementDir() ; // changes the direction in this order: UP, RIGHT, LEFT, DOWN
    void decrementX() ; // moves the ship to the left
    void decrementY() ; // moves the ship up
    
    void printName() const ; // prints the name of the ship (ie, "Battleship", "Destroyer", etc.)
    
private:
    int size ; // number of pegs taken up on board
    int locX ; // location X
    int locY ; // location Y
    int direct ; // direction
    int damage ; // amount of damage taken
    std::string name ; // ship name
    bool isSunk ; // is still counted as alive
};

#endif	/* SHIP_H */

