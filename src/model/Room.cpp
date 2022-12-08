#include "model/Room.h"
#include "model/Skeleton.h"
#include "model/SlimeRound.h"
#include "model/SlimeLong.h"

Room::Room()
{
    //Iniate default tiles mapping
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

    //Carpet
    for(int i = 4; i<26; i++)
    {
        for(int j = 5; j<14; j++)
        {

            tilesMapping[i+j*30]=293;
        }
    }

    //Fire place

    //Big door
    tilesMapping[9+2*30]=127;
    tilesMapping[10+2*30]=128;
    tilesMapping[19+2*30]=127;
    tilesMapping[20+2*30]=128;

    //Big door top decoration
    tilesMapping[9+1*30]=248;
    tilesMapping[10+1*30]=273;
    tilesMapping[19+1*30]=274;
    tilesMapping[20+1*30]=249;


    //Top banner
    tilesMapping[8+1*30]=99;
    tilesMapping[11+1*30]=99;
    tilesMapping[18+1*30]=99;
    tilesMapping[21+1*30]=99;

    //Bottom banner
    tilesMapping[8+2*30]=124;
    tilesMapping[11+2*30]=124;
    tilesMapping[18+2*30]=124;
    tilesMapping[21+2*30]=124;

    //Bookcase
    tilesMapping[14+2*30]=221;
    tilesMapping[14+3*30]=246;
    tilesMapping[15+2*30]=222;
    tilesMapping[15+3*30]=247;

    //Bookcase top decoration
    tilesMapping[14+1*30]=229;
    tilesMapping[15+1*30]=229;

    //Jason painting
    tilesMapping[12+1*30]=226;
    tilesMapping[13+1*30]=227;

    //Inner carpet
    for(int i=5; i<25; i++)
        for(int j=6; j<13; j++)
        {
            if(i==5)
            {
                if(j==6)
                    tileNumber=264;
                else if(j>6 && j<12)
                    tileNumber=289;
                else if(j==12)
                    tileNumber=241;
            }
            else if(i>5 && i<24)
            {
                if(j==6)
                    tileNumber=262;
                else if(j==12)
                    tileNumber=237;
                else
                    tileNumber=40;
            }
            else if(i==24)
            {
                if(j==6)
                    tileNumber=263;
                else if(j>6 && j<12)
                    tileNumber=288;
                else if(j==12)
                    tileNumber=240;
            }
            tilesMapping[i+j*30]=tileNumber;
        }
}

Room::~Room()
{
    //dtor
    for(Monster* m : monsters)
    {
        delete m;
    }
}

Room::Room(const Room& other)
{
    //copy ctor
    for (int i = 0; i < Nb_Tile; i++)
        this->tilesMapping[i] = other.tilesMapping[i];

    for (Monster* monster : other.monsters)
        this->monsters.push_back(new Monster(*monster));

}

Room& Room::operator=(const Room& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    for (int i = 0; i < Nb_Tile; i++)
        this->tilesMapping[i] = rhs.tilesMapping[i];

    for (Monster* monster : monsters)
        delete monster;

    for (Monster* monster : rhs.monsters)
        this->monsters.push_back(new Monster(*monster));

    return *this;
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

Monster* Room::generateNewMonster()
{
    int randMonster = rand() % 3;
    float randPosX = rand() %  1856 + 64;
    float randPosY = rand() %  760 + 192;

    Monster* monster;
    switch(randMonster)
    {
        case 0 : monster = new Skeleton(randPosX, randPosY); break;
        case 1 : monster = new SlimeRound(randPosX, randPosY); break;
        case 2 : monster = new SlimeLong(randPosX, randPosY); break;
    }

    this->addMonster(monster);
    return monster;
}
