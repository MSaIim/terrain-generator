#include "game.h"

Game::Game() { }

void Game::setup() { 
    ScreenManager::getInstance().addScreen(debugScreen);

    MapOptions mapOptions;
    mapOptions.worldWidth = 10;
    mapOptions.worldHeight = 10;
    mapOptions.tileData = { {DefaultMap::GRASS, 50}, {DefaultMap::WATER, 50} };
    MapGenerator::generate(mapOptions);
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
