#ifndef PLAYSTATEVIEW_H
#define PLAYSTATEVIEW_H
#include "StateView.h"

class PlayStateView: public StateView
{
    public:
        PlayStateView();
        virtual ~PlayStateView();
        PlayStateView(const PlayStateView& other);
        PlayStateView& operator=(const PlayStateView& other);

    protected:

    private:
};

#endif // PLAYSTATEVIEW_H
