/* 
 * File:   viewer.cpp
 * Author: mint
 * 
 * Created on December 3, 2014, 3:08 PM
 */

#include "viewer.h"
#include <unistd.h>
#include <curses.h>

viewer::viewer() 
{
    ;
}
viewer::~viewer() 
{
    ;
}

void viewer::menu(bool &pDone, controller* pController) 
{
    clear() ;
    addstr("Please make a selection...\n") ;
    addstr("Press H for help, Q to quit, G for instructions on using the program...\n") ;
    addstr("Press P to play against the computer...\n") ;
    refresh() ;
    
    char sel = getInput() ;
    
    switch(sel)
    {
        case 'Q':
            clear() ;
            addstr("Goodbye!") ;
            refresh() ;
            pDone = true ;
            break ;
        case 'H':
            displayHelp() ;
            break ;
        case 'G':
            displayProgHelp() ;
            break ;
        case 'P':
            pController->playerVsComp() ;
            break ;
    }
}
char viewer::getInput() 
{
    char retval ;
    bool isValid = false ;    
    
    while(!isValid)
    {
        retval = getch() ;
        getch() ;

        switch(retval)
        {
            case 'Q':
            case 'q':
                retval = 'Q' ;
                isValid = true ;
                break ;
            case 'H':
            case 'h':
                retval = 'H' ;
                isValid = true ;
                break ;
            case 'G':
            case 'g':
                retval = 'G' ;
                isValid = true ;
                break ;
            case 'P':
            case 'p':
                retval = 'P' ;
                isValid = true ;
                break ;
            default:
                addstr("Please make a valid selection.") ;
                isValid = false ;    
        }
    }
    
    return retval ;
}

void viewer::displayHelp()
{
    clear() ;
    addstr("-=| Please see http://www.hasbro.com/common/instruct/battleship.pdf \n") ;
    addstr("for full instructions. |=-\n") ;
    addstr("The objective of the game is to sink the opponent's 5 ships: \n") ;
    addstr("Carrier: 5 pegs, Battleship: 4 pegs, Cruiser: 3, Submarine: 3, and Destroyer: 2.\n") ;
    addstr("Each player takes a turn choosing a spot on the opponent player's board \n") ;
    addstr("to mark as a shot, and the game reports a miss or a hit, along with \n") ;
    addstr("the type of target hit.") ;
    refresh() ;
    sleep(1) ;
    addstr("Hit any key to continue...") ;
    refresh() ;
    getch() ;
}
void viewer::displayProgHelp()
{
    clear() ;
    addstr("The board is printed and updated after each turn.\n") ;
    addstr("You will have an opportunity to either place your own ships or \n");
    addstr("have them placed for you in a random pattern.\n") ;
    refresh() ;
    sleep(1) ;
    addstr("Hit any key to continue...") ;
    refresh() ;
    getch() ;
    
    addstr("\nUse the arrow keys to move the marker where you want to fire the shot.") ;
    addstr("\nHit enter when you have selected your target.") ;
    refresh() ;
    sleep(1) ;
    addstr("\nPress any key when ready...") ;
    refresh() ;
    getch() ;
    getch() ;
}