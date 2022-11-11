#ifndef OPTIONSTATEVIEW_H
#define OPTIONSTATEVIEW_H
#include "StateView.h"


class OptionStateView: public StateView
{
    public:
        OptionStateView();
        virtual ~OptionStateView();
        OptionStateView(const OptionStateView& other);
        OptionStateView& operator=(const OptionStateView& other);

    protected:

    private:
};

#endif // OPTIONSTATEVIEW_H
