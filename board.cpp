#ifndef BOARD_CPP
#define BOARD_CPP

#include "board.h"
#include <unistd.h>
#include <iostream>
#include <curses.h>

board::board() 
{
    player = 0 ;
    ships = 0 ;
    boardArray  = new std::array<std::array<char, ROWS_GLOBAL>, COLS_GLOBAL> ;
}
board::board(int pPlayer) 
{
    player = pPlayer ;
    ships = 0 ;
    boardArray  = new std::array<std::array<char, ROWS_GLOBAL>, COLS_GLOBAL> ;
}
board::~board()
{
    delete[] boardArray ;
}

void board::setPlayer(int pPlayer) 
{
    player = pPlayer ;
}
void board::setShips(int pShips) 
{
    ships = pShips ;
}
int board::getPlayer() const
{
    return player ;
}
int board::getShips() const 
{
    return ships ;
}


void board::initBoard() 
{
    int i, j ;
    
    for(i = 0; i < COLS_GLOBAL; i++)
    {
        for(j = 0; j < ROWS_GLOBAL; j++)
        {
            (*boardArray)[i][j] = '\000' ;
        }
    }
}
bool board::markBoard(int pCol, int pRow, char pMark) 
{
    bool retval ;
    
    if((*boardArray)[pCol][pRow] != '_')
    {
        retval = false ;
    }
    else
    {
        (*boardArray)[pCol][pRow] = pMark ;
        retval = true ;
    }
    
    return retval ;
}

void board::printBoard() const
{
    int i, j ;
    
    clear() ;
    printw("-----------------------------------------\n") ;
    
    for(i = 0; i < COLS_GLOBAL; i++)
    {
        printw("| ") ;
        for(j = 0; j < ROWS_GLOBAL; j++)
        {
            if(j < ROWS_GLOBAL)
            {
                addch((*boardArray)[i][j]) ;
                printw(" | ") ;
                refresh() ;
            }
        }
        refresh() ;
        printw("\n") ;
        
        if(i < COLS_GLOBAL)
        {
            printw("-----------------------------------------\n") ;
        }
        refresh() ;
    }
        
    printw("\n") ;
    refresh() ;
}

void board::initBlankBoard()
{
    srand(time(NULL)) ;
    int i, j ;
    
    for(i = 0; i < COLS_GLOBAL; i++)
    {
        for(j = 0; j < ROWS_GLOBAL; j++)
        {
            (*boardArray)[i][j] = '_' ;
        }
    }
}

char board::checkElement(int pRow, int pCol) const
{
    return (*boardArray)[pRow][pCol] ;
}

void board::setElement(int pRow, int pCol, char pChar)
{
    if((pRow <= 9) && (pRow >= 0))
    {
        if((pCol <= 9) && (pRow >= 0))
        {
            (*boardArray)[pRow][pCol] = pChar ;
        }
    }
    else
    {
        ; // do nothing
    }
}

void board::copyBoard(board* pBoard) const
{
    for(int i = 0; i < ROWS_GLOBAL; i++)
    {
        for(int j = 0; j < COLS_GLOBAL; j++)
        {
            pBoard->setElement(i, j, (*boardArray)[i][j]) ;
        }
    }
}

char board::setPeg(peg* pPeg)
{
    int tempX = pPeg->getX() ;
    int tempY = pPeg->getY() ;
    char retChar ;
    
    if((tempX >= 0) && (tempX <= 9))
    {
        if((tempY >= 0) && (tempY <= 9))
        {
            if((*boardArray)[tempY][tempX] == '_')
            {
                retChar = 'O' ; 
                (*boardArray)[tempY][tempX] = 'O' ;
            }
            else if((*boardArray)[tempY][tempX] != '_')
            {
                retChar = (*boardArray)[tempY][tempX] ; // returns the letter of the ship hit
                (*boardArray)[tempY][tempX] = 'X' ; // marks as hit
                pPeg->setColor(true) ;
            }
        }
    }
    
    return retChar ;
}
void board::printTwoBoards(board* otherBoard) const 
{
    int i, j ;
    
    clear() ;
    printw("-----------------------------------------\n") ;
    printw("     ") ;
    printw("-----------------------------------------\n") ;
    
    for(i = 0; i < COLS_GLOBAL; i++)
    {
        printw("| ") ;
        for(j = 0; j < ROWS_GLOBAL; j++)
        {
            if(j < ROWS_GLOBAL)
            {
                addch((*boardArray)[i][j]) ;
                printw(" | ") ;
                refresh() ;
            }
        }
        printw("     ") ;
        for(j = 0; j < ROWS_GLOBAL; j++)
        {
            if(j < ROWS_GLOBAL)
            {
                addch(otherBoard->checkElement(i, j)) ;
                printw(" | ") ;
                refresh() ;
            }
        }
        
        refresh() ;
        printw("\n") ;
        
        if(i < COLS_GLOBAL)
        {
            printw("-----------------------------------------\n") ;
            printw("     ") ;
            printw("-----------------------------------------\n") ;
        }
        refresh() ;
    }
        
    printw("\n") ;
    refresh() ;
}
#endif	/* BOARD_CPP */