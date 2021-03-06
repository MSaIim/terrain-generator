#pragma once
#include "imgui.h"
#include "../core/window.h"
#include "../core/screen.h"
#include "../globals/constants.h"
#include "fps_counter.h"
#include <string>

class DebugScreen : public Screen
{
    private:
        ImGuiWindowFlags flags;                 // ImGui window options
        bool isWindowVisible;

        std::string title;                      // Title of the screen
        float width;                            // The screen's width.
        float height;                           // The screen's height.
        float x;                                // The screen's x position.
        float y;                                // The screen's y position.

        // ImGui title options
        ImVec2 titlePosition;
        ImVec4 titleBgColor;
        ImVec4 titleBgActiveColor;

        // Debug items
        FpsCounter fpsCounter;

    public:
        DebugScreen();
        ~DebugScreen();

        void setup() override;
        void update(const sf::Event& event, const float tickRate) override;
        void draw(Window& window, const float alpha) override;
};
