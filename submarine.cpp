/* 
 * File:   submarine.cpp
 * Author: mint
 * 
 * Created on November 14, 2014, 12:56 PM
 */

#include "submarine.h"

submarine::submarine()
    : ship()
{
    setSize(3) ;
    setX(0) ;
    setY(0) ;
    setDir(0) ;
    setDmg(0) ;
    setName("Submarine") ;
    setSunk(false) ;
}

submarine::~submarine()
{
    ;
}
