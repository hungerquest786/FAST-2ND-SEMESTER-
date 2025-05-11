#include<stdafx.h>
#include<Player.h>
using namespace std;



void Player :: render(sf:: RenderTarget &target){
    target.draw(this->sprite);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(2.0f);
    circle.setPosition(this->sprite.getPosition());

    target.draw(circle);
}

void Player::initTextures() {
    if (!this->texturesheet.loadFromFile("textures\\Idle.png")) {
        std::cout << "Error: idle texture could not load" << std::endl;
    }

    if (!this->textureRun.loadFromFile("textures\\Run.png")) {
        std::cout << "Error: run texture could not load" << std::endl;
    }

    if (!this->textureJump.loadFromFile("textures\\Jump.png")) {
        std::cout << "Error: jump texture could not load" << std::endl;
    }
}


void Player::initSprite() {
    this->sprite.setTexture(this->texturesheet);
    
    // Define the frame size based on the actual visible character
    // The sprite sheet has a 128x128 grid, but the actual character is smaller
    this->currentFrame = sf::IntRect(0, 0, 128, 128);
    
    // Set the texture rect for the sprite
    this->sprite.setTextureRect(this->currentFrame);
    
    // Scale the sprite to a reasonable size
    this->sprite.setScale(1.5f, 1.5f); 
    
    // Create a tighter hitbox that better matches the visible character
    sf::FloatRect spriteBounds = this->sprite.getGlobalBounds();
    
    // Create a much narrower hitbox that focuses on the central part of the sprite
    // This will allow the player to pass through narrow gaps
    this->hitbox = sf::FloatRect(
        spriteBounds.left + spriteBounds.width * 0.3f,  // 30% from left
        spriteBounds.top + spriteBounds.height * 0.1f,  // 10% from top
        spriteBounds.width * 0.4f,                      // 40% of total width (narrower)
        spriteBounds.height * 0.85f                     // 85% of total height
    );
}

Player :: Player (){
    initVariable();
    initTextures();
    initSprite();
    initAnimation();
    initPhysics();
    this->jumpPressed = false;
    this->isJumping = false; 
    this->jumpReleased = true;
    this->canJump = true;
}

Player :: ~Player (){

}

void Player :: updateMovement()
{
    if(this->velocity.x > 0.f)
    {
        this->animationState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
    }
    else if(this->velocity.x < 0.f)
    {
        this->animationState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
    }
    else
        this->animationState = PLAYER_ANIMATION_STATES::IDLE;

    if(this->velocity.y < 0.f)
    {
        this->animationState = PLAYER_ANIMATION_STATES::JUMPING;
    }
    else if (this->velocity.y > 1.f)
    {
        this->animationState = PLAYER_ANIMATION_STATES::FALLING;
    }
}

void Player :: update()
{
    this->updateMovement();
    this-> updateAnimation();
    this-> updatePhysics();
    this->updateHitbox();
}



void Player :: initVariable ()
{   
    this->animationState = PLAYER_ANIMATION_STATES :: IDLE;
    
}

void Player::updateAnimation() 
{
    if (this->animationState == PLAYER_ANIMATION_STATES::IDLE) 
    {
        // Use idle texture
        this->sprite.setTexture(this->texturesheet, false); // false = don't reset texture rect

        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimationSwitch()) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 128.f;

            if (this->currentFrame.left >= 640.f) {
                this->currentFrame.left = 0;
            }

            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    } 
    else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) 
    {
        // Use run texture
        this->sprite.setTexture(this->textureRun, false); // false = don't reset texture rect

        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimationSwitch()) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 128.f;

            if (this->currentFrame.left >= 640.f) {
                this->currentFrame.left = 0;
            }

            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
        
        this->sprite.setScale(1.5f, 1.5f); // Keep scale consistent
        this->sprite.setOrigin(0.f, 0.f);
    }
    else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT) 
    {
        // Use run texture
        this->sprite.setTexture(this->textureRun, false); // false = don't reset texture rect
    
        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimationSwitch()) {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 128.f;
    
            if (this->currentFrame.left >= 640.f) {
                this->currentFrame.left = 0;
            }
    
            this->animationtimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
        
        this->sprite.setScale(-1.5f, 1.5f); // Keep scale consistent, just flip horizontally
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 1.5f, 0.f);
    } 
    else if (this->animationState == PLAYER_ANIMATION_STATES::JUMPING || 
             this->animationState == PLAYER_ANIMATION_STATES::FALLING) 
    {
        // Use jump texture
        this->sprite.setTexture(this->textureJump, false); // false = don't reset texture rect
        
        if (this->animationtimer.getElapsedTime().asSeconds() >= 0.08f) { // slightly faster animation
            // Progress through frames based on jump phase
            if (this->velocity.y < 0.f) { // Rising
                // Start at frame 0 and progress to frame 4
                this->currentFrame.left += 128.f;
                
                // Cap at frame 4 during ascent
                if (this->currentFrame.left > 512.f) { // 4 * 128 = 512
                    this->currentFrame.left = 512.f;
                }
            } else { // Falling
                // Progress from frame 5 to 9
                if (this->currentFrame.left < 512.f) {
                    this->currentFrame.left = 512.f; // Start at frame 5 (5 * 128 = 640, but 512 is frame 4)
                }
                
                this->currentFrame.left += 128.f;
                
                // Loop back to frame 5 if we reach the end
                if (this->currentFrame.left >= 1280.f) {
                    this->currentFrame.left = 512.f;
                }
            }
            
            this->animationtimer.restart();
            this->currentFrame.top = 0.f;
            this->sprite.setTextureRect(this->currentFrame);
        }
        
        // Keep the scale and orientation consistent with movement direction
        if (this->velocity.x >= 0) {
            this->sprite.setScale(1.5f, 1.5f);
            this->sprite.setOrigin(0.f, 0.f);
        } else {
            this->sprite.setScale(-1.5f, 1.5f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 1.5f, 0.f);
        }
    }
    else 
    {
        this->animationtimer.restart();
    }

    // Fallback if no texture is set
    if (!this->sprite.getTexture()) {
        this->sprite.setTexture(this->texturesheet); // Default to idle texture if none is set
        this->currentFrame = sf::IntRect(0, 0, 128, 128);
        this->sprite.setTextureRect(this->currentFrame);
        this->sprite.setScale(1.5f, 1.5f); // Keep consistent scale
    }
    
    // Always update hitbox after any animation changes
    this->updateHitbox();
}


void Player :: initAnimation()
{
    this->animationtimer.restart();
    this->animationSwitch = true;
}

void Player::initPhysics() {
    this->velocityMax = 8.0f;        // Reduced horizontal speed for better control
    this->velocityMin = 1.0f;       // Lower threshold for stopping
    this->acceleration = 2.0f;      // Reduced acceleration for smoother movement
    this->drag = 0.85f;              // Less drag for more responsive controls
    this->gravity = 0.7f;           // Reduced gravity for slower falling
    this->velocityMaxY = 12.f;      // Reduced max falling speed
    this->canJump = false; 
}

const bool& Player::getAnimationSwitch()
{
    if(this->animationSwitch)
    {
        this->animationSwitch = false;
    }

    return animationSwitch;
}

void Player :: resetAnimationTimer()
{
    this->animationtimer.restart();
    this->animationSwitch = true;

    if (this->animationState == PLAYER_ANIMATION_STATES::IDLE) 
    {
        this->currentFrame.left = 0.f;
        this->currentFrame.top = 0.f;
        this->sprite.setTexture(this->texturesheet);
    } 
    else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT || 
               this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) 
    {
        this->currentFrame.left = 0.f;
        this->currentFrame.top = 0.f;
        this->sprite.setTexture(this->textureRun);
    }
    
    this->sprite.setTextureRect(this->currentFrame);
}


 void Player :: move (const float dir_x, const float dir_y)
 {
    //acceleration
    this->velocity.x += dir_x*acceleration;
    this->velocity.y += dir_y*acceleration;

    //limit velocity 
    if(std::abs(this->velocity.x) > this-> velocityMax)
    {
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f)?-1.f:1.f);
    }
 }

void Player::jump() {
    // Only jump when on ground (canJump is true)
    if (this->canJump && !this->isJumping) {
        this->velocity.y = -20.f;     // Moderate jump height
        this->canJump = false;        // Prevent jumping again until landing
        this->isJumping = true;       // Mark that we're jumping
        this->animationState = PLAYER_ANIMATION_STATES::JUMPING;

        // Reset jump animation frame
        this->currentFrame.left = 0.f;
        this->currentFrame.top = 0.f;
        this->animationtimer.restart();
    }
}

void Player::updatePhysics() 
{
    // Apply gravity
    this->velocity.y += this->gravity;

    // Cap the maximum fall speed
    if (this->velocity.y > this->velocityMaxY) {
        this->velocity.y = this->velocityMaxY;
    }

    // Deceleration
    if (std::abs(this->velocity.x) > 0.1f) {
        this->velocity.x *= this->drag;
    } else {
        this->velocity.x = 0.f; // Stop completely if very slow
    }

    // Apply the movement to the player
    this->sprite.move(this->velocity);
    
    this->updateHitbox();
    // Note: canJump is now managed in the Game::updateCollision method
    // It's set to true when player touches ground or platform
    // and set to false when player is in the air
}

 const sf::FloatRect Player :: globalbounds() const
 {
    return this->hitbox;
 }

 void Player :: setPosition(const float x, const float y)
 {
    this->sprite.setPosition(x,y);
 }

 void Player :: resetVelocityY()
 {
    this->velocity.y = 0.0f;
}

void Player :: resetVelocityX()
{
    this->velocity.x = 0.0f;
}

const sf::Vector2f Player :: getPosition() const
{
    return this->sprite.getPosition();
}

void Player::updateHitbox() {
    sf::FloatRect spriteBounds = this->sprite.getGlobalBounds();
    this->hitbox = sf::FloatRect(
        spriteBounds.left + spriteBounds.width * 0.3f,  // 30% from left
        spriteBounds.top + spriteBounds.height * 0.1f,  // 10% from top
        spriteBounds.width * 0.4f,                      // 40% of total width (narrower)
        spriteBounds.height * 0.85f                     // 85% of total height
    );
}
