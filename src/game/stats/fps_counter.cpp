#pragma once
#include "fps_counter.h"

FpsCounter::FpsCounter(): value(0), frame(0) {
    this->text.setFont(ResourceManager::getInstance().loadFont(FontPaths::HAPPY));
    this->text.setCharacterSize(26);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(15, 10);
}

const void FpsCounter::update() {
    if (this->clock.getElapsedTime().asSeconds() >= 1.f) {
        value = frame;
        frame = 0;
        this->clock.restart();
    }

    ++frame;
}

const int FpsCounter::getFpsValue() {
    this->update();
    return this->value;
}

FpsCounter::~FpsCounter() { }
