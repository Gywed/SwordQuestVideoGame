#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>

using namespace std;

class Observer;

class Observable
{
    private:
        vector<Observer*> observers;

    public:
        Observable();
        virtual ~Observable();
        Observable(const Observable& other);
        Observable& operator=(const Observable& other);

        void attach(Observer* obs);
        void detach(Observer* obs);
        void notify();

    protected:


};

#endif // OBSERVABLE_H
