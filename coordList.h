/* 
 * File:   coordList.h
 * Author: mint
 *
 * Created on November 19, 2014, 1:41 AM
 */

#ifndef COORDLIST_H
#define	COORDLIST_H

#include <cstdlib>
#include <list>
#include "locDirNode.h"

class coordList 
{
public:
    coordList();
    virtual ~coordList();
    
    int ID ;
    
    locDirNode* getHead() const ; // seems like an inappropriate name, but actually returns the first Location/Direction Node
    locDirNode* getTail() const ; // again, actually returns the last Location/Direction Node
    int getCount() const ; // returns the number of nodes in the list
    
    void setHead(locDirNode* pNode) ; // setters
    void setTail(locDirNode* pNode) ; 
    void setCount(int pI) ;
    
    void incrementCount() ; // increment/decrement the count
    void decrementCount() ;
    
    bool addToList(locDirNode* pNode) ; // adds a node to the list
    locDirNode* removeLast() ; // removes the last node
    locDirNode* removeSearch(int pId) ; // searches for the matching ID of the node and removes it
    void clear() ; // clears the list of nodes
    
protected:
    std::list<locDirNode> list ; // list of locDirNodes
    std::list<locDirNode>::iterator listIter ; // iterator
    locDirNode* head ; // pointer to head node
    locDirNode* tail ; // pointer to tail node
    int count ; // number of nodes in the list
};

#endif	/* COORDLIST_H */

