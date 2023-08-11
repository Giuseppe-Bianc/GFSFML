#pragma once
#include "State.h"

class Game {
public:
    Game();
    virtual ~Game();

    // functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();

private:
    // variabili
    std::unique_ptr<sf::RenderWindow> window;
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt;

    // inizializzazione
    void initWindow();
};
