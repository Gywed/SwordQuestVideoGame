#ifndef BASICROOMVIEW_H
#define BASICROOMVIEW_H
#include "TileMap.h"
#include "Room.h"


class BasicRoomView
{
    private:
        TileMap tileMap;
        Room* room;
        int tilesMapping[480];


    public:
        BasicRoomView();
        virtual ~BasicRoomView();
        BasicRoomView(const BasicRoomView& other);
        BasicRoomView& operator=(const BasicRoomView& other);

        //Setters getter
        TileMap getTileMap()const;


};

#endif // BASICROOMVIEW_H
