#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H
// Size of Sprite
#define Sprite_Width 96
#define Sprite_Height 104

#include "SFML/Graphics.hpp"
#include "Character.h"
#include "Entity.h"


class CharacterView: public Entity
{
    private:
        Character* character;

        sf::IntRect* rectSourceSprite;

    public:
        CharacterView(Character *character);
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

        //Setters Getters
        Character* getCharacter()const;
        void setCharacter(Character* Character);
        sf::IntRect* getRectSourceSprite()const;
        void setRectSourceSprite(sf::IntRect* rectSourceSprite);

        //Method
        void moveAnyDirection(sf::RenderWindow* window);


};

#endif // CHARACTERVIEW_H
