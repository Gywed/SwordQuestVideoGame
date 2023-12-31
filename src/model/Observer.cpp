#include "model/Observer.h"

Observer::Observer()
{
    //ctor
}

Observer::~Observer()
{
    //dtor
}

Observer::Observer(const Observer& other)
{
    //copy ctor
}

Observer& Observer::operator=(const Observer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
