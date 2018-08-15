/* 
 * File:   peg.h
 * Author: mint
 *
 * Created on December 3, 2014, 4:24 PM
 */

#ifndef PEG_H
#define	PEG_H

class peg {
public:
    peg();
    peg(int pX, int pY, bool pIsRed) ;
    virtual ~peg();
    
    int getX() const ;
    int getY() const ;
    bool getColor() const ;
    
    void setX(int pX) ;
    void setY(int pY) ;
    void setColor(bool pColor) ;
    
    void incrementX() ; // used to move the peg around on the board
    void incrementY() ;
    void decrementX() ;
    void decrementY() ;
    
    static char constexpr WHITE = 'O' ; // white pegs are represented as O's
    static char constexpr RED = 'X' ; // red pegs are X's
    
private:
    int x ; // coordinate X
    int y ; // coordinate Y
    bool isRed ; // boolean determining color (is red? -> no == must be white)
};

#endif	/* PEG_H */

