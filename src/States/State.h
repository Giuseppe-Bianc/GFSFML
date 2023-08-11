#pragma once
#include "../headers.h"

class State {
public:
    explicit State(std::shared_ptr<sf::RenderWindow> window);
    virtual ~State();
    virtual void endState() = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;

private:
    std::vector<sf::Texture> textures;
    std::shared_ptr<sf::RenderWindow> window;
};
