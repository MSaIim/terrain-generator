#pragma once
#include <SFML/Graphics.hpp>
#include "window.h"

class Screen
{
    public:
        Screen() { }
        virtual ~Screen() { }

        // Sets up anything needed for the screen.
        virtual void setup() = 0;

        // Updates anything needed for the screen at the specified tick rate.
        virtual void update(const sf::Event& event, const float tickRate) = 0;

        // Draws everything to the screen.
        virtual void draw(Window& window, const float alpha) = 0;
};
