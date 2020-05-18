#include "graphics.h"

Graphics::Graphics() { }

Graphics &Graphics::getInstance() {
    static Graphics instance;
    return instance;
}

void Graphics::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void Graphics::clear() {
    this->window->clear();
}

void Graphics::display() {
    this->window->display();
}

void Graphics::draw(const sf::Drawable &drawable) {
    this->window->draw(drawable);
}

Graphics::~Graphics() { }
