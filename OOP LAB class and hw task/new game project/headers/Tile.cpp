#include "stdafx.h"
#include "Tile.h"

Tile::Tile(const unsigned& gridPosX, const unsigned& gridPosY, const unsigned& tileSize,sf::Texture* textureSheet, sf::IntRect textureRect, bool damaging) 
    : damaging(damaging)
{
    this->sprite.setTexture(*textureSheet);
    this->sprite.setTextureRect(textureRect);
    this->sprite.setPosition(float(gridPosX * tileSize), float(gridPosY * tileSize));
}

const sf::FloatRect Tile::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

void Tile::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}