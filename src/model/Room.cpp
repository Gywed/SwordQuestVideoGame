#include "model/Room.h"
#include "model/Skeleton.h"

Room::Room()
{
    //ctor
    id = new int(compteur++);

    //Iniate tiles mapping
    int tileNumber;
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<16; j++)
        {
            //Left wall
            if(i==0)
            {
                if(j==0)
                    tileNumber=75;
                if(j>0 && j< 3)
                    tileNumber=125;
                if(j==3)
                    tileNumber=150;
                if(j>3 && j< 15)
                    tileNumber=175;
                if(j==15)
                    tileNumber=56;
            }
            else if(i>0 && i<29)
            {
                //Top wall
                if(j==0)
                    tileNumber=77;
                if(j>0 && j < 3)
                    tileNumber=0;
                if(j==3)
                    tileNumber=34;

                //Rest of the floor
                if(j>3 && j<15)
                    tileNumber = 25;

                //Bottom wall
                if(j==15)
                    tileNumber=52;

            }
            else if(i==29)
            {
                //RightWall
                if(j==0)
                    tileNumber=76;
                if(j>0 && j< 3)
                    tileNumber=126;
                if(j==3)
                    tileNumber=151;
                if(j>3 && j< 15)
                    tileNumber=176;
                if(j==15)
                    tileNumber=55;
            }

            tilesMapping[i+j*30]=tileNumber;
        }
    }
}

Room::~Room()
{
    //dtor
    delete id;

    for(Monster* m : monsters)
    {
        delete m;
    }
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

const int * Room::getTilesMapping() { return tilesMapping; }
list<Monster*> Room::getMonsters()const { return monsters; }

void Room::addMonster(Monster* monster)
{
    monsters.push_back(monster);
}

void Room::removeMonster(Monster* monster)
{
    monsters.remove(monster);
    delete monster;
}

void Room::generateNewMonster()
{
    int randMonster = rand() % 3;
    float randPosX = rand() %  1856 + 64;
    float randPosY = rand() %  760 + 192;

    switch(randMonster)
    {
        case 0 : this->addMonster(new Skeleton(randPosX, randPosY)); break;
    }
}
