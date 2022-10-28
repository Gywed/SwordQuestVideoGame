#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <Weapon.h>
#include <string>
#include <sstream>

using std::string;
using std::vector;

class Character
{
    public:
        Character();
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        string str() const;

    protected:

    private:
        int HP;
        vector<Weapon*> weapons;

};

#endif // CHARACTER_H
