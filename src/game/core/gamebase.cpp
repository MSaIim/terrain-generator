#pragma once
#include "gamebase.h"

GameBase::GameBase(): window(sf::VideoMode(0, 0), "", sf::Style::Titlebar | sf::Style::Close) {
    // Set window properties
    this->window.setVisible(false);
    this->window.setSize(sf::Vector2u(800, 600));
    this->window.setTitle("Aegis Terrain Generator");
    this->window.setVerticalSyncEnabled(true);

    // Set to center screen
    auto desktopSize = sf::VideoMode::getDesktopMode();
    auto windowSize = this->window.getSize();
    this->window.setPosition(sf::Vector2i(desktopSize.width / 2 - windowSize.x / 2, desktopSize.height / 2 - windowSize.y / 2));

    // Set window icon
    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    this->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Let the graphics instance use the window
    Graphics::getInstance().setWindow(&this->window);
}

const bool GameBase::run() {
    this->setup();
    this->window.setVisible(true);

    // Start the clock
    const sf::Clock clock;

    // Fixed timestep initial setup
    float currentTime = clock.getElapsedTime().asMilliseconds() / 1000.0f;
    float accumulator = 0.0f;
    float tickRate = 1.0f / 240.0f;

    while (true) {
        // Capture the input events
        sf::Event event;
        this->window.pollEvent(event);

        // Implement fixed time step
        const float newTime = clock.getElapsedTime().asMilliseconds() / 1000.0f;
        const float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator = (frameTime > 0.25) ? accumulator + 0.25f : accumulator + frameTime;

        // Update at the specified tick rate
        while (accumulator >= tickRate) {
            if (!this->update(event, tickRate)) {
                return false;
            }

            accumulator -= tickRate;
        }

        const float alpha = accumulator / tickRate;
        this->draw(alpha);
    }

    return true;
}

GameBase::~GameBase() { }
