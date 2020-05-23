#pragma once
#include <SFML/Graphics.hpp>

class Screen
{
    public:
        Screen() { }
        virtual ~Screen() { }

        // Updates anything needed for the game at the specified tick rate.
        virtual void update(const sf::Event& event, const float tickRate) = 0;

        // Draws everything to the screen.
        virtual void draw(const float alpha) = 0;
};
