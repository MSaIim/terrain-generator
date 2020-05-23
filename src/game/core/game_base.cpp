#include "game_base.h"

GameBase::GameBase() {
    Graphics::getInstance().setWindow(&this->window.getRenderer());

    // Load ImGui and set settings
    ImGui::SFML::Init(this->window.getRenderer(), false);
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF(FontPaths::ROBOTO.c_str(), 16.0f);
    ImGui::SFML::UpdateFontTexture();
}

const bool GameBase::run() {
    this->setup();
    this->window.setVisible(true);

    // Start the clocks
    sf::Clock imguiClock;
    const sf::Clock gameClock;

    // Fixed timestep initial setup
    float currentTime = gameClock.getElapsedTime().asMilliseconds() / 1000.0f;
    float accumulator = 0.0f;
    float tickRate = 1.0f / 240.0f;

    while (true) {
        // Capture the input events
        sf::Event event;
        while (this->window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                this->window.close();
            }
        }
        
        // Implement fixed time step
        const float newTime = gameClock.getElapsedTime().asMilliseconds() / 1000.0f;
        const float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator = (frameTime > 0.25) ? accumulator + 0.25f : accumulator + frameTime;

        // Update ImGui
        ImGui::SFML::Update(this->window.getRenderer(), imguiClock.restart());

        // Update at the specified tick rate
        while (accumulator >= tickRate) {
            if (!this->update(event, tickRate)) {
                return false;
            }

            accumulator -= tickRate;
        }

        // Draw everything
        const float alpha = accumulator / tickRate;
        this->draw(alpha);
    }

    return true;
}

GameBase::~GameBase() { 
    ImGui::SFML::Shutdown();
}
