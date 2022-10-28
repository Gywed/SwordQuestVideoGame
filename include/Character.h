#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    public:
        Character();
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);

    protected:

    private:
};

#endif // CHARACTER_H
