#pragma once
#include <SFML/Graphics.hpp>
#include "../globals/constants.h"
#include <string>

class Window
{
    private:
        sf::RenderWindow window;            // The actual window.

        int width;                          // The window's width.
        int height;                         // The window's height.
        int x;                              // The window's x position.
        int y;                              // The window's y position.

        std::string title;                  // The window's title.
        bool verticalSyncEnabled;           // Boolean holding the vertical sync property.

    public:
        Window();
        ~Window();

        // Gets the window's renderer.
        sf::RenderWindow& getRenderer();

        // Unhides the window.
        const void setVisible(bool isVisible);

        // Sets the window's title.
        const void setTitle(const std::string& title);

        // Sets the window's size.
        const void setSize(const unsigned int width, const unsigned int height);

        // Sets the window's position.
        const void setPosition(const unsigned int x, const unsigned int y);

        // Toggles vertical sync
        const void setVerticalSyncEnabled(bool isVerticalSyncEnabled);
};
