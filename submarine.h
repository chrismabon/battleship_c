/* 
 * File:   submarine.h
 * Author: mint
 *
 * Created on November 14, 2014, 12:56 PM
 */

#ifndef SUBMARINE_H
#define	SUBMARINE_H

#include "ship.h"


class submarine 
    : public ship
{
public:
    submarine();
    virtual ~submarine() ;
};

#endif	/* SUBMARINE_H */

