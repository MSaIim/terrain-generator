#pragma once
#include <SFML/Graphics.hpp>
#include "../core/resource_manager.h"
#include "../globals/constants.h"
#include <string>
#include <math.h>

class FPSCounter
{
    private:
        sf::Text text;
        sf::Clock clock;
        
        int value;
        int frame;

        const void update();

    public:
        FPSCounter();
        ~FPSCounter();

        const int getFpsValue();
        const sf::Text& getFpsText();
};
