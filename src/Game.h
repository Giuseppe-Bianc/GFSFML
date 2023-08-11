#pragma once
#include "Timer.h"
#include "headers.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
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
