#pragma once
#include <SFML/Graphics.hpp>
#include "../core/resource_manager.h"
#include "../globals/constants.h"
#include <string>
#include <math.h>

class FPS 
{
    private:
        sf::Text text;
        sf::Clock clock;
        
        int fps;
        int frame;

        const void update();

    public:
        FPS();
        ~FPS();

        const sf::Text &getFps(const std::string &preText = "");
};
