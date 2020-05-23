#include "screen_manager.h"

ScreenManager::ScreenManager() {}

ScreenManager& ScreenManager::getInstance() {
    static ScreenManager instance;
    return instance;
}

void ScreenManager::toggleScreen(Screen& screen) {
    bool isVisible = this->isScreenVisible(screen);

    if (isVisible) {
        this->removeScreen(screen);
    }
    else {
        this->addScreen(screen);
    }
}

void ScreenManager::addScreen(Screen& screen) {
    bool isVisible = this->isScreenVisible(screen);

    if (!isVisible) {
        this->screens.push_back(&screen);
    }
}

void ScreenManager::removeScreen(Screen& screen) {
    bool isVisible = false;

    for (unsigned int i = 0; i < this->screens.size() && !isVisible; i++) {
        if (this->screens[i] == &screen) {
            isVisible = true;
            this->screens.erase(this->screens.begin() + i);
        }
    }
}

const bool ScreenManager::isScreenVisible(Screen& screen) {
    bool isVisible = false;

    for (unsigned int i = 0; i < this->screens.size() && !isVisible; i++) {
        if (this->screens[i] == &screen) {
            isVisible = true;
        }
    }

    return isVisible;
}

void ScreenManager::update(const sf::Event& event, const float tickRate) {
    for (size_t i = this->screens.size() - 1; i != (size_t)-1; i--) {
        this->screens.at(i)->update(event, tickRate);
    }
}

void ScreenManager::draw(const float alpha) {
    for (unsigned int i = 0; i < this->screens.size(); i++) {
        this->screens.at(i)->draw(alpha);
    }
}

ScreenManager::~ScreenManager() { }
