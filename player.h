/* 
 * File:   player.h
 * Author: mint
 *
 * Created on November 16, 2014, 10:38 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "user.h"
#include "board.h"

class player 
    : public user
{
public:
    player() ;
    player(std::string pName, int pId) ;
    virtual ~player() ;
    
    board* getSelf() const ;
    board* getShots() const ;
    
    void initShips() ;
    
    
protected:
    board* self ; // contains a board for the self (ships, opponent shots)
    board* shots ; // board for shots (opponent ships, player shots)
};

#endif	/* PLAYER_H */

