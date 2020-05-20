#pragma once
#include <SFML/Graphics.hpp>
#include "fps.h"
#include <string>

class Debug
{
    private:
        FPS fps;

    public:
        explicit Debug();
        ~Debug();

        // Make it non-copyable
        Debug(const Debug& graphics) = delete;
        Debug& operator=(const Debug& graphics) = delete;

        // Gets the instance of the resource manager.
        static Debug& getInstance();

        // Debug options
        const sf::Text &getFps(const std::string &preText = "");
};
