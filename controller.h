/* 
 * File:   controller.h
 * Author: Chris Mabon
 * Prof. M. Penta
 * Created on November 13, 2014, 6:53 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "board.h"
#include "player.h"
#include "locDirNode.h"
#include <list>
#include "coordList.h"

class controller
{
public:
    controller() ;
    virtual ~controller() ;
    
    void placeShip(ship* pShip, board* pBoard, int pX, int pY) ; // places a ship on the provided board,
    // at the provided coordinates in the 2d array
    void randPlaceShips(ship** pShips, board* pBoard) ; // takes a pointer to an array of ships and board,
    // randomly places ships in open spots based on the size and orientation of each ship
    void promptPlaceShips(ship** pShips, board* pBoard, player* pPlayer) ; // prompts the given player
    // to place his/her ships using the arrow keys and visual feedback
    bool playerVsComp() ; // main function for player versus computer
    char promptPlaceShot(player* pPlayer, board* playerShots, board* compSelf) ; // prompts the user to pick a spot to fire on
    char placeShot(player* defensePlayer, peg* pPeg, board* defenseBoard)  ; // places a shot on the board and returns a character
    // of the type hit or an O if no hit
    void setSearching(bool pSearch) ; // sets the state to searching or acquired state
    void changeSearching() ; // flips between states
    
    void changeTurn(int &pPlayer) ; // changes the turn from 1 to 2 and 2 to 1
    int determineWinner(player* humanPlayer, player* compPlayer) ; // counts remaining ships and determines
    // winner based on how many are left
    
    void setX(int pX) ;
    void setY(int pY) ;
    void setDir(int pDir) ;
    void setOrigX(int pX) ;
    void setOrigY(int pY) ;
    
    int getX() const ;
    int getY() const ;
    int getOrigX() const ;
    int getOrigY() const ;
    int getDir() const ;
    
    void incrementVar(int &pVar) ;
    void incrementDir() ;
    void decrementVar(int &pVar) ;
    
private:
    bool isOpen(ship* pShip, board* pBoard, int pX, int pY) const ; // checks if the space on the board is open
    // to accommodate the given ship in the provided space
    bool checkAdj(ship* pShip, board* pBoard, int pX, int pY) const ; // checks the adjacent spots up to the
    // size of the given ship
    int countTaken(board* pBoard, ship* pShip) const ; // counts the number of taken spaces given the orientation,
    // size, and location of the ship on the board
    bool markBoard(board* pBoard, ship* pShip, int pX, int pY) ; // calls mark char for the given ship
    // on the provided board, returns failure(false) or success (true)
    void markChar(board* pBoard, ship* pShip, int pX, int pY) ; // places marks on the board representing
    // the given ship in the provided location
    void randomPlace(ship* pShip, int &pX, int &pY) ; // randomizes X and Y to an integer 0-9
    void computerAi(board* compShots, board* pSelf, player* humanPlayer, player* compPlayer) ; // chooses a random spot to fire on, if a hit then fires up, down, left, right
    // until another hit is attained, then it fires in that direction until ship is sunk
    void initPlayersAndBoards(player* humanPlayer, player* compPlayer) ;
    
    
    bool searching ; // if true, computer fires random shots
    int lastX ; // last shot location
    int lastY ;
    int direction ; // direction the AI is working in
    int origX ; // location of original shot that landed a hit
    int origY ;
    int hits ; // number of consecutive hits
    
    std::list<locDirNode>* targetList ;
    std::list<locDirNode>::iterator listIter ; // iterator
};

#endif	/* CONTROLLER_H */

