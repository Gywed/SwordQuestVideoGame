#include "Character.h"

Character::Character()
{
    HP = 10;
}

Character::~Character()
{
    //dtor
    for (Weapon* weapon : weapons)
        delete weapon;
}

Character::Character(const Character& other)
{
    //copy ctor
    this->HP = other.HP;


    for (Weapon* weapon : other.weapons)
    {
        this->weapons.push_back(new Weapon(*weapon));
    }
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->HP = rhs.HP;

    for (Weapon* weapon : weapons)
        delete weapon;
    for (Weapon* weapon : rhs.weapons)
    {
        this->weapons.push_back(new Weapon(*weapon));
    }

    return *this;
}

void Character::getDamaged(int damage)
{
    int newHP = getHP() - damage;

    if (newHP <= 0)
    {
        setHP(0);
    }
    else
        setHP(newHP);
}

void Character::setHP(int newHP)
{
    this->HP = newHP;
}

int Character::getHP() const
{
    return this->HP;
}

string Character::str() const {
    std::stringstream ss;
    ss << HP;
    return ss.str();
}
