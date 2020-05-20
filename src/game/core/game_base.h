#pragma once
#include <SFML/Graphics.hpp>
#include "window.h"
#include "graphics.h"

class GameBase
{
    private:
        Window window;

    protected:
        // Sets up anything needed for the window.
        virtual void setup() = 0;

        // Updates anything needed for the current class.
        virtual const bool update(const sf::Event event, const float tickRate) = 0;

        // Draws everything to the screen.
        virtual void draw(const float alpha) = 0;

    public:
        GameBase();
        ~GameBase();

        // Starts the game loop.
        const bool run();
};
