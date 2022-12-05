#ifndef SLIMEROUND_H
#define SLIMEROUND_H
#include "Monster.h"


class SlimeRound: public Monster
{
    private:

    public:
        SlimeRound(float posX = 0., float posY = 0.);
        virtual ~SlimeRound();
        SlimeRound(const SlimeRound& other);
        SlimeRound& operator=(const SlimeRound& other);
};

#endif // SKELETON_H
