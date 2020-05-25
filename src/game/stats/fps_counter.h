#pragma once
#include <SFML/Graphics.hpp>
#include "../core/resource_manager.h"
#include "../globals/constants.h"
#include <math.h>

class FpsCounter
{
    private:
        sf::Text text;
        sf::Clock clock;
        
        int value;
        int frame;

        const void update();

    public:
        FpsCounter();
        ~FpsCounter();

        const int getFpsValue();
};
