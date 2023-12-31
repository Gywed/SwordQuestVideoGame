#ifndef OBSERVER_H
#define OBSERVER_H
#include "Observable.h"

class Observer
{
    private:

    public:
        Observer();
        virtual ~Observer();
        Observer(const Observer& other);
        Observer& operator=(const Observer& other);

        //Return true if the observer is still active
        virtual void update(Observable* o) = 0;

};

#endif // OBSERVER_H
