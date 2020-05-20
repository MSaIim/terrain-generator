#include "debug.h"

Debug::Debug() { }

Debug& Debug::getInstance() {
    static Debug instance;
    return instance;
}

const sf::Text &Debug::getFps(const std::string &preText) {
    return this->fps.getFps(preText);
}

Debug::~Debug() { }
