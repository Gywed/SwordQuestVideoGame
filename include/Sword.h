#ifndef SWORD_H
#define SWORD_H
#include <Weapon.h>


class Sword : public Weapon
{
    public:
        Sword();
        virtual ~Sword();
        Sword(const Sword& other);
        Sword& operator=(const Sword& other);

    protected:

    private:
};

#endif // SWORD_H
