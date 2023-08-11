#include "GameState.h"

GameState::GameState(std::shared_ptr<sf::RenderWindow> window) : State(window) { LINFO("init GameState"); }

GameState::~GameState() {}

void GameState::endState() {}

void GameState::update(const float &dt) {}

void GameState::render(std::shared_ptr<sf::RenderTarget> target) {}
