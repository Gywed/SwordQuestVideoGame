#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
    public:
        Monster(int HP = 0);
        virtual ~Monster();
        Monster(const Monster& other);
        Monster& operator=(const Monster& other);

        virtual void attack();

        static int getCompteur();


    protected:

    private:
        int HP;

        int* id;

        inline static int compteur;
};

#endif // MONSTER_H
