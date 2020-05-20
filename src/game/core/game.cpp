#include "game.h"

Game::Game() { }

void Game::setup() { }

const bool Game::update(const sf::Event event, const float tickRate) {
    if (event.type == sf::Event::Closed)
        return false;

    return true;
}

void Game::draw(const float alpha) {
    Graphics::getInstance().clear();
    Graphics::getInstance().draw(Debug::getInstance().getFps("FPS: "));
    Graphics::getInstance().display();
}

Game::~Game() { }
