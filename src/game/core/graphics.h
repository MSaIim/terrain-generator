#pragma once
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class Graphics
{
    private:
        sf::RenderWindow* window = nullptr;

    public:
        explicit Graphics();
        ~Graphics();

        // Make it non-copyable
        Graphics(const Graphics& graphics) = delete;
        Graphics &operator=(const Graphics& graphics) = delete;

        // Gets the instance of the resource manager.
        static Graphics& getInstance();

        // Set the window to use
        void setWindow(sf::RenderWindow* window);

        // Clear and display
        void clear();
        void display();

        // Draw functions
        const void renderImgui();

        void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
        void draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default);
        void draw(const sf::VertexBuffer& vertexBuffer, const sf::RenderStates& states = sf::RenderStates::Default);
        void draw(const sf::VertexBuffer& vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates& states = sf::RenderStates::Default);
};
