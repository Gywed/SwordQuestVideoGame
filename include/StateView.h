#ifndef STATEVIEW_H
#define STATEVIEW_H


class StateView
{
    public:
        StateView();
        virtual ~StateView();
        StateView(const StateView& other);
        StateView& operator=(const StateView& other);

        /* Abstract Method */
        /* Method to initialize the state (constructor) */
        virtual void init(sf::RenderWindow* window) {}
        /* Method to run the state */
        virtual void run(sf::RenderWindow* window){}
        /* Method to draw component in the game window */
        virtual void render(sf::RenderWindow* window) {}
        /* Method for destroy component in the window game */
        virtual void destroy() {}

    protected:

    private:
};

#endif // STATEVIEW_H
