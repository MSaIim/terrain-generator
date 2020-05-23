#include "graphics.h"

Graphics::Graphics() { }

Graphics& Graphics::getInstance() {
    static Graphics instance;
    return instance;
}

void Graphics::setWindow(sf::RenderWindow* window) {
    this->window = window;
}

void Graphics::clear() {
    this->window->clear();
}

void Graphics::display() {
    this->window->display();
}

const void Graphics::renderImgui() {
    ImGui::SFML::Render(*this->window);
}

void Graphics::draw(const sf::Drawable& drawable, const sf::RenderStates& states) {
    this->window->draw(drawable, states);
}

void Graphics::draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type, const sf::RenderStates& states) {
    this->window->draw(vertices, vertexCount, type, states);
}

void Graphics::draw(const sf::VertexBuffer& vertexBuffer, const sf::RenderStates& states) {
    this->window->draw(vertexBuffer, states);
}

void Graphics::draw(const sf::VertexBuffer& vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const sf::RenderStates& states) {
    this->window->draw(vertexBuffer, firstVertex, vertexCount, states);
}

Graphics::~Graphics() { }
