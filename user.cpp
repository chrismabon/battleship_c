#include "user.h"

user::user()
{
    (*compShips) = new ship[NUM_SHIPS] ;
    (*compShips)[0] = static_cast<ship>(carrier()) ;
    (*compShips)[1] = static_cast<ship>(battleship()) ;
    (*compShips)[2] = static_cast<ship>(cruiser()) ;
    (*compShips)[3] = static_cast<ship>(submarine()) ;
    (*compShips)[4] = static_cast<ship>(destroyer()) ; 
    name = "Player" ;
    id = 1 ;
}
user::user(std::string pName)
{
    (*compShips) = new ship[NUM_SHIPS] ;
    (*compShips)[0] = static_cast<ship>(carrier()) ;
    (*compShips)[1] = static_cast<ship>(battleship()) ;
    (*compShips)[2] = static_cast<ship>(cruiser()) ;
    (*compShips)[3] = static_cast<ship>(submarine()) ;
    (*compShips)[4] = static_cast<ship>(destroyer()) ; 
    name = pName ;
    id = 1 ;
}
user::user(std::string pName, int pId)
{
    (*compShips) = new ship[NUM_SHIPS] ;
    (*compShips)[0] = static_cast<ship>(carrier()) ;
    (*compShips)[1] = static_cast<ship>(battleship()) ;
    (*compShips)[2] = static_cast<ship>(cruiser()) ;
    (*compShips)[3] = static_cast<ship>(submarine()) ;
    (*compShips)[4] = static_cast<ship>(destroyer()) ; 
    name = pName ;
    id = pId ;
}
user::~user()
{
    for(int i = 0; i < NUM_SHIPS; i++)
    {
        delete compShips[i] ;
    }
}

int user::getId() const
{
    return id ;
}
std::string user::getName() const
{
    return name ;
}
void user::setId(int pId)
{
    id = pId ;
}
void user::setName(std::string pName)
{
    name = pName ;
}
ship* user::getShip(int pIndex) const
{
    return compShips[pIndex] ;
}
ship** user::getShips()
{
    return compShips ;
}