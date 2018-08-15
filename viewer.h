/* 
 * File:   viewer.h
 * Author: mint
 *
 * Created on December 3, 2014, 3:08 PM
 */

#ifndef VIEWER_H
#define	VIEWER_H

#include "controller.h"

class viewer 
{
public:
    viewer();
    virtual ~viewer();
    
    void menu(bool &pDone, controller* pController) ; // takes
    // a sentinel &bool, a board*, a player*, and a controller* and continues until bool is true
    char getInput() ; // tests the input and puts in canonical form (uppercase)
    void displayHelp() ; // displays the game help for Battleship and link to 
    // official instructions
    void displayProgHelp() ; // displays help on how to use the program
 
};

#endif	/* VIEWER_H */

