#pragma once
#include <stdafx.h>

class Tile
{
    sf::Sprite sprite;
    const bool damaging;

    public:
        Tile(const unsigned& gridPosX, const unsigned& gridPosY, const unsigned& tileSize,sf::Texture* textureSheet, sf::IntRect textureRect, bool damaging = false);

        const sf::FloatRect getGlobalBounds() const;

        void update();
        void render(sf::RenderTarget& target);
    
        void setPosition(const float x, const float y);
        void setTexture(sf::Texture* texture, sf::IntRect textureRect);

};