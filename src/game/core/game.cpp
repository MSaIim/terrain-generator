#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"

Game::Game() { }

void Game::setup() {
    std::cout << "In Game setup!" << std::endl;
}

const bool Game::update(const sf::Event event, const float tickRate) {
    if (event.type == sf::Event::Closed)
        return false;

    return true;
}

void Game::draw(const float alpha) {
    Graphics::getInstance().clear();


    Graphics::getInstance().display();
}

Game::~Game() { }
