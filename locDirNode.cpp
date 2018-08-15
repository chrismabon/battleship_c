/* 
 * File:   node.cpp
 * Author: mint
 * 
 * Created on November 19, 2014, 1:00 AM
 */

#include "locDirNode.h"
#include <cstdlib>
#include <iostream>

locDirNode::locDirNode() 
{
    id = -1 ;
    x = -1 ;
    y = -1 ;
    dir =  -1 ;
    next = NULL ;
    prev = NULL ;
}
locDirNode::locDirNode(int pId, int pX, int pY, int pDir)
{
    id = pId ;
    x = pX ;
    y = pY ;
    dir = pDir ;
    next = NULL ;
    prev = NULL ;
}
locDirNode::locDirNode(int pId, int pX, int pY, int pDir, locDirNode* pNext, locDirNode* pPrev)
{
    id = pId ;
    x = pX ;
    y = pY ;
    dir = pDir ;
    next = pNext ;
    prev = pPrev ;
}

locDirNode::~locDirNode() 
{
    delete next ;
    delete prev ;
    next = NULL ;
    prev = NULL ;
}

int locDirNode::getId() const
{
    return id ;
}
int locDirNode::getDir() const
{
    return dir ;
}
int locDirNode::getX() const
{
    return x ;
}
int locDirNode::getY() const
{
    return y ;
}
locDirNode* locDirNode::getNext() const
{
    return next;
}
locDirNode* locDirNode::getPrev() const
{
    return prev;
}

void locDirNode::setId(int pId)
{
    id = pId ;
}
void locDirNode::setDir(int pDir)
{
    dir = pDir ;
}
void locDirNode::setX(int pX)
{
    x = pX ;
}
void locDirNode::setY(int pY)
{
    y = pY ;
}
void locDirNode::setNext(locDirNode* pNext)
{
    next = pNext ;
}
void locDirNode::setPrev(locDirNode* pPrev)
{
    prev = pPrev ;
}

void locDirNode::print() const 
{
    std::cout << "-=| Printing the location/direction node |=-" << std::endl ;
    std::cout << "X location: " << x << ", Y location: " << y << "." << std::endl ;
    
    switch(dir)
    {
        case 0:
            std::cout << "Direction is up: " << dir << "." << std::endl ;
            break ;
        case 1:
            std::cout << "Direction is down: " << dir << "." << std::endl ;
            break ;
        case 2:
            std::cout << "Direction is left: " << dir << "." << std::endl ;
            break ;
        case 3:
            std::cout << "Direction is right: " << dir << "." << std::endl ;
            break ;
    }
}