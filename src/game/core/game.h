#pragma once
#include "game_base.h"
#include "screen_manager.h"
#include "../stats/debug_screen.h"
#include "window.h"
#include <iostream>
#include <string>
#include <math.h>

class Game : public GameBase
{
    private: 
        DebugScreen debugScreen;

    public:
        Game();
        ~Game();

        // Sets up anything needed for the current game.
        void setup() override;

        // Updates anything needed for the game at the specified tick rate.
        const bool update(const sf::Event& event, const float tickRate) override;

        // Draws everything to the screen.
        void draw(Window& window, const float alpha) override;
};
