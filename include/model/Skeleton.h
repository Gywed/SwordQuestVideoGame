#ifndef SKELETON_H
#define SKELETON_H
#include "Monster.h"


class Skeleton: public Monster
{
    private:

    public:
        Skeleton(float posX = 0., float posY = 0.);
        virtual ~Skeleton();
        Skeleton(const Skeleton& other);
        Skeleton& operator=(const Skeleton& other);
};

#endif // SKELETON_H
