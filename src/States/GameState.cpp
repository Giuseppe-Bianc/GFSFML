#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window) : State(window) { LINFO("init GameState"); }

GameState::~GameState() {}

void GameState::endState() { LINFO("ending GameState"); }

void GameState::updateKeyBinds(const float &dt) { this->checkForQuit(); }

void GameState::update(const float &dt) {
    this->updateKeyBinds(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        LINFO("A");
    }
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target) {}
