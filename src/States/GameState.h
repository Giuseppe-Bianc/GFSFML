#pragma once
#include "State.h"

class GameState : public State {
public:
    explicit GameState(std::shared_ptr<sf::RenderWindow> window);

    virtual ~GameState();
    virtual void endState();
    void updateKeyBinds(const float &dt) final;
    virtual void update(const float &dt);
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr);

private:
};
