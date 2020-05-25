#pragma once
#include "window.h"
#include "screen.h"

class ScreenManager
{
    private:
        static ScreenManager instance;       // Singleton object.
        std::vector<Screen*> screens;        // Screen map to know which screen to draw and update first.

    public:
        explicit ScreenManager();
        ~ScreenManager();

        // Make it non-copyable
        ScreenManager(const ScreenManager& scnmgr) = delete;
        ScreenManager& operator=(const ScreenManager& scnmgr) = delete;

        // Gets the instance of the screen manager.
        static ScreenManager& getInstance();

        // Checks if the screen is visible
        const bool isScreenVisible(Screen& screen);

        // Toggles a screen to or from the screen list.
        void toggleScreen(Screen& screen);

        // Adds a screen to the screen list.
        void addScreen(Screen& screen);

        // Removes a screen from the screen list.
        void removeScreen(Screen& screen);

        // Updates the all the screens in the list in reverse order (last added screen updates first).
        void update(const sf::Event& event, const float tickRate);

        // Draws all the screens in the list in the order they were added.
        void draw(Window& window, const float alpha);
};
