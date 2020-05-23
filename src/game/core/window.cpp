#include "window.h"

Window::Window(): x(0), y(0), width(1400), height(900), title("Aegis Terrain Generator"), verticalSyncEnabled(true) {
    // Set window properties
    this->window.setVisible(false);

    // Create the window
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
    this->window.setVerticalSyncEnabled(verticalSyncEnabled);

    // Set to center screen
    auto desktopSize = sf::VideoMode::getDesktopMode();
    auto windowSize = this->window.getSize();
    this->window.setPosition(sf::Vector2i(desktopSize.width / 2 - windowSize.x / 2, desktopSize.height / 2 - windowSize.y / 2));

    // Set window icon
    sf::Image icon;
    icon.loadFromFile(ImagePaths::APP_ICON);
    this->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

sf::RenderWindow& Window::getRenderer() {
    return this->window;
}

const bool Window::pollEvent(sf::Event& event) {
    return this->window.pollEvent(event);
}

const void Window::setVisible(bool isVisible) {
    this->window.setVisible(isVisible);
}

const void Window::setTitle(const std::string& title) {
    this->window.setTitle(title);
}

const void Window::setSize(const unsigned int width, const unsigned int height) {
    this->width = width;
    this->height = height;
    this->window.setSize(sf::Vector2u(width, height));
}

const void Window::setPosition(const unsigned int x, const unsigned int y) {
    this->x = x;
    this->y = y;
    this->window.setPosition(sf::Vector2i(x, y));
}

const void Window::setVerticalSyncEnabled(bool isVerticalSyncEnabled) {
    this->verticalSyncEnabled = isVerticalSyncEnabled;
    this->window.setVerticalSyncEnabled(isVerticalSyncEnabled);
}

const void Window::close() {
    this->window.close();
}

Window::~Window() { }
