#include "resource_manager.h"

ResourceManager::ResourceManager() {}

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

const sf::Font& ResourceManager::loadFont(const std::string& filepath) {
    if (this->fonts.count(filepath) == 0) {
        sf::Font *font = new sf::Font();

        if (!font->loadFromFile(filepath.c_str())) {
            std::cout << "Error loading font file: " + filepath << std::endl;
        }

        this->fonts[filepath] = font;
    }

    return *this->fonts[filepath];
}

ResourceManager::~ResourceManager() {
    if (this->fonts.size() > 0) {
        for (auto& font : this->fonts) {
            delete font.second;
        }
        this->fonts.clear();
    }
}
