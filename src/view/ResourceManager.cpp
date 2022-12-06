#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    string fileName;
    //MainHero
     fileName = "images/Animation/MainHero/Idle.png";
    sf::Texture mainHeroIdle;
    mainHeroIdle.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &mainHeroIdle));

     fileName = "images/Animation/MainHero/Movement.png";
    sf::Texture mainHeroMovement;
    mainHeroIdle.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &mainHeroMovement));

     fileName = "images/Animation/MainHero/Attack1.png";
    sf::Texture mainHeroSimpleAttack;
    mainHeroSimpleAttack.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &mainHeroSimpleAttack));

     fileName = "images/Animation/MainHero/Attack2.png";
    sf::Texture mainHeroHeavyAttack;
    mainHeroHeavyAttack.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &mainHeroHeavyAttack));

     fileName = "images/Animation/MainHero/Death.png";
    sf::Texture mainHeroDeath;
    mainHeroDeath.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &mainHeroDeath));



    //Skeleton
     fileName = "images/Animation/Skeleton/Idle.png";
    sf::Texture skeletonIdle;
    skeletonIdle.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &skeletonIdle));

     fileName = "images/Animation/Skeleton/Movement.png";
    sf::Texture skeletonMovement;
    skeletonMovement.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &skeletonMovement));

     fileName = "images/Animation/Skeleton/Attack1.png";
    sf::Texture skeletonSimpleAttack;
    skeletonSimpleAttack.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &skeletonSimpleAttack));

     fileName = "images/Animation/Skeleton/Death.png";
    sf::Texture skeletonDeath;
    skeletonDeath.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &skeletonDeath));


    //SlimeRound
     fileName = "images/Animation/SlimeRound/Idle.png";
    sf::Texture slimeRoundIdle;
    slimeRoundIdle.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeRoundIdle));

     fileName = "images/Animation/SlimeRound/Movement.png";
    sf::Texture slimeRoundMovement;
    slimeRoundMovement.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeRoundMovement));

     fileName = "images/Animation/SlimeRound/Attack1.png";
    sf::Texture slimeRoundSimpleAttack;
    slimeRoundSimpleAttack.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeRoundSimpleAttack));

     fileName = "images/Animation/SlimeRound/Death.png";
    sf::Texture slimeRoundDeath;
    slimeRoundDeath.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeRoundDeath));


    //SlimeLong
     fileName = "images/Animation/SlimeLong/Idle.png";
    sf::Texture slimeLongIdle;
    slimeLongIdle.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeLongIdle));

     fileName = "images/Animation/SlimeLong/Movement.png";
    sf::Texture slimeLongMovement;
    slimeLongMovement.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeLongMovement));

     fileName = "images/Animation/SlimeLong/Attack1.png";
    sf::Texture slimeLongSimpleAttack;
    slimeLongSimpleAttack.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeLongSimpleAttack));

     fileName = "images/Animation/SlimeLong/Death.png";
    sf::Texture slimeLongDeath;
    slimeLongDeath.loadFromFile(fileName);
    this->texturesList.insert(texturesList.end(), make_pair(fileName, &slimeLongDeath));

}

ResourceManager::~ResourceManager()
{
    //dtor
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
            std::cout<<"true"<<std::endl;
            return texture.second;
        }

    }
    return NULL;
}


