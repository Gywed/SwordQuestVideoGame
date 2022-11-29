#ifndef SKELETONVIEW_H
#define SKELETONVIEW_H
#include "Entity.h"
#include "Skeleton.h"


class SkeletonView: public Entity
{
    private:
        Skeleton* skeleton;

    public:
        SkeletonView(Skeleton* skeleton);
        virtual ~SkeletonView();
        SkeletonView(const SkeletonView& other);
        SkeletonView& operator=(const SkeletonView& other);

        Skeleton* getSkeleton()const;
        void setSkeleton(Skeleton* skeleton);

        //Method
        void spriteEvents(sf::RenderWindow* window);

        //Animation
        virtual void updateSpriteMovementAnimation();
        virtual void updateSpriteIdleAnimation();
        virtual void updateSpriteSimpleAttackAnimation();
        virtual void updateSpriteDeathAnimation();

    protected:


};

#endif // SKELETONVIEW_H
