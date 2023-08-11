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
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned int frame_limit = 120;
    bool vertical_sync_enable = false;

    if(std::ifstream ifs("Config/window.ini"); ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> frame_limit;
        ifs >> std::boolalpha >> vertical_sync_enable;
    }

    this->window = std::make_unique<sf::RenderWindow>(window_bounds, title,
                                                      sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    this->window->setFramerateLimit(frame_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enable);
}
