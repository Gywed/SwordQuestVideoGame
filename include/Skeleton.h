#ifndef SKELETON_H
#define SKELETON_H
#include "Monster.h"


class Skeleton: public Monster
{
    private:

    public:
        Skeleton(float posX, float posY);
        virtual ~Skeleton();
        Skeleton(const Skeleton& other);
        Skeleton& operator=(const Skeleton& other);
};

#endif // SKELETON_H
