#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ResourceManager
{
    private:
        static ResourceManager instance;

        std::map<std::string, sf::Font*> fonts;

    public:
        explicit ResourceManager();
        ~ResourceManager();

        // Make it non-copyable
        ResourceManager(const ResourceManager& resmgr) = delete;
        ResourceManager& operator= (const ResourceManager& resmgr) = delete;

        // Gets the instance of the resource manager.
        static ResourceManager& getInstance();

        // Loads a font into the fonts map if it doesn't exist.
        const sf::Font &loadFont(const std::string& filepath);
};
