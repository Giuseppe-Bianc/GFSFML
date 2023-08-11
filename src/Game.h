#pragma once
#include "States/GameState.h"

class Game {
public:
    Game();
    virtual ~Game();

    // functions
    void endApplication();

    void updateDt();
    void updateSFMLEvents();
    void update();

    void render();

    void run();

private:
    // variabili
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt;
    std::stack<std::unique_ptr<State>> states;

    // inizializzazione
    void initWindow();
    void initStates();
};
