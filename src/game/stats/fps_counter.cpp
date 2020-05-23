#pragma once
#include "fps_counter.h"

FPSCounter::FPSCounter(): value(0), frame(0) {
    this->text.setFont(ResourceManager::getInstance().loadFont(FontPaths::HAPPY));
    this->text.setCharacterSize(26);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(15, 10);
}

const void FPSCounter::update() {
    if (this->clock.getElapsedTime().asSeconds() >= 1.f) {
        value = frame;
        frame = 0;
        this->clock.restart();
    }

    ++frame;
}

const int FPSCounter::getFpsValue() {
    this->update();
    return this->value;
}

const sf::Text& FPSCounter::getFpsText() {
    this->update();
    this->text.setString(std::to_string(this->value));
    return this->text;
}

FPSCounter::~FPSCounter() { }
