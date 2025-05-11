#pragma once
#include <stdafx.h>

class Coin
{
private:
    sf::Sprite sprite;
    sf::Texture* texture;
    bool collected;
    sf::Clock animationTimer;
    sf::IntRect currentFrame;
    bool animationSwitch;

    void initAnimation();

public:
    Coin(const float x, const float y, sf::Texture* texture);
    ~Coin();

    // Accessors
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosition() const;
    const bool isCollected() const;

    // Modifiers
    void collect();
    void setPosition(const float x, const float y);

    // Functions
    void update();
    void updateAnimation();
    void render(sf::RenderTarget& target);
};