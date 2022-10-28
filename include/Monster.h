#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
    public:
        Monster();
        virtual ~Monster();
        Monster(const Monster& other);
        Monster& operator=(const Monster& other);

    protected:

    private:
};

#endif // MONSTER_H
