#ifndef SWORD_H
#define SWORD_H
#include <Weapon.h>


class Sword : public Weapon
{
    public:
<<<<<<< HEAD
        Sword(int cooldown = 500, float range = 1.0);
=======
        Sword(int cooldown = 500, float range = 1.0, int damage = 1);
>>>>>>> origin/dev
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

<<<<<<< HEAD
        int attack();
=======
        void attack(vector<Monster*> monsters);
>>>>>>> origin/dev

    private:

};

#endif // SWORD_H
