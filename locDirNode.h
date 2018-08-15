/* 
 * File:   node.h
 * Author: mint
 *
 * Created on November 19, 2014, 1:00 AM
 */

#ifndef LOCDIRNODE_H
#define	LOCDIRNODE_H

class locDirNode 
{
public:
    locDirNode();
    locDirNode(int pId, int pX, int pY, int pDir) ;
    locDirNode(int pId, int pX, int pY, int pDir, locDirNode* pNext, locDirNode* pPrev);
    virtual ~locDirNode();
    
    void setId(int pId) ; // setters
    void setX(int pX) ;
    void setY(int pY) ;
    void setDir(int pDir) ;
    void setNext(locDirNode* pNext) ;
    void setPrev(locDirNode* pPrev) ;
    
    int getId() const ; // getters
    int getX() const ;
    int getY() const ;
    int getDir() const ;
    locDirNode* getNext() const ;
    locDirNode* getPrev() const ;
    
    void print() const ; // prints the node data
    
private:
    int id ; // unique identifier
    int x ; // X coordinate
    int y ; // Y coordinate
    int dir ; // direction of ship
    locDirNode* next ; // pointer to next node 
    locDirNode* prev ; // pointer to previous node
    
};

#endif	/* LOCDIRNODE_H */

