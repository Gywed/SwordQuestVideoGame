#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <model/MainHero.h>
#include <model/Monster.h>
#include <list>

#define Nb_Tile 480

using std::list;

class Room
{
    private:

        list<Monster*> monsters;
        int tilesMapping[Nb_Tile];

    public:
        Room();
        virtual ~Room();
        Room(const Room& other);
        Room& operator=(const Room& other);

        // Getter/Setter
        list<Monster*> getMonsters()const;

        const int * getTilesMapping();
        void addMonster(Monster* monster);
        void removeMonster(Monster* monster);
        Monster* generateNewMonster();

    protected:




};

#endif // ROOM_H
