/* 
 * File:   player.cpp
 * Author: mint
 * 
 * Created on November 16, 2014, 10:38 AM
 */

#include "player.h"

player::player() 
    : user()
{
    name = "Human Player" ;
    id = 1 ;
    self =  new board() ;
    shots = new board() ;
}
player::player(std::string pName, int pId)
    : user(pName, pId)
{
    name = pName ;
    id = pId ;
    self =  new board() ;
    shots = new board() ;
}
player::~player()
{
    delete[] self ;
    delete[] shots ;
    self = NULL ;
    shots = NULL ;
}

board* player::getSelf() const
{
    return self ;
}
board* player::getShots() const
{
    return shots ;
}

void player::initShips()
{
    compShips[0] = new carrier() ;
    compShips[1] = new battleship() ;
    compShips[2] = new cruiser() ;
    compShips[3] = new submarine() ;
    compShips[4] = new destroyer() ;
}
