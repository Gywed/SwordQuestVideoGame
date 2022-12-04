#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <model/MainHero.h>
#include <model/Monster.h>
#include <list>

using std::list;

class Room
{
    public:
        Room();
        virtual ~Room();
        Room(const Room& other);
        Room& operator=(const Room& other);

        static int getCompteur();
        int getId()const;

        const int * getTilesMapping();
        void addMonster(Monster* monster);
        void removeMonster(Monster* monster);

    protected:

    private:

        list<Monster*> monsters;
        int tilesMapping[480];

        int* id;
        inline static int compteur;


};

#endif // ROOM_H
