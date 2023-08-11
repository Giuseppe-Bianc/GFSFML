#include "Game.h"

Game::Game() { this->initWindow(); }

Game::~Game() {}

void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
    LINFO("dt {}", this->dt);
}

void Game::updateSFMLEvents() {
    while(this->window->pollEvent(this->sfEvent)) {
        switch(this->sfEvent.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::Resized:
            LINFO("resize to {}x{}", this->sfEvent.size.width, this->sfEvent.size.height);
            break;
        default:
            break;
        }
    }

    this->window->clear();
    this->window->display();
}

void Game::update() { this->updateSFMLEvents(); }

void Game::render() {
    this->window->clear();
    // render
    this->window->display();
}

void Game::run() {
    sf::Clock clock;
    while(this->window->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::initWindow() {
    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML RPG!",
                                                      sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
}
