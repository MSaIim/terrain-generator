#include "game.h"

Game::Game() { }

void Game::setup() { 
    ScreenManager::getInstance().addScreen(debugScreen);

    MapOptions mapOptions;
    mapOptions.worldWidth = 45;
    mapOptions.worldHeight = 30;
    mapOptions.sheetFilePath = SpriteSheetPaths::TEST_SPRITESHEET;
    mapOptions.sheetRows = 1;
    mapOptions.sheetColumns = 4;
    mapOptions.tileData = { 
        { DefaultMap::GRASS, 50 }, 
        { DefaultMap::WATER, 50 }
    };
    
    this->mapView.load(mapOptions, MapGenerator::generate(mapOptions));
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
    window.draw(this->mapView);
    window.renderImgui();

    window.display();
}

Game::~Game() { }
