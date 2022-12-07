#ifndef SLIMEROUNDVIEW_H
#define SLIMEROUNDVIEW_H
#include "view/MonsterEntity.h"
#include "model/SlimeRound.h"
#include "view/MainHeroView.h"


class SlimeRoundView: public MonsterEntity
{
    private:
        sf::Color* colorOfSkeleton;

    public:
        SlimeRoundView(SlimeRound* slimeRound);
        virtual ~SlimeRoundView();
        SlimeRoundView(const SlimeRoundView& other);
        SlimeRoundView& operator=(const SlimeRoundView& other);

        //Method
        void receiveDamage(int dmg) override;

    protected:


};

#endif // SKELETONVIEW_H
