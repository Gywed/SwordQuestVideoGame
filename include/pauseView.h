#ifndef PAUSEVIEW_H
#define PAUSEVIEW_H
#include <SFML/Graphics.hpp>

class pauseView
{
    public:
        pauseView();
        virtual ~pauseView();
        pauseView(const pauseView& other);
        pauseView& operator=(const pauseView& other);

    protected:

    private:
};

#endif // PAUSEVIEW_H
