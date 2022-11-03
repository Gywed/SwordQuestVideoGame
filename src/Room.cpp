#include "Room.h"

Room::Room()
{
    //ctor
    id = new int(compteur++);
}

Room::~Room()
{
    //dtor

}

Room::Room(const Room& other)
{
    //copy ctor
    delete id;
    this->id = new int (*other.id);

    for (Monster* monster : other.monsters)
    {
        this->monsters.push_back(new Monster(*monster));
    }
}

Room& Room::operator=(const Room& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    delete id;

    this->id = new int(*rhs.id);

    for (Monster* monster : monsters)
        delete monster;
    for (Monster* monster : rhs.monsters)
    {
        this->monsters.push_back(new Monster(*monster));
    }

    return *this;
}

int Room::getCompteur()
{
    return compteur;
}

int Room::getId()const
{
    return *id;
}
