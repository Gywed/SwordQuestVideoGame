#include "view/BasicRoomView.h"
#include <iostream>
#include "model/Skeleton.h"
#include "view/SkeletonView.h"

BasicRoomView::BasicRoomView()
{
    this->room = new Room();

    if (!this->tileMap.load("images/Tileset.png", sf::Vector2u(64, 64), this->room->getTilesMapping(), 30, 16))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
}

BasicRoomView::~BasicRoomView()
{
    delete this->room;
}

BasicRoomView::BasicRoomView(const BasicRoomView& other)
{
    //copy ctor
}

BasicRoomView& BasicRoomView::operator=(const BasicRoomView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Setters getters
TileMap BasicRoomView::getTileMap()const { return tileMap; }

void BasicRoomView::removeMonster(MonsterEntity* monsterV)
{
    monsters.remove(monsterV);
    room->removeMonster(monsterV->getMonster());
    delete monsterV;
}

void BasicRoomView::generateMonsterView()
{
    Monster* newMonster = this->room->generateNewMonster();
    if(instanceof<Skeleton>(newMonster))
        monsters.push_back(new SkeletonView((Skeleton*)newMonster));
}
