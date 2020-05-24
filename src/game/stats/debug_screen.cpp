#include "debug_screen.h"

DebugScreen::DebugScreen(): width(150), height(100), x(15), y(15) {
    this->title = ImGuiIds::DEBUG;
    this->isWindowVisible = true;
    this->flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;

    // Title settings
    this->titlePosition = ImVec2(0.5, 0.5);
    this->titleBgColor = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
    this->titleBgActiveColor = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
}

void DebugScreen::setup() {

}

void DebugScreen::update(const sf::Event& event, const float tickRate) {
    // TODO: Check if isWindowVisible should be updated
}

void DebugScreen::draw(Window& window, const float alpha) {
    const std::string fpsText = "FPS: " + std::to_string(this->fpsCounter.getFpsValue());

    if (this->isWindowVisible) {
        // Set imgui window options
        ImGui::SetNextWindowSize(ImVec2(this->width, this->height));
        ImGui::SetNextWindowPos(ImVec2(this->x, this->y));
        ImGui::SetNextWindowBgAlpha(0.2f);

        // Display imgui window
        ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, this->titlePosition);
        ImGui::PushStyleColor(ImGuiCol_TitleBgActive, this->titleBgColor);
        ImGui::PushStyleColor(ImGuiCol_TitleBg, this->titleBgActiveColor);
        ImGui::Begin(this->title.c_str(), (bool*) 0, this->flags);
        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();

        // Show details inside the imgui window
        ImGui::Text(fpsText.c_str());

        // End the window draw
        ImGui::End();
    }
}

DebugScreen::~DebugScreen() { }
