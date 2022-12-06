#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    string fileName;
    //MainHero
     fileName = "images/Animation/MainHero/Idle.png";
    sf::Texture* mainHeroIdle = new sf::Texture();
    mainHeroIdle->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, mainHeroIdle));

     fileName = "images/Animation/MainHero/Movement.png";
    sf::Texture* mainHeroMovement = new sf::Texture();
    mainHeroMovement->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, mainHeroMovement));

     fileName = "images/Animation/MainHero/Attack1.png";
    sf::Texture* mainHeroSimpleAttack = new sf::Texture();
    mainHeroSimpleAttack->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, mainHeroSimpleAttack));

     fileName = "images/Animation/MainHero/Attack2.png";
    sf::Texture* mainHeroHeavyAttack = new sf::Texture();
    mainHeroHeavyAttack->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, mainHeroHeavyAttack));

     fileName = "images/Animation/MainHero/Death.png";
    sf::Texture* mainHeroDeath = new sf::Texture();
    mainHeroDeath->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, mainHeroDeath));



    //Skeleton
     fileName = "images/Animation/Skeleton/Idle.png";
    sf::Texture* skeletonIdle = new sf::Texture();
    skeletonIdle->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, skeletonIdle));

     fileName = "images/Animation/Skeleton/Movement.png";
    sf::Texture* skeletonMovement = new sf::Texture();
    skeletonMovement->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, skeletonMovement));

     fileName = "images/Animation/Skeleton/Attack1.png";
    sf::Texture* skeletonSimpleAttack = new sf::Texture();
    skeletonSimpleAttack->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, skeletonSimpleAttack));

     fileName = "images/Animation/Skeleton/Death.png";
    sf::Texture* skeletonDeath = new sf::Texture();
    skeletonDeath->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, skeletonDeath));


    //SlimeRound
     fileName = "images/Animation/SlimeRound/Idle.png";
    sf::Texture* slimeRoundIdle = new sf::Texture();
    slimeRoundIdle->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeRoundIdle));

     fileName = "images/Animation/SlimeRound/Movement.png";
    sf::Texture* slimeRoundMovement = new sf::Texture();
    slimeRoundMovement->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeRoundMovement));

     fileName = "images/Animation/SlimeRound/Attack1.png";
    sf::Texture* slimeRoundSimpleAttack = new sf::Texture();
    slimeRoundSimpleAttack->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeRoundSimpleAttack));

     fileName = "images/Animation/SlimeRound/Death.png";
    sf::Texture* slimeRoundDeath = new sf::Texture();
    slimeRoundDeath->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeRoundDeath));


    //SlimeLong
     fileName = "images/Animation/SlimeLong/Idle.png";
    sf::Texture* slimeLongIdle = new sf::Texture();
    slimeLongIdle->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeLongIdle));

     fileName = "images/Animation/SlimeLong/Movement.png";
    sf::Texture* slimeLongMovement = new sf::Texture();
    slimeLongMovement->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeLongMovement));

     fileName = "images/Animation/SlimeLong/Attack1.png";
    sf::Texture* slimeLongSimpleAttack = new sf::Texture();
    slimeLongSimpleAttack->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeLongSimpleAttack));

     fileName = "images/Animation/SlimeLong/Death.png";
    sf::Texture* slimeLongDeath = new sf::Texture();
    slimeLongDeath->loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, slimeLongDeath));

}

ResourceManager::~ResourceManager()
{
    for(auto texture : texturesList)
        delete texture.second;
}

ResourceManager::ResourceManager(const ResourceManager& other)
{
    //copy ctor
}

ResourceManager& ResourceManager::operator=(const ResourceManager& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


sf::Texture* ResourceManager::searchTexturesList(string fileName)
{
    for(auto texture : texturesList)
    {
        if(texture.first==fileName)
        {
            return texture.second;
        }

    }
    return NULL;
}


