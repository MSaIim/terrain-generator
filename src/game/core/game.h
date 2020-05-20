#pragma once
#include "game_base.h"
#include "../debug/debug.h"
#include <iostream>
#include <string>
#include <math.h>

class Game : public GameBase
{      
    public:
        Game();
        ~Game();

        // Sets up anything needed for the current game.
        void setup() override;

        // Updates anything needed for the game at the specified tick rate.
        const bool update(const sf::Event event, const float tickRate) override;

        // Draws everything to the screen.
        void draw(const float alpha) override;
};
