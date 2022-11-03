#ifndef MONSTER_H
#define MONSTER_H

// include <Character.h> dans Monster.cpp, sinon ça fait des déclaration ciruclaire (Character include Weapon, Weapon include Monster, Monster include Character ... Boucled)
class Character;

class Monster
{
    public:
        Monster(int HP = 0, int damage = 0);
        virtual ~Monster();
        Monster(const Monster& other);
        Monster& operator=(const Monster& other);

        virtual void attack(Character* character);

        void getDamaged(int damage);

        void setDamage(int newDamage);
        int getDamage()const;

        static int getCompteur();
        int getId() const;

        void setHP(int newHP);
        int getHP() const;

    protected:

    private:
        int HP;
        int damage;
        bool dead;

        int* id;

        inline static int compteur;
};

#endif // MONSTER_H
