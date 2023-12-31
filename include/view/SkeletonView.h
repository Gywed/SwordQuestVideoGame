#ifndef SKELETONVIEW_H
#define SKELETONVIEW_H
#include "view/MonsterEntity.h"
#include "model/Skeleton.h"
#include "view/MainHeroView.h"


class SkeletonView: public MonsterEntity
{
    private:
        sf::Color* colorOfSkeleton;

    public:
        SkeletonView(Skeleton* skeleton);
        virtual ~SkeletonView();
        SkeletonView(const SkeletonView& other);
        SkeletonView& operator=(const SkeletonView& other);

        //Method
        void receiveDamage(int dmg) override;

    protected:


};

#endif // SKELETONVIEW_H
