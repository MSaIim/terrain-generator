#pragma once
#include "fps.h"

FPS::FPS(): fps(0), frame(0) { 
    this->text.setFont(ResourceManager::getInstance().loadFont(Fonts::HAPPY));
    this->text.setCharacterSize(26);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(15, 10);
}

const void FPS::update() {
    if (this->clock.getElapsedTime().asSeconds() >= 1.f)
    {
        fps = frame;
        frame = 0;
        this->clock.restart();
    }

    ++frame;
}

const sf::Text &FPS::getFps(const std::string& preText) {
    this->update();
    this->text.setString(preText + std::to_string(this->fps));

    return this->text;
}

FPS::~FPS() { }
