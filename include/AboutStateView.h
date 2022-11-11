#ifndef ABOUTSTATEVIEW_H
#define ABOUTSTATEVIEW_H
#include "StateView.h"


class AboutStateView: public StateView
{
    public:
        AboutStateView();
        virtual ~AboutStateView();
        AboutStateView(const AboutStateView& other);
        AboutStateView& operator=(const AboutStateView& other);

    protected:

    private:
};

#endif // ABOUTSTATEVIEW_H
