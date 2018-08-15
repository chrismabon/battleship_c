/* 
 * File:   carrier.cpp
 * Author: mint
 * 
 * Created on November 14, 2014, 12:47 PM
 */

#include "carrier.h"

carrier::carrier()
    : ship()
{
    setSize(5) ;
    setX(0) ;
    setY(0) ;
    setDir(0) ;
    setDmg(0) ;
    setName("Carrier") ;
    setSunk(false) ;
}

carrier::~carrier()
{
    ;
}