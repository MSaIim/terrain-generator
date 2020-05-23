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

void Game::draw(const float alpha) {
    Graphics::getInstance().clear();

    ScreenManager::getInstance().draw(alpha);
    Graphics::getInstance().renderImgui();

    Graphics::getInstance().display();
}

Game::~Game() { }
