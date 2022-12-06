#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

using namespace std;

class ResourceManager
{
    private:
        vector< pair<string, sf::Texture*> > texturesList;

    public:
        ResourceManager();
        virtual ~ResourceManager();
        ResourceManager(const ResourceManager& other);
        ResourceManager& operator=(const ResourceManager& other);

        sf::Texture* searchTexturesList(string fileName);


    protected:


};

#endif // RESOURCEMANGER_H
