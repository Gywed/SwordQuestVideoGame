#ifndef WEAPON_H
#define WEAPON_H
#include <vector>
#include <Monster.h>

using std::vector;

class Weapon
{
    public:
<<<<<<< HEAD
        Weapon(int cooldown = 0, float range = 0.0);
=======
        Weapon(int cooldown = 0, float range = 0.0, int damage = 0);
>>>>>>> origin/dev
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

<<<<<<< HEAD
        virtual int attack();

        static int getCompteur();
=======
        virtual void attack(vector<Monster*> monsters);

        void setDamage(int newDamage);
        int getDamage()const;

        static int getCompteur();
        int getId()const;
>>>>>>> origin/dev

    protected:

    private:
        // Cooldown de l'arme en ms
        int cooldown;
<<<<<<< HEAD


        float range;
=======
        float range;
        int damage;
>>>>>>> origin/dev

        // Pour pouvoir facilement gérer les armes
        int* id;

        inline static int compteur;
};

#endif // WEAPON_H
