#ifndef SHIP_CPP
#define	SHIP_CPP

#include "ship.h"
#include <unistd.h>
#include <curses.h>

ship::ship() 
{
    size = 0 ;
    locX = 0 ;
    locY = 0 ;
    direct = RIGHT ;
    damage = 0 ;
    name = "" ;
    isSunk = false ;
}
ship::ship(int pSize, int pX, int pY, int pDir, int pDmg, std::string pName) 
{
    size = pSize ;
    locX = pX ;
    locY = pY ;
    direct = pDir ;
    damage = pDmg ;
    name = pName ;
    isSunk = false ;
}
ship::ship(int pSize, int pX, int pY, int pDir, int pDmg, std::string pName, bool pSunk) 
{
    size = pSize ;
    locX = pX ;
    locY = pY ;
    direct = pDir ;
    damage = pDmg ;
    name = pName ;
    isSunk = pSunk ;
}
ship::~ship()
{
    ;
}
void ship::setSize(int pSize) 
{
    size = pSize ;
}
void ship::setX(int pX) 
{
    locX = pX ;
}
void ship::setY(int pY) 
{
    locY = pY ;
}
void ship::setDir(int pDir) 
{
    direct = pDir ;
}
void ship::setDmg(int pDmg) 
{
    damage = pDmg ;
}
void ship::setName(std::string pName) 
{
    name = pName ;
}
void ship::setSunk(bool pSunk) 
{
    isSunk = pSunk ;
}

int ship::getSize() const 
{
    return size ;
}
int ship::getX() const 
{
    return locX ;
}
int ship::getY() const 
{
    return locY ;
}
int ship::getDir() const 
{
    return direct ;
}
int ship::getDmg() const 
{
    return damage ;
}
std::string ship::getName() const 
{
    return name ;
}
bool ship::getSunk() const 
{
    return isSunk ;
}

void ship::incrementDmg()
{
    damage++ ;
    
    if(damage == size)
    {
        isSunk = true ;
        addstr("Ship sunk! ") ;
    }    
}
void ship::incrementDir()
{
    if(direct == 3)
    {
        direct = 0 ;
    }
    else
    {
        direct++ ;
    }
}
void ship::incrementX()
{
    if(locX == 9)
    {
        locX = 9 ;
    }
    else
    {
        locX++ ;
    }
}
void ship::incrementY()
{
    if(locY == 9)
    {
        locY = 9 ;
    }
    else
    {
        locY++ ;
    }
}

void ship::decrementDir()
{
    if(direct == 0)
    {
        direct = 3 ;
    }
    else
    {
        direct-- ;
    }
}
void ship::decrementX()
{
    if(locX == 0)
    {
        locX = 0 ;
    }
    else
    {
        locX-- ;
    }
}
void ship::decrementY()
{
    if(locY == 0)
    {
        locY = 0 ;
    }
    else
    {
        locY-- ;
    }
}

void ship::printName() const
{
    char* nameArr = new char[15];
    
    for(int i = 0; i < name.length(); i++)
    {
        nameArr[i] = name[i] ;
    }
    addstr(nameArr) ;
}

#endif	/* SHIP_CPP */