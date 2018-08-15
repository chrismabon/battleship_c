/* 
 * File:   destroyer.cpp
 * Author: mint
 * 
 * Created on November 14, 2014, 12:57 PM
 */

#include "destroyer.h"

destroyer::destroyer()
    : ship()
{
    setSize(2) ;
    setX(0) ;
    setY(0) ;
    setDir(0) ;
    setDmg(0) ;
    setName("Destroyer") ;
    setSunk(false) ;
}

destroyer::~destroyer()
{
    ;
}
