#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H
#include "Character.h"


class CharacterView
{
    private:
        Character* character;

    public:
        CharacterView();
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

        //Setters Getters
        Character* getCharacter()const;
        void setCharacter(int *Character);

        //Method
        void moveAnyDirection(sf::RenderWindow* window);


};

#endif // CHARACTERVIEW_H
