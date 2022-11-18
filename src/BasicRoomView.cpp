#include "BasicRoomView.h"
#include <iostream>

BasicRoomView::BasicRoomView()
{
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

    if (!this->tileMap.load("images/Tileset.png", sf::Vector2u(64, 64), this->tilesMapping, 30, 16))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
}

BasicRoomView::~BasicRoomView()
{
    //dtor
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
