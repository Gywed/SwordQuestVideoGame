#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
    public:
        Weapon();
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

    protected:

    private:
};

#endif // WEAPON_H
