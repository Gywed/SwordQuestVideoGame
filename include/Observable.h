#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <list>

using namespace std;

class Observer;

class Observable
{
    private:
        //using list instead of vector because deletion is the same wherever in the list and iterators are valid after deletion or addition of elements
        //Be aware that random access is not possible and that it isn't thread safe but we only need it in one thread so this shouldn't be a problem
        list<Observer*> observers;

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
