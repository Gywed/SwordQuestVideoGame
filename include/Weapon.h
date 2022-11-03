#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
    public:
        Weapon(int cooldown = 0, float range = 0.0);
        virtual ~Weapon();
        Weapon(const Weapon& other);
        Weapon& operator=(const Weapon& other);

        virtual void attack();

        static int getCompteur();

    protected:

    private:
        // Cooldown de l'arme en ms
        int cooldown;


        float range;

        // Pour pouvoir facilement gérer les armes
        int* id;

        inline static int compteur;
};

#endif // WEAPON_H
