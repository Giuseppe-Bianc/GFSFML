#pragma once
#include "headers.h"

class State {
public:
    State();
    virtual ~State();
    virtual void update() = 0;
    virtual void render() = 0;

private:
    std::vector<sf::Texture> textures;
};
