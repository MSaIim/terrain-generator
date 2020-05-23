#pragma once
#include "../core/screen.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../core/graphics.h"
#include "fps_counter.h"
#include "../globals/constants.h"
#include <string>

class DebugScreen : public Screen
{
    private:
        ImGuiWindowFlags flags;                 // ImGui window options

        std::string title;                      // Title of the screen
        float width;                            // The screen's width.
        float height;                           // The screen's height.
        float x;                                // The screen's x position.
        float y;                                // The screen's y position.

        // Debug items
        FPSCounter fpsCounter;

    public:
        DebugScreen();
        ~DebugScreen();

        void update(const sf::Event& event, const float tickRate) override;
        void draw(const float alpha) override;
};
