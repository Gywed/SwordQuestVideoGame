#include "model/Observable.h"
#include "model/Observer.h"

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
    for (Observer* observer : other.observers)
        this->observers.push_back(observer);
}

Observable& Observable::operator=(const Observable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    this->observers.clear();

    for (Observer* observer : rhs.observers)
        this->observers.push_back(observer);

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
    for(Observer* obs : observers)
       obs->update(this);

}
