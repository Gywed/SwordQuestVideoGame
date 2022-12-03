#ifndef SKELETONVIEW_H
#define SKELETONVIEW_H
#include "MonsterEntity.h"
#include "Skeleton.h"
#include "MainHeroView.h"


class SkeletonView: public MonsterEntity
{
    private:

    public:
        SkeletonView(Skeleton* skeleton);
        virtual ~SkeletonView();
        SkeletonView(const SkeletonView& other);
        SkeletonView& operator=(const SkeletonView& other);

        //Method
        void getDamaged(int dmg);

    protected:


};

#endif // SKELETONVIEW_H
