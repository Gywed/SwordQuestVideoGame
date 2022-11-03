#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <Character.h>
#include <Monster.h>

using std::vector;

class Room
{
    public:
        Room();
        virtual ~Room();
        Room(const Room& other);
        Room& operator=(const Room& other);

        static int getCompteur();
        int getId()const;

    protected:

    private:

        vector<Monster*> monsters;
        Character* character;

        int* id;
        inline static int compteur;


};

#endif // ROOM_H
