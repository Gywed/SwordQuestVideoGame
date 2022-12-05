#ifndef SLIMELONGVIEW_H
#define SLIMELONGVIEW_H
#include "view/MonsterEntity.h"
#include "model/SlimeLong.h"
#include "view/MainHeroView.h"


class SlimeLongView: public MonsterEntity
{
    private:
        sf::Color* colorOfSkeleton;

    public:
        SlimeLongView(SlimeLong* slimeLong);
        virtual ~SlimeLongView();
        SlimeLongView(const SlimeLongView& other);
        SlimeLongView& operator=(const SlimeLongView& other);

        //Method
        void getDamaged(int dmg) override;

    protected:


};

#endif // SKELETONVIEW_H
