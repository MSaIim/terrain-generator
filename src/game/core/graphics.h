#pragma once
#include <SFML/Graphics.hpp>

class Graphics
{
    private:
        sf::RenderWindow *window = nullptr;

    public:
        explicit Graphics();
        ~Graphics();

        // Make it non-copyable
        Graphics(const Graphics &graphics) = delete;
        Graphics &operator=(const Graphics& graphics) = delete;

        // Gets the instance of the resource manager.
        static Graphics &getInstance();

        // Set the window to use
        void setWindow(sf::RenderWindow *window);

        // Draw functions
        void clear();
        void display();
        void draw(const sf::Drawable& drawable);
};
