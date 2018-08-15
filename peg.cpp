/* 
 * File:   peg.cpp
 * Author: mint
 * 
 * Created on December 3, 2014, 4:24 PM
 */

#include "peg.h"

peg::peg() 
{
    x = 5 ;
    y = 5 ;
    isRed = false ;
}
peg::peg(int pX, int pY, bool pIsRed) 
{
    x = pX ;
    y = pY ;
    isRed = pIsRed ;
}
peg::~peg() 
{
    ;
}

int peg::getX() const 
{
    return x ;
}
int peg::getY() const 
{
    return y ;
}
bool peg::getColor() const 
{
    return isRed ;
}
    
void peg::setX(int pX) 
{
    x = pX ;
}
void peg::setY(int pY) 
{
    y = pY ;
}
void peg::setColor(bool pColor) 
{
    isRed = pColor ;
}
    
void peg::incrementX() 
{
    if(x == 9)
    {
        ;
    }
    else
    {
        x++ ;
    }
}
void peg::incrementY() 
{
    if(y == 9)
    {
        ;
    }
    else
    {
        y++ ;
    }
}
void peg::decrementX()
{
    if(x == 0)
    {
        ;
    }
    else
    {
        x-- ;
    }
}
void peg::decrementY()
{
    if(y == 0)
    {
        ;
    }
    else
    {
        y-- ;
    }
}