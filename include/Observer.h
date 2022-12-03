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

        virtual void actualise(Observable o) = 0;

    protected:


};

#endif // OBSERVER_H
