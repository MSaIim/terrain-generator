#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ResourceManager
{
    private:
        static ResourceManager instance;
        std::map<std::string, sf::Font*> fonts;
        std::map<std::string, sf::Texture*> textures;

    public:
        explicit ResourceManager();
        ~ResourceManager();

        // Make it non-copyable
        ResourceManager(const ResourceManager& resmgr) = delete;
        ResourceManager& operator=(const ResourceManager& resmgr) = delete;

        // Gets the instance of the resource manager.
        static ResourceManager& getInstance();

        // Loads a font into the fonts map if it doesn't exist.
        const sf::Font& loadFont(const std::string& filepath);

        // Loads a texture into the textures map if it doesn't exist.
        const sf::Texture& loadTexture(const std::string& filepath);
};
