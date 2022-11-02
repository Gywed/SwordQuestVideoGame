#ifndef SWORD_H
#define SWORD_H
#include <Weapon.h>


class Sword : public Weapon
{
    public:
        Sword(int cooldown = 500, float range = 1.0);
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

        int attack();

    private:

};

#endif // SWORD_H
