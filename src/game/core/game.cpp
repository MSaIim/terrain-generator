#include "game.h"

Game::Game() { }

void Game::setup() { 
    ScreenManager::getInstance().addScreen(debugScreen);
}

const bool Game::update(const sf::Event& event, const float tickRate) {
    if (event.type == sf::Event::Closed) {
        return false;
    }

    ScreenManager::getInstance().update(event, tickRate);

    return true;
}

void Game::draw(Window& window, const float alpha) {
    window.clear();

    ScreenManager::getInstance().draw(window, alpha);
    window.renderImgui();

    window.display();
}

Game::~Game() { }
