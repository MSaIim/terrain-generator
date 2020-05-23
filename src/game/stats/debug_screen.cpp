#include "debug_screen.h"

DebugScreen::DebugScreen(): width(150), height(100), x(15), y(15) {
    this->title = ImGuiIds::DEBUG;
    this->flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
}

void DebugScreen::update(const sf::Event& event, const float tickRate) {

}

void DebugScreen::draw(const float alpha) {
    const std::string fpsText = "FPS: " + std::to_string(this->fpsCounter.getFpsValue());

    // Set imgui window options
    ImGui::SetNextWindowSize(ImVec2(this->width, this->height));
    ImGui::SetNextWindowPos(ImVec2(this->x, this->y));
    ImGui::SetNextWindowBgAlpha(0.2f);

    // Display imgui window
    ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, ImVec2(0.5, 0.5));
    ImGui::Begin(this->title.c_str(), (bool*)0, this->flags);
    ImGui::PopStyleVar();

    // Show fps counter
    ImGui::Text(fpsText.c_str());

    // End the previous windows
    ImGui::End();
}

DebugScreen::~DebugScreen() { }
