#include "model/Observable.h"
#include "model/Observer.h"
#include <iostream>

Observable::Observable()
{
    //ctor
}

Observable::~Observable()
{
    //dtor
}

Observable::Observable(const Observable& other)
{
    //copy ctor
}

Observable& Observable::operator=(const Observable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Observable::attach(Observer* obs)
{
    observers.push_back(obs);
}

void Observable::detach(Observer* obs)
{
    observers.remove(obs);
}

void Observable::notify()
{
    std::cout<<"list size : " + std::to_string(observers.size())<<std::endl;
    if(!observers.empty())
        for (Observer* obs : observers)
            obs->update(this);
}
