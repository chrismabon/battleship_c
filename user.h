/* 
 * File:   computer.h
 * Author: Chris Mabon
 * Prof. M. Penta
 * Created on November 14, 2014, 8:21 AM
 */

#ifndef USER_H
#define	USER_H

#include "ships.h"
#include <string>
#include <cstdlib>

static constexpr int NUM_SHIPS = 5 ;

class user
{
public:
    user() ;
    user(std::string pName) ;
    user(std::string pName, int pId) ;
    virtual ~user() ;
    
    void setName(std::string pName) ; // setters
    void setId(int pId) ;
    
    std::string getName() const ; // getters
    int getId() const ;
    ship* getShip(int pIndex) const ; // returns the ship at the given index
    ship** getShips() ; // returns the entire ship array belonging to the user
    
protected:
    ship* compShips[NUM_SHIPS] ; // array of ships used by the player
    std::string name ; // name of the player
    int id ; // unique id (human = 1, computer = 2)
};

#endif	/* USER_H */
