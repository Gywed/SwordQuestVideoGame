#ifndef BASICROOMVIEW_H
#define BASICROOMVIEW_H
#include "view/TileMap.h"
#include "model/Room.h"
#include <list>
#include "view/MonsterEntity.h"

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T *ptr)
{
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

class BasicRoomView
{
    private:
        TileMap tileMap;
        Room* room;
        list<MonsterEntity*> monsters;


    public:
        BasicRoomView();
        virtual ~BasicRoomView();
        BasicRoomView(const BasicRoomView& other);
        BasicRoomView& operator=(const BasicRoomView& other);

        //Setters getter
        TileMap getTileMap()const;
        list<MonsterEntity*> getMonsters()const;

        void removeMonster(MonsterEntity* monsterV);
        MonsterEntity* generateMonsterView();


};

#endif // BASICROOMVIEW_H
