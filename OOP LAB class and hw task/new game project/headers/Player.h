#pragma once
#include<stdafx.h>

enum PLAYER_ANIMATION_STATES{IDLE=0,MOVING_LEFT  , MOVING_RIGHT ,JUMPING, FALLING};

class Player {
    private:
        sf::Sprite sprite;
        sf::Texture texturesheet;
        sf::Texture textureRun;
        sf :: Clock animationtimer;
        sf :: Texture textureJump;
        sf::FloatRect hitbox; 
        float groundLevel;

        

        // core
        void initTextures();
        void initSprite();
        void initAnimation();
        void initVariable();
        void initPhysics();
        

        // movement

        //physics
        sf::Vector2f velocity;
        float velocityMax;
        float velocityMin;
        float acceleration;
        float drag;
        float gravity;
        float velocityMaxY;
        bool canJump;
        

        // animation
        short animationState;
        sf :: IntRect currentFrame;
        bool animationSwitch;

    //constructor
    public:
        Player();
        ~Player();

        //accessors
        const sf ::FloatRect globalbounds() const;
        const sf::Vector2f getPosition() const;
        const bool& getAnimationSwitch();
        bool jumpPressed; 
        bool jumpReleased;
        bool isJumping;

        // Inline Functions
        inline const bool& getCanJump() const {return this->canJump; }
        inline void setCanJump(const bool canJump) { this->canJump = canJump;}
        inline const sf::Vector2f& getVelocity() const { return this->velocity;}
        inline void setAnimationState(const short state) { this->animationState = state;}
        inline const short& getAnimationState() const { return this->animationState; }
        inline const sf::Sprite& getSprite() const { return this->sprite; }

        //modifiers
        void setPosition (const float x , const float y );
        void resetVelocityY();
        void resetVelocityX();

        //function 
        void resetAnimationTimer();
        void update();
        void render(sf:: RenderTarget &target);
        void updateMovement();
        void updateAnimation();
        void updatePhysics();
        void updateHitbox(); 
        void move(const float dir_x , const float dir_y);
        void jump();
   
};