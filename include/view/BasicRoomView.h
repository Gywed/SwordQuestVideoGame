#ifndef BASICROOMVIEW_H
#define BASICROOMVIEW_H
#include "view/TileMap.h"
#include "model/Room.h"


class BasicRoomView
{
    private:
        TileMap tileMap;
        Room* room;


    public:
        BasicRoomView();
        virtual ~BasicRoomView();
        BasicRoomView(const BasicRoomView& other);
        BasicRoomView& operator=(const BasicRoomView& other);

        //Setters getter
        TileMap getTileMap()const;


};

#endif // BASICROOMVIEW_H
