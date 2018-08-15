/* 
 * File:   main.cpp
 * Author: Chris Mabon
 * Lab 2 - Battleship
 * Prof. M. Penta
 * Created on November 13, 2014, 4:05 PM
 */

#include <cstdlib>
#include <unistd.h>
#include <curses.h>

#include "controller.h"
#include "viewer.h"
#include "board.h"

// using namespace std;




/*
 * This program is designed to play Battleship against a computer player.
 */
int main(int argc, char** argv) {

    bool isDone = false ;
    srand(time(NULL)) ;
    
    initscr() ;
    keypad(stdscr, true) ;
    nocbreak();
    
    controller* testControl = new controller() ;
    viewer* testView = new viewer() ;

    
    addstr("-=| Welcome to Battleship! |=-\n") ;
    refresh() ;
    addstr("Press any key to continue...") ;
    refresh() ;
    getch() ;
    getch() ;

    while(!isDone)
    {
        testView->menu(isDone, testControl) ;
    }
    
    getch() ;
    
    endwin() ;
    
    return 0;
}

