/* 
 * File:   coordList.cpp
 * Author: mint
 * 
 * Created on November 19, 2014, 1:41 AM
 */

#include "coordList.h"
#include <stdlib.h>

coordList::coordList() 
{
    ID = 1 ;
    head = new locDirNode(-1, -1, -1, -1, NULL, NULL) ;
    tail = head ;
    count = 0 ;
    listIter = list.begin() ;
}
coordList::~coordList() 
{
    clear() ;    
    delete head ;
    delete tail ;
    head = NULL ;
    tail = NULL ;
}

locDirNode* coordList::getHead() const 
{
    return head ;
}
locDirNode* coordList::getTail() const 
{
    return tail ;
}
int coordList::getCount() const 
{
    return count ;
}
    
void coordList::setHead(locDirNode* pNode) 
{
    head = pNode ;
}
void coordList::setTail(locDirNode* pNode) 
{
    tail = pNode ;
}
void coordList::setCount(int pI) 
{
    count = pI ;
}
    
void coordList::incrementCount() 
{
    count++ ;
}
void coordList::decrementCount() 
{
    count-- ;
}
    
bool coordList::addToList(locDirNode* pNode)
{
    
    pNode->setId(ID) ;
    ID++ ;
    tail = pNode ;
    list.push_back(*pNode) ;
    count++ ;
}
locDirNode* coordList::removeLast()
{
    locDirNode* retval ;
    listIter = list.begin() ;
    
    while(listIter != list.end())
    {
        ++listIter ;
        (*retval) = (*listIter) ;
    }
    
    retval->getPrev()->setNext(NULL) ;
    retval->setPrev(NULL) ;
    
    return retval ;
}
locDirNode* coordList::removeSearch(int pId)
{
    locDirNode* retval = head ;
    locDirNode* nextNode ; 
    locDirNode* prevNode ;
    listIter = list.begin() ;
    
    while(listIter != list.end())
    {
        if(listIter->getId() == pId)
        {
            head = listIter->getNext() ;
            (*retval) = (*listIter) ;
            retval->setNext(NULL) ;
            retval->setPrev(NULL) ;
            count-- ;
            break ;
        }
        else if(listIter->getNext()->getId() == pId)
        {
            (*prevNode) = (*listIter) ;
            listIter++ ;
            (*retval) = (*listIter) ;
            nextNode = listIter->getNext() ;
            prevNode->setNext(nextNode) ;
            retval->setNext(NULL) ;
            retval->setPrev(NULL) ;
            count-- ;
            break ;
        }
        ++listIter ;
    }
    
    delete nextNode ;
    delete prevNode ;
    
    return retval ;
}

void coordList::clear()
{
    listIter = list.begin() ;
    locDirNode* temp ;
    
    if(list.empty())
    {
        ;
    }
    else
    {
        while(listIter != list.end())
        {
            (*temp) = (*listIter) ;
            temp->setNext(NULL) ;
            temp->setPrev(NULL) ;
            delete temp ;
            ++listIter ;
        }
    }
}