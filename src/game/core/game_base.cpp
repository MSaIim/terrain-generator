#include "game_base.h"

GameBase::GameBase() {
    Graphics::getInstance().setWindow(&this->window.getRenderer());
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
        this->window.getRenderer().pollEvent(event);

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
