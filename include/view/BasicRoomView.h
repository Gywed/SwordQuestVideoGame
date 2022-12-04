#ifndef BASICROOMVIEW_H
#define BASICROOMVIEW_H
#include "view/TileMap.h"
#include "model/Room.h"
#include <list>
#include "view/MonsterEntity.h"

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
        std::list<MonsterEntity*> monsters;


    public:
        BasicRoomView();
        virtual ~BasicRoomView();
        BasicRoomView(const BasicRoomView& other);
        BasicRoomView& operator=(const BasicRoomView& other);

        //Setters getter
        TileMap getTileMap()const;

        void removeMonster(MonsterEntity* monsterV);
        void generateMonsterView();


};

#endif // BASICROOMVIEW_H
