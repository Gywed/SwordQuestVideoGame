#ifndef SLIMELONG_H
#define SLIMELONG_H
#include "Monster.h"


class SlimeLong: public Monster
{
    private:

    public:
        SlimeLong(float posX = 0., float posY = 0.);
        virtual ~SlimeLong();
        SlimeLong(const SlimeLong& other);
        SlimeLong& operator=(const SlimeLong& other);
};

#endif // SKELETON_H
