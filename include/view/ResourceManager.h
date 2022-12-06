#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

using namespace std;

class ResourceManager
{
    private:
        vector< pair<string, sf::Texture*> > mainHeroTextures;
        vector< pair<string, sf::Texture*> > skeletonTextures;
        vector< pair<string, sf::Texture*> > slimeRoundTextures;
        vector< pair<string, sf::Texture*> > slimeLongTextures;

    public:
        ResourceManager();
        virtual ~ResourceManager();
        ResourceManager(const ResourceManager& other);
        ResourceManager& operator=(const ResourceManager& other);

        sf::Texture* searchMainHeroTexture(string fileName);
        sf::Texture* searchSkeletonTexture(string fileName);
        sf::Texture* searchSlimeRoundTexture(string fileName);
        sf::Texture* searchSlimeLongTexture(string fileName);

    protected:


};

#endif // RESOURCEMANGER_H
