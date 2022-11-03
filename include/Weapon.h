#ifndef WEAPON_H
#define WEAPON_H
#include <vector>
#include <Monster.h>

using std::vector;

class Weapon
{
    public:

        Weapon(int cooldown = 0, float range = 0.0, int damage = 0);
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);


        virtual void attack(vector<Monster*> monsters);

        void setDamage(int newDamage);
        int getDamage()const;

        static int getCompteur();
        int getId()const;


    protected:

    private:
        // Cooldown de l'arme en ms
        int cooldown;

        float range;
        int damage;


        // Pour pouvoir facilement gérer les armes
        int* id;

        inline static int compteur;
};

#endif // WEAPON_H
