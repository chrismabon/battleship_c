#include "controller.h"
#include <unistd.h>
#include "peg.h"
#include <ctime>
#include <cstdlib>
#include <curses.h>

controller::controller()
{
    searching = true ;
    lastX = 0 ;
    lastY = 0 ;
    direction = 0 ;
    origX = 0 ;
    origY = 0 ;
    hits = 0 ;
    targetList = new std::list<locDirNode>() ;
}
controller::~controller()
{
    delete targetList ;
}

void controller::setDir(int pDir)
{
    direction = pDir ;
}
void controller::setX(int pX)
{
    lastX = pX ;
}
void controller::setY(int pY)
{
    lastY = pY ;
}
void controller::setOrigX(int pX)
{
    origX = pX ;
}
void controller::setOrigY(int pY)
{
    origY = pY ;
}
int controller::getDir() const
{
    return direction ;
}
int controller::getX() const
{
    return lastX ;
}
int controller::getY() const
{
    return lastY ;
}
int controller::getOrigX() const
{
    return origX ;
}
int controller::getOrigY() const
{
    return origY ;
}
void controller::changeTurn(int &pPlayer)
{
    if(pPlayer == 1)
    {
        pPlayer = 2 ;
    }
    else if(pPlayer == 2)
    {
        pPlayer = 1 ;
    }
}
void controller::incrementVar(int &pVar)
{
    if(pVar == 9)
    {
        ;
    }
    else
    {
        pVar++ ;
    }
}

void controller::decrementVar(int &pVar)
{
    if(pVar == 0)
    {
        ;
    }
    else
    {
        pVar-- ;
    }
}

void controller::incrementDir()
{
    if(direction == 3)
    {
        direction = 0 ;
    }
    else
    {
        direction++ ;
    }
}

void controller::setSearching(bool pSearch)
{
    searching = pSearch ;
}
void controller::changeSearching()
{
    if(searching)
    {
        searching = false ;
    }
    else if(!searching)
    {
        searching = true ;
    }
}

bool controller::isOpen(ship* pShip, board* pBoard, int pX, int pY) const
{
    bool retval ;
    
    switch(pBoard->checkElement(pX, pY))
    {
        case ' ':
        case '\000':
        case '_':
            if(checkAdj(pShip, pBoard, pX, pY) == true)
            {
                retval = false ;
            }
            else
            {
                retval = true ;
            }
            break ;
        default:
            retval = false ;
    }
    
    return retval ;
}

void controller::placeShip(ship* pShip, board* pBoard, int pX, int pY)
{
    markChar(pBoard, pShip, pX, pY) ;
    pShip->setX(pX) ;
    pShip->setY(pY) ;
}

void controller::randPlaceShips(ship** pShips, board* pBoard)
{
    int iRandX ;
    int iRandY ;
    int dir ;
    int i ; 
    bool isDone ;
    pBoard->initBlankBoard() ;
    
    for(i = 0; i < NUM_SHIPS; i++)
    {
        isDone = false ;
        
        while(!isDone)
        {
            dir = rand() % 4 ;
            randomPlace(pShips[i], iRandX, iRandY) ;
            
            pShips[i]->setDir(dir) ;
            pShips[i]->setX(iRandX) ;
            pShips[i]->setY(iRandY) ;

            if(checkAdj(pShips[i], pBoard, iRandX, iRandY) == false)
            {
                placeShip(pShips[i], pBoard, iRandX, iRandY) ;
                isDone = true ;
            }
            else
            {
                dir = rand() % 4 ;
                pShips[i]->setDir(dir) ;

                if(checkAdj(pShips[i], pBoard, iRandX, iRandY) == false)
                {
                    placeShip(pShips[i], pBoard, iRandX, iRandY) ;
                    isDone = true ;
                }
            }
        }
    }
}

bool controller::checkAdj(ship* pShip, board* pBoard, int pX, int pY) const
{
    bool retval ;
    
    if(countTaken(pBoard, pShip) > 0)
    {
        retval = true ;
    }
    else
    {
        retval = false ;
    }
    
    return retval ;
}

int controller::countTaken(board* pBoard, ship* pShip) const
{
    int i ;
    int count = 0 ;
    int pX = pShip->getX() ;
    int pY = pShip->getY() ;
    int direction = pShip->getDir() ;
    int pSize = pShip->getSize() ;
    
    switch(direction)
    {
        case 0:
            for(i = pSize - 1; i >= 0; i--)
            {
                if((pY - i) < 0)
                {
                    count++ ;
                    break ;
                }
                else
                {
                    if(pBoard->checkElement(pY - i, pX) == '_') 
                    {
                        ;
                    }
                    else
                    {
                        count++ ;
                    }
                }
            }
            break ;
        case 1:
            for(i = 0; i < pSize; i++)
            {
                if((pY + i) > 9)
                {
                    count++ ;
                    break ;
                }
                else
                {
                    if(pBoard->checkElement(pY + i, pX) == '_') 
                    {
                        ;
                    }
                    else
                    {
                        count++ ;
                    }
                }
            }
            break ;
        case 2:
            
                for(i = pSize - 1; i >= 0; i--)
                {
                    if((pX - i) < 0)
                    {
                        count++ ;
                        break ;
                    }
                    else
                    {
                        if(pBoard->checkElement(pY, pX - i) == '_')
                        {
                            ;
                        }
                        else
                        {
                            count++ ;
                        }
                    }
                }
            break ;
        case 3:
            for(i = 0; i < pSize; i++)
            {
                if((pX + i) > 9)
                {
                    count++ ;
                    break ;
                }
                else
                {
                    if(pBoard->checkElement(pY, pX + i) == '_')
                    {
                        ;
                    }
                    else
                    {
                        count++ ;
                    }
                }
            }    
            break ;
        default:
            addstr("Error counting open spots!") ;
    }
    return count ;
}

bool controller::markBoard(board* pBoard, ship* pShip, int pX, int pY) 
{
    bool retval ;
    
    if(isOpen(pShip, pBoard, pX, pY) == true)
    {
        markChar(pBoard, pShip, pX, pY) ;
        retval = true ;
    }
    else 
    {
        retval = false ;
    }
}

void controller::markChar(board* pBoard, ship* pShip, int pX, int pY)
{
    char shipChar ;
    
    if((pShip->getName().compare("Carrier") == 0))
    {
        shipChar = 'A' ;
    }
    else if((pShip->getName().compare("Battleship") == 0))
    {
        shipChar = 'B' ;
    }
    else if((pShip->getName().compare("Cruiser") == 0))
    {
        shipChar = 'C' ;
    }
    else if((pShip->getName().compare("Submarine") == 0))
    {
        shipChar = 'S' ;
    }
    else if((pShip->getName().compare("Destroyer") == 0))
    {
        shipChar = 'D' ;
    }
    
    if(pShip->getDir() == 0)
    {
         for(int i = pShip->getSize() - 1; i >= 0; i--)
        {
            pBoard->setElement(pY - i, pX, shipChar) ;
        }
    }
    else if(pShip->getDir() == 1)
    {
        for(int i = 0; i < pShip->getSize(); i++)
        {
            pBoard->setElement(pY + i, pX, shipChar) ;
        }
    }
    else if(pShip->getDir() == 2)
    {
         for(int i = pShip->getSize() - 1; i >= 0; i--)
        {
            pBoard->setElement(pY, pX - i, shipChar) ;
        }
    }
    else if(pShip->getDir() == 3)
    {
         for(int i = 0; i < pShip->getSize(); i++)
        {
            pBoard->setElement(pY, pX + i, shipChar) ;
        }
    }
}

void controller::randomPlace(ship* pShip, int &pX, int &pY)
{
    pX = rand() % 9 ;
    pY = rand() % 9 ; 
}

void controller::promptPlaceShips(ship** pShips, board* pBoard, player* pPlayer)
{
    clear() ;
    refresh() ;
    cbreak() ;
    noecho() ;
    curs_set(0) ;
    
    addstr("Use the arrow keys to move the ship, space bar to change orientation,") ;
    addstr(" and enter to finalize your choice. Hit Enter to continue...") ;
    
    refresh() ;
//    sleep(1) ;
    getch() ;
    
    bool isDone ;
    int sel ;
    board* placeBoard = new board() ;
    placeBoard->initBlankBoard() ;
    pBoard->initBlankBoard() ;
    
    for(int i = 0; i < NUM_SHIPS; i++)
    {
        sel = 0 ;
        isDone = false ;
        pBoard->copyBoard(placeBoard) ;
        
        while(!isDone)
        {
            pShips[i]->setX(rand() % 10) ;
            pShips[i]->setY(rand() % 10) ;
            pShips[i]->setDir(rand() % 4) ;
        
            if((checkAdj(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY())) == true)
            {
                pShips[i]->incrementDir() ;
                
                if((checkAdj(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY())) == true)
                {
                    pShips[i]->incrementDir() ;
                    
                    if((checkAdj(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY())) == true)
                    {
                        pShips[i]->incrementDir() ;
                    }
                    else
                    {
                        placeShip(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY()) ;
                        isDone = true ;
                    }
                }
                else
                {
                    placeShip(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY()) ;
                    isDone = true ;
                }
            }
            else
            {
                placeShip(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY()) ;
                isDone = true ; 
            }
        }
                
        while(sel != 10)
        {
            clear() ;
            placeBoard->printBoard() ;
            
            switch(i)
            {
                case 0:
                    addstr("Carrier - A") ;
                    break ;
                case 1:
                    addstr("Battleship - B") ;
                    break ;
                case 2:
                    addstr("Cruiser - C") ;
                    break ;
                case 3:
                    addstr("Submarine - S") ;
                    break ;
                case 4:
                    addstr("Destroyer - D") ;
                    break ;
            }
            
            refresh() ;
            sel = getch() ;

            switch(sel)
            {
                case KEY_UP:
                    pShips[i]->decrementY() ;
                    if(checkAdj(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) == true)
                    {
                        pShips[i]->incrementY() ;
                    }
                    else
                    {
                        ;
                    }
                    break ;
                case KEY_DOWN:
                    pShips[i]->incrementY() ;
                    if(checkAdj(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) == true)
                    {
                        pShips[i]->decrementY() ;
                    }
                    else
                    {
                        ;
                    }
                    break ;
                case KEY_LEFT:
                    pShips[i]->decrementX() ;
                    if(checkAdj(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) == true)
                    {
                        pShips[i]->incrementX() ;
                    }
                    else
                    {
                        ;
                    }
                    break ;
                case KEY_RIGHT:
                    pShips[i]->incrementX() ;
                    if(checkAdj(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) == true)
                    {
                        pShips[i]->decrementX() ;
                    }
                    else
                    {
                        ;
                    }
                    break ;
                case 32:
                    pShips[i]->incrementDir() ;
                    if(checkAdj(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) == true)
                    {
                        pShips[i]->decrementDir() ;
                    }
                    else
                    {
                        ;
                    }
                    break ;
                case 10:
                    addstr("Selection made.") ;
                    placeShip(pShips[i], pBoard, pShips[i]->getX(), pShips[i]->getY()) ;
                    break ;
                default:
                    ;
            }
            pBoard->copyBoard(placeBoard) ;
            placeShip(pShips[i], placeBoard, pShips[i]->getX(), pShips[i]->getY()) ;
        }
        sleep(2) ;
    }
    
    delete placeBoard ;
    nocbreak() ;
}
bool controller::playerVsComp()
{
    player* humanPlayer = new player("Human Player", 1) ;
    player* compPlayer = new player("Computer Player", 2) ;
    initPlayersAndBoards(humanPlayer, compPlayer) ;
    char select ;
    bool selected = false ;
    
    while(!selected)
    {
        clear() ;
        addstr("Would you like to place your own ships (Y/N)? ") ;
        refresh() ;
        select = getch() ;

        switch(select)
        {
            case 'y':
            case 'Y':
                promptPlaceShips(humanPlayer->getShips(), humanPlayer->getSelf(), humanPlayer) ;
                selected = true ;
                break ;
            case 'n':
            case 'N':
                randPlaceShips(humanPlayer->getShips(), humanPlayer->getSelf()) ;
                selected = true ;
                break ;
            default:
                addstr("Invalid selection.") ;
                refresh() ;
        }
    }
        
    bool turnTaken ;
    int playerTurn = 1 ;
    char shot ;
    
    randPlaceShips(compPlayer->getShips(), compPlayer->getSelf()) ;
    
    clear() ;
    compPlayer->getSelf()->printBoard() ;
    addstr("Computer board. Hit any key to continue...") ;
    refresh() ;
    getch() ;
    getch() ;
        
    while(determineWinner(humanPlayer, compPlayer) == 0)
    {
        turnTaken = false ;
        
        while(!turnTaken)
        {
            if(playerTurn == 1)
            {
                humanPlayer->getSelf()->printBoard() ;
                addstr("Your board. Hit any key to continue...") ;
                refresh() ;
                getch() ;
                               
                shot = promptPlaceShot(humanPlayer, humanPlayer->getShots(), compPlayer->getSelf()) ;

                switch(shot)
                {
                    case '_':
                        addstr("Miss!") ;
                        refresh() ;
                        break ;
                    case 'A':
                        compPlayer->getShip(0)->incrementDmg() ;
                        addstr("Hit! Carrier...") ;
                        refresh() ;
                        break ;
                    case 'B':
                        compPlayer->getShip(1)->incrementDmg() ;
                        addstr("Hit! Battleship...") ;
                        refresh() ;
                        break ;
                    case 'C':
                        compPlayer->getShip(2)->incrementDmg() ;
                        addstr("Hit! Cruiser...") ;
                        refresh() ;
                        break ;
                    case 'S':
                        compPlayer->getShip(3)->incrementDmg() ;
                        addstr("Hit! Submarine...") ;
                        refresh() ;
                        break ;
                    case 'D':
                        compPlayer->getShip(4)->incrementDmg() ;
                        addstr("Hit! Destroyer...") ;
                        refresh() ;
                        break ;
                }
                getch() ;
                turnTaken = true ;
            }
            else if(playerTurn == 2)
            {
                computerAi(compPlayer->getShots(), humanPlayer->getSelf(), humanPlayer, compPlayer) ;
                turnTaken = true ;
            }
        }
        
        changeTurn(playerTurn) ;
    }
    
    clear() ;
    
    if(determineWinner(humanPlayer, compPlayer) == 1)
    {
        addstr("\nHuman player has won!") ;
    }
    else if(determineWinner(humanPlayer, compPlayer) == 2)
    {
        addstr("\nComputer player has won...Try again?") ;
    }
    refresh() ;
    
//    delete humanPlayer ;
//    delete compPlayer ;
}
char controller::promptPlaceShot(player* pPlayer, board* playerShots, board* compSelf)
{
    clear() ;
    refresh() ;
    cbreak() ;
    noecho() ;
    curs_set(0) ;
        
    char retval ;
    bool isDone = false ;
    int sel = 0 ;
    peg* mark = new peg(5, 5, false) ;
    board* placeBoard = new board() ;
       
    while(!isDone)
    {
        placeBoard->initBlankBoard() ;
        playerShots->copyBoard(placeBoard) ;
        placeBoard->setPeg(mark) ;
        
        clear() ;
        placeBoard->printBoard() ;
        
        refresh() ;
        sel = getch() ;

        switch(sel)
        {
            case KEY_UP:
                mark->decrementY() ;
                break ;
            case KEY_DOWN:
                mark->incrementY() ;
                break ;
            case KEY_LEFT:
                mark->decrementX() ;
                break ;
            case KEY_RIGHT:
                mark->incrementX() ;
                break ;
            case 10:
                retval = compSelf->checkElement(mark->getY(), mark->getX()) ;
                if((retval != 'O') && (retval != 'X'))
                {
                    mark->setColor(true) ;
                    playerShots->setPeg(mark) ;
                    compSelf->setPeg(mark) ;
                    isDone = true ;
                }
                else
                {
                    ;
                }
                break ;
            default:
                ;
        }
        playerShots->copyBoard(placeBoard) ;
        placeBoard->setPeg(mark) ;
    }
    
    delete placeBoard ;
    delete mark ;
    echo() ;
    nocbreak() ;
    
    return retval ;
}

void controller::computerAi(board* compShots, board* playerSelf, player* humanPlayer, player* compPlayer)
{
    bool isDone = false ;
    peg* mark ;
    
    while(!isDone)
    {
        if(searching)
        {
            origX = rand() % 10 ;
            origY = rand() % 10 ;
            lastX = origX ;
            lastY = origY ;
        }
        else
        {
            switch(direction)
            {
                case 0:
                    decrementVar(lastY) ;
                    break ;
                case 1:
                    incrementVar(lastY) ;
                    break ;
                case 2:
                    decrementVar(lastX) ;
                    break ;
                case 3:
                    incrementVar(lastX) ;
                    break ;
            }
        }
        mark = new peg(lastX, lastY, false) ;
        char hitType = placeShot(humanPlayer, mark, humanPlayer->getSelf()) ;
        
        switch(hitType)
        {
            case 'A':
            case 'B':
            case 'C':
            case 'S':
            case 'D':   
                hits++ ;
                searching = false ;
                isDone = true ;
                break ;
            case 'O':
                if(direction == 3)
                {
                    searching = true ;
                }
                hits = 0 ;
                incrementDir() ;
                isDone = true ;
                break ;
        }
    }
    
    delete mark ;
}

char controller::placeShot(player* defensePlayer, peg* pPeg, board* defenseBoard) 
{
    bool isDone = false ;
    char hit ;
    
    while(!isDone)
    {
        hit = defenseBoard->setPeg(pPeg) ;
        
        switch(hit)
        {
            case 'O':
                pPeg->setColor(false) ;
                isDone = true ;
                break ;
            case 'A':
                defensePlayer->getShip(0)->incrementDmg() ;
                pPeg->setColor(true) ;
                addstr("Your Carrier has been hit!") ;
                refresh() ;
                getch() ;
                isDone = true ;
                break ;
            case 'B':
                defensePlayer->getShip(1)->incrementDmg() ;
                pPeg->setColor(true) ;
                addstr("Your Battleship has been hit!") ;
                refresh() ;
                getch() ;
                isDone = true ;
                break ;
            case 'C':
                defensePlayer->getShip(2)->incrementDmg() ;
                pPeg->setColor(true) ;
                addstr("Your Cruiser has been hit!") ;
                refresh() ;
                getch() ;
                isDone = true ;
                break ;
            case 'S':
                defensePlayer->getShip(3)->incrementDmg() ;
                pPeg->setColor(true) ;
                addstr("Your Submarine has been hit!") ;
                refresh() ;
                getch() ;
                isDone = true ;
                break ;
            case 'D':
                defensePlayer->getShip(4)->incrementDmg() ;
                pPeg->setColor(true) ;
                addstr("Your Destroyer has been hit!") ;
                refresh() ;
                getch() ;
                isDone = true ;
                break ;
            case 'X':
                pPeg->setX(rand() % 10) ;
                pPeg->setY(rand() % 10) ;
                break ;
        }
        defenseBoard->setPeg(pPeg) ;
    }
     
    return hit ;
}

int controller::determineWinner(player* humanPlayer, player* compPlayer)
{
    int shipsPlayer = 0 ;
    int shipsComp = 0 ;
    int retval = 0 ;
    
    for(int i = 0; i < NUM_SHIPS; i++)
    {
        if(humanPlayer->getShip(i)->getSunk() == true)
        {
            ;
        }
        else
        {
            shipsPlayer++ ;
        }
        
        if(compPlayer->getShip(i)->getSunk() == true)
        {
            ;
        }
        else
        {
            shipsComp++ ;
        }
    }
    
    if(shipsPlayer == 0)
    {
        retval = 2 ;
    }
    else
    {
        retval = 0 ;
    }
    if(shipsComp == 0)
    {
        retval = 1 ;
    }
    else
    {
        retval = 0 ;
    }
    
    return retval ;
}
void controller::initPlayersAndBoards(player* humanPlayer, player* compPlayer) 
{
    humanPlayer->initShips() ;
    compPlayer->initShips() ;
    
    humanPlayer->getSelf()->initBlankBoard() ;
    humanPlayer->getShots()->initBlankBoard() ;
    
    compPlayer->getSelf()->initBlankBoard() ;
    compPlayer->getShots()->initBlankBoard() ;
}