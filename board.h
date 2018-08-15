/* 
 * File:   board.h
 * Author: Chris Mabon
 * Prof. M. Penta
 * Created on November 13, 2014, 4:09 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include <cstdlib>
#include <array>
#include <cmath>
#include <ctime>
#include "peg.h"


constexpr unsigned int ROWS_GLOBAL = 10;
constexpr unsigned int COLS_GLOBAL = 10;


class board {
public:
    board();
    board(int player);
    virtual ~board() ;

    
    void setPlayer(int) ;
    void setShips(int) ;
    int getPlayer() const ;
    int getShips() const ;
    void setElement(int pRow, int pCol, char pChar) ; // sets the given element 
    // in the boardArray to the specified character
    char setPeg(peg* pPeg) ; // draws the peg on the board
    
    void initBoard() ; // initialize board with non-printing characters
    bool markBoard(int pCol, int pRow, char pMark) ; // change the given element
    // to the character specified
    void printBoard() const ; // prints the board
    void initBlankBoard() ; // initializes board with the underscore (_) character
    char checkElement(int pRow, int pCol) const ; // returns the char value of the given element
    void copyBoard(board* pBoard) const ; // returns a pointer to a copy of the current object
    void printTwoBoards(board* otherBoard) const ;
    
protected:
    int player; // player ID
    int ships ; // number of ships remaining
    std::array<std::array<char, ROWS_GLOBAL>, COLS_GLOBAL>* boardArray ; // the 2D array board
};

#endif	/* BOARD_H */

