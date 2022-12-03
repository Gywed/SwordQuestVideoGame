#include "view/StateView.h"

StateView::StateView()
{
    //ctor
}

StateView::~StateView()
{
    //dtor
}

StateView::StateView(const StateView& other)
{
    //copy ctor
}

StateView& StateView::operator=(const StateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
