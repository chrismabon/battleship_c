/* 
 * File:   cruiser.cpp
 * Author: mint
 * 
 * Created on November 14, 2014, 12:55 PM
 */

#include "cruiser.h"

cruiser::cruiser()
    : ship()
{
    setSize(3) ;
    setX(0) ;
    setY(0) ;
    setDir(0) ;
    setDmg(0) ;
    setName("Cruiser") ;
    setSunk(false) ;
}

cruiser::~cruiser()
{
    ;
}
