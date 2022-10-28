#ifndef ROOM_H
#define ROOM_H


class Room
{
    public:
        Room();
        virtual ~Room();
        Room(const Room& other);
        Room& operator=(const Room& other);

    protected:

    private:
};

#endif // ROOM_H
