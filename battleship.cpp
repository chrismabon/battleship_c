/* 
 * File:   battleship.cpp
 * Author: mint
 * 
 * Created on November 14, 2014, 12:54 PM
 */

#include "battleship.h"

battleship::battleship()
    : ship()
{
    setSize(4) ;
    setX(0) ;
    setY(0) ;
    setDir(0) ;
    setDmg(0) ;
    setName("Battleship") ;
    setSunk(false) ;
}

battleship::~battleship()
{
    ;
}
