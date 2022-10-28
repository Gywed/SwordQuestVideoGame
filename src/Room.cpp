#include "Room.h"

Room::Room()
{
    //ctor
}

Room::~Room()
{
    //dtor
}

Room::Room(const Room& other)
{
    //copy ctor
}

Room& Room::operator=(const Room& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
