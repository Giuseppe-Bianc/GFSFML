#pragma once
#include "../headers.h"

class State {
public:
    explicit State(std::shared_ptr<sf::RenderWindow> window);
    virtual ~State();

    const bool &getQuit() const;
    virtual void checkForQuit();
    virtual void endState() = 0;
    virtual void updateKeyBinds(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;

private:
    std::vector<sf::Texture> textures;
    std::shared_ptr<sf::RenderWindow> window;
    bool quit;
};
