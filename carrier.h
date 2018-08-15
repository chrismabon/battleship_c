/* 
 * File:   carrier.h
 * Author: mint
 *
 * Created on November 14, 2014, 12:47 PM
 */

#ifndef CARRIER_H
#define	CARRIER_H

#include "ship.h"

class carrier 
    : public ship
{
public:
    carrier();
    virtual ~carrier() ;
};

#endif	/* CARRIER_H */

