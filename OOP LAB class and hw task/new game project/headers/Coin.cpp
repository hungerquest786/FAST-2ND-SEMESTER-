#include "stdafx.h"
#include "Coin.h"

Coin::Coin(const float x, const float y, sf::Texture* texture)
{
    this->texture = texture;
    this->collected = false;
    
    // Setup sprite
    this->sprite.setTexture(*this->texture);
    sf::Vector2u texSize = texture->getSize();
    this->currentFrame = sf::IntRect(0, 0, texSize.x, texSize.y);
    this->sprite.setOrigin(texSize.x/2.f, texSize.y/2.f);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setPosition(x, y);
    this->sprite.setScale(0.09f, 0.09f); // Scale down the coin a bit
    
    this->initAnimation();
}

Coin::~Coin()
{
    // Nothing to destroy manually
}

void Coin::initAnimation()
{
    this->animationTimer.restart();
    this->animationSwitch = true;
}

const sf::FloatRect Coin::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f Coin::getPosition() const
{
    return this->sprite.getPosition();
}

const bool Coin::isCollected() const
{
    return this->collected;
}

void Coin::collect()
{
    this->collected = true;
}

void Coin::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Coin::update()
{
    if (!this->collected)
    {
        this->updateAnimation();
    }
}

void Coin::updateAnimation()
{
    // Animate coin spinning
    // if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
    // {
    //     this->currentFrame.left += 64; // Move to next frame
        
    //     // If we've reached the end of the spritesheet, loop back
    //     if (this->currentFrame.left >= 384) // 6 frames * 64 pixels
    //     {
    //         this->currentFrame.left = 0;
    //     }
        
    //     this->sprite.setTextureRect(this->currentFrame);
    //     this->animationTimer.restart();
    // }



    this->currentFrame = sf::IntRect(0, 0, 
    this->texture->getSize().x,
    this->texture->getSize().y);
    this->sprite.setTextureRect(this->currentFrame);


}

void Coin::render(sf::RenderTarget& target)
{
    if (!this->collected)
    {
        target.draw(this->sprite);
    }
}