#include "stdafx.h"
#include "Game.h"
#include<sstream>
using namespace std;

// Initialize window settings
void Game::initWindow() 
{
    this->window.create(sf::VideoMode(1600, 900), "Mario on its peak", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);
}

void Game::initPlayer() {
    this->player = new Player();
    
    // Calculate appropriate starting position
    // Place player on ground at left side of screen
    float groundLevel = this->window.getSize().y - 50.f; // Match ground level from collision detection
    float playerHeight = this->player->globalbounds().height;
    
    // Position player at left side of screen, standing on ground
    this->player->setPosition(100.f, groundLevel - playerHeight);
}

void Game::initInput()
{
    // Mouse Bindings
    this->mouseMappings["BTN_ADD_TILE"] = sf::Mouse::Left;
    this->mouseMappings["BTN_REMOVE_TILE"] = sf::Mouse::Right;

    // Keyboard Bindings
    this->keyboardMappings["KEY_MOVE_LEFT"] = sf::Keyboard::A;
    this->keyboardMappings["KEY_MOVE_RIGHT"] = sf::Keyboard::D;
    this->keyboardMappings["KEY_MOVE_UP"] = sf::Keyboard::W;
    this->keyboardMappings["KEY_MOVE_DOWN"] = sf::Keyboard::S;
    this->keyboardMappings["KEY_JUMP"] = sf::Keyboard::Space;
}

void Game::initTileSheet()
{
    if (!this->tileSheet.loadFromFile("textures\\Tile.jpeg")) {
        std::cout << "Error:: Game Class :: tile sheet could not load" << std::endl;
    }
    
    if (!this->coinTexture.loadFromFile("textures\\coinn.png")) {
        std::cout << "Error:: Game Class :: coin texture could not load" << std::endl;
    }
}

void Game::initTileMap()
{
    this->tileMap = new TileMap(32, 18, &this->tileSheet, 50);
    this->createPlatforms();
}

void Game::createPlatforms() 
{
    int tileSize = this->tileMap->getTileSize();
    int groundY = (this->window.getSize().y - 50) / tileSize; // Position at the red line
    
    // Add ground tiles across the entire width of the screen
    int numTilesX = this->window.getSize().x / tileSize;
    for (int i = 0; i < numTilesX + 1; i++) { // +1 to ensure complete coverage
        this->tileMap->addTile(i, groundY);
    }

    for (int i = 5; i < 10; i++) {
        this->tileMap->addTile(i, 13);
    }
    
    // Platform 2 - middle platform in center
    for (int i = 15; i < 20; i++) {
        this->tileMap->addTile(i, 9);
    }
    
    // Platform 3 - high platform right side
    for (int i = 25; i < 30; i++) {
        this->tileMap->addTile(i, 5);
    }
}

void Game::initCoins()
{
    for (auto& coin : this->coins) {
        delete coin;
    }
    this->coins.clear();
    
    float tileSize = this->tileMap->getTileSize();
    
    // Just add a few coins above each platform
    
    // Coins for Platform 1
    this->addCoin(6 * tileSize, 13 * tileSize - 75.f);
    this->addCoin(8 * tileSize, 13 * tileSize - 75.f);
    
    // Coins for Platform 2
    this->addCoin(16 * tileSize, 9 * tileSize - 75.f);
    this->addCoin(18 * tileSize, 9 * tileSize - 75.f);
    
    // Coins for Platform 3
    this->addCoin(26 * tileSize, 5 * tileSize - 75.f);
    this->addCoin(28 * tileSize, 5 * tileSize - 75.f);
}

void Game::addCoin(float x, float y)
{
    Coin* coin = new Coin(x, y, &this->coinTexture);
    this->coins.push_back(coin);
}

void Game::initGUI()
{
    this->score = 0;
    
    // Load font
    if (!this->font.loadFromFile("fonts\\ARIAL.TTF")) {
        std::cout << "Error:: Game Class :: font could not load" << std::endl;
    }
    
    // Setup score text
    this->scoreText.setFont(this->font);
    this->scoreText.setString("Coins: 0");
    this->scoreText.setCharacterSize(30);
    this->scoreText.setFillColor(sf::Color::Yellow);
    this->scoreText.setPosition(20.f, 20.f);
}

Game::Game() {
    this->score = 0;
    this->initWindow();
    this->initInput();
    this->initTileSheet();
    this->initBackground();
    this->initTileMap();
    this->initPlayer();
    this->initCoins();
    this->initGUI();
}

// Destructor
Game::~Game() {
    delete this->player;
    delete this->tileMap;
    
    // Clean up coins
    for (auto& coin : this->coins) {
        delete coin;
    }
    this->coins.clear();
}

void Game::updateInput() {
    // Player Movement Update
    if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_LEFT"])) {
        this->player->move(-1.0f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_MOVE_RIGHT"])) {
        this->player->move(1.0f, 0.f);
    }

    // Check for jump key
    if (sf::Keyboard::isKeyPressed(this->keyboardMappings["KEY_JUMP"])) {
        // Check if key wasn't pressed before to prevent continuous jumping
        if (!this->player->jumpPressed && this->player->jumpReleased) {
            this->player->jumpPressed = true;
            this->player->jumpReleased = false;
            this->player->jump(); // This will check canJump internally
        }
    } else {
        // Key was released
        this->player->jumpPressed = false;
        this->player->jumpReleased = true;
    }
}

// Accessor for the window
const sf::RenderWindow& Game::getwindow() const {
    return this->window;
}

// Update game logic and handle events
void Game::update() {
    // polling window event 
    while (window.pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Escape)
        {
            // Add pause menu or exit
        }
    }

    this->updateInput();
    this->updatePlayer();
    this->updateCollision();
    this->updateTileMap();
    this->updateCoins();
    this->checkCoinCollisions();
    this->updateGUI();
}

// Render game objects (draw to the window)
void Game::render() 
{
    this->window.clear(sf::Color::Black);

    // Render Background first
    this->window.draw(this->backgroundSprite);
    this->renderTileMap();
    this->renderCoins();
    this->renderPlayer();
    this->renderGUI();

    //this->renderDebug();
    
    this->window.display();
}

void Game::updatePlayer() {
    this->player->update();
}

void Game::renderPlayer() {
    this->player->render(this->window);
}

void Game::updateCoins()
{
    for (auto& coin : this->coins) {
        coin->update();
    }
}

void Game::renderCoins()
{
    for (auto& coin : this->coins) {
        coin->render(this->window);
    }
}

void Game::updateGUI()
{
    std::stringstream ss;
    ss << "Coins: " << this->score;
    this->scoreText.setString(ss.str());
}

void Game::renderGUI()
{
    this->window.draw(this->scoreText);
}

void Game::checkCoinCollisions()
{
    for (auto& coin : this->coins) {
        if (!coin->isCollected() && this->player->globalbounds().intersects(coin->getGlobalBounds())) {
            coin->collect();
            this->score++;
        }
    }
}

void Game::updateCollision() {
    // Start with player not on ground
    bool onGround = false;
    
    // IMPORTANT: Make sure we use the hitbox bounds (green), not sprite bounds (blue)
    sf::FloatRect playerBounds = this->player->globalbounds(); // This gets the green hitbox
    
    // Get player position and velocity
    sf::Vector2f playerPos = this->player->getPosition();
    sf::Vector2f playerVel = this->player->getVelocity();
    
    // Store original position to detect if we've made changes
    sf::Vector2f originalPosition = playerPos;
    
    // =============== PLATFORM COLLISION HANDLING ===============
    
    // Calculate player grid position
    float tileSize = static_cast<float>(this->tileMap->getTileSize());
    int startX = static_cast<int>(playerBounds.left / tileSize) - 1;
    int endX = static_cast<int>((playerBounds.left + playerBounds.width) / tileSize) + 1;
    int startY = static_cast<int>(playerBounds.top / tileSize) - 1;
    int endY = static_cast<int>((playerBounds.top + playerBounds.height) / tileSize) + 1;
    
    // First pass: Check for grounding collisions (bottom of player)
    // This check has priority to ensure landing on platforms works consistently
    for (int x = startX; x <= endX; x++) {
        for (int y = startY; y <= endY; y++) {
            Tile* tile = this->tileMap->getTile(x, y);
            if (tile) {
                sf::FloatRect tileBounds = tile->getGlobalBounds();
                
                // Skip tiles that are definitely not relevant for grounding
                // IMPORTANT: Use playerBounds instead of playerPos for correct hitbox check
                if (playerBounds.top + playerBounds.height <= tileBounds.top ||
                    playerBounds.top >= tileBounds.top + tileBounds.height ||
                    playerBounds.left + playerBounds.width <= tileBounds.left ||
                    playerBounds.left >= tileBounds.left + tileBounds.width) {
                    continue;
                }
                
                // Check if player is landing on this tile (coming from above)
                // IMPORTANT: Use playerBounds for correct hitbox check
                float playerBottom = playerBounds.top + playerBounds.height;
                float tileTop = tileBounds.top;
                float penetration = playerBottom - tileTop;
                
                // Player is close to the top of the tile and moving downward
                if (penetration > 0 && penetration < 20.0f && playerVel.y >= 0) {
                    // Landing on top of tile
                    this->player->setPosition(playerPos.x, tileTop - playerBounds.height);
                    this->player->resetVelocityY();
                    onGround = true;
                    
                    // Update animation based on horizontal movement
                    if (std::abs(playerVel.x) < 0.1f) {
                        this->player->setAnimationState(PLAYER_ANIMATION_STATES::IDLE);
                    } 
                    else if (playerVel.x > 0.f) {
                        this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_RIGHT);
                    } 
                    else {
                        this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_LEFT);
                    }
                    this->player->resetAnimationTimer();
                }
            }
        }
    }
    
    // Only proceed with other collisions if we haven't landed on a platform
    if (!onGround) {
        // Second pass: Check for all other collisions
        for (int x = startX; x <= endX; x++) {
            for (int y = startY; y <= endY; y++) {
                Tile* tile = this->tileMap->getTile(x, y);
                if (tile) {
                    sf::FloatRect tileBounds = tile->getGlobalBounds();
                    
                    // Skip tiles that are definitely not colliding
                    // IMPORTANT: Use playerBounds instead of playerPos for correct hitbox check
                    if (playerBounds.top + playerBounds.height <= tileBounds.top ||
                        playerBounds.top >= tileBounds.top + tileBounds.height ||
                        playerBounds.left + playerBounds.width <= tileBounds.left ||
                        playerBounds.left >= tileBounds.left + tileBounds.width) {
                        continue;
                    }
                    
                    // Calculate overlap on each side using playerBounds (green hitbox)
                    float overlapLeft = (playerBounds.left + playerBounds.width) - tileBounds.left;
                    float overlapRight = (tileBounds.left + tileBounds.width) - playerBounds.left;
                    float overlapTop = (playerBounds.top + playerBounds.height) - tileBounds.top;
                    float overlapBottom = (tileBounds.top + tileBounds.height) - playerBounds.top;
                    
                    // Find smallest overlap
                    float minOverlapX = std::min(overlapLeft, overlapRight);
                    float minOverlapY = std::min(overlapTop, overlapBottom);
                    
                    // Resolve collision based on smallest overlap
                    if (minOverlapX < minOverlapY) {
                        // Horizontal collision
                        if (overlapLeft < overlapRight) {
                            // Hitting tile from left side
                            this->player->setPosition(tileBounds.left - playerBounds.width, playerPos.y);
                            this->player->resetVelocityX();
                        } else {
                            // Hitting tile from right side
                            this->player->setPosition(tileBounds.left + tileBounds.width, playerPos.y);
                            this->player->resetVelocityX();
                        }
                    } else {
                        // Vertical collision
                        if (overlapTop < overlapBottom && playerVel.y >= 0) {
                            // Landing on top of tile
                            this->player->setPosition(playerPos.x, tileBounds.top - playerBounds.height);
                            this->player->resetVelocityY();
                            onGround = true;
                            
                            // Update animation based on horizontal movement
                            if (std::abs(playerVel.x) < 0.1f) {
                                this->player->setAnimationState(PLAYER_ANIMATION_STATES::IDLE);
                            } 
                            else if (playerVel.x > 0.f) {
                                this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_RIGHT);
                            } 
                            else {
                                this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_LEFT);
                            }
                            this->player->resetAnimationTimer();
                        } else if (overlapBottom < overlapTop) {
                            // Hitting tile from below
                            this->player->setPosition(playerPos.x, tileBounds.top + tileBounds.height);
                            this->player->resetVelocityY();
                        }
                    }
                }
            }
        }
    }
    
    // =============== MAIN GROUND HANDLING ===============
    float groundLevel = this->window.getSize().y - 50.f;
    
    // Check if player is at or below ground level
    // IMPORTANT: Use playerBounds instead of playerPos for correct hitbox check
    if (playerBounds.top + playerBounds.height >= groundLevel)
    {
        // Place player exactly on ground
        this->player->setPosition(playerPos.x, groundLevel - playerBounds.height);
        this->player->resetVelocityY();
        onGround = true;
        
        // Reset animation state based on horizontal movement
        if (std::abs(playerVel.x) < 0.1f) 
        {
            this->player->setAnimationState(PLAYER_ANIMATION_STATES::IDLE);
        } 
        else if (playerVel.x > 0.f) 
        {
            this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_RIGHT);
        } 
        else 
        {
            this->player->setAnimationState(PLAYER_ANIMATION_STATES::MOVING_LEFT);
        }
        this->player->resetAnimationTimer();
    }
    
    // Update player state based on ground contact
    if (onGround) {
        this->player->setCanJump(true);
        this->player->isJumping = false;
    } else {
        this->player->setCanJump(false);
    }
    
    // Screen boundary collisions
    // IMPORTANT: Use playerBounds instead of playerPos for correct hitbox check
    if (playerBounds.left < 0) {
        this->player->setPosition(0, playerPos.y);
        this->player->resetVelocityX();
    }
    if (playerBounds.left + playerBounds.width > this->window.getSize().x) {
        this->player->setPosition(this->window.getSize().x - playerBounds.width, playerPos.y);
        this->player->resetVelocityX();
    }
    if (playerBounds.top < 0) {
        this->player->setPosition(playerPos.x, 0);
        this->player->resetVelocityY();
    }
    
    // Ensure hitbox is updated after collision resolution
    this->player->updateHitbox();
}

void Game::updateTileMap()
{
    this->tileMap->update();
}

void Game::renderTileMap()
{
    this->tileMap->render(this->window);
}

void Game::initBackground()
{
    if (!this->backgroundTexture.loadFromFile("textures\\background.jpg")) {
        std::cout << "Error:: Game Class :: Background image could not load" << std::endl;
        
        // Use a fallback color if image loading fails
        this->backgroundSprite.setColor(sf::Color(100, 100, 255));
        this->backgroundSprite.setTextureRect(sf::IntRect(0, 0, this->window.getSize().x, this->window.getSize().y));
    } else {
        this->backgroundSprite.setTexture(this->backgroundTexture);
        this->backgroundSprite.setScale(
            float(this->window.getSize().x) / this->backgroundTexture.getSize().x, 
            float(this->window.getSize().y) / this->backgroundTexture.getSize().y
        );
    }
}

// void Game::renderDebug() {
//     // Draw ground level (red line)
//     sf::RectangleShape groundLine(sf::Vector2f(this->window.getSize().x, 2.f));
//     groundLine.setPosition(0.f, this->window.getSize().y - 50.f);
//     groundLine.setFillColor(sf::Color::Red);
//     this->window.draw(groundLine);
    
//     // Draw player hitbox (green box when can jump, yellow when can't)
//     sf::FloatRect playerBounds = this->player->globalbounds();
//     sf::RectangleShape playerBox(sf::Vector2f(playerBounds.width, playerBounds.height));
//     playerBox.setPosition(playerBounds.left, playerBounds.top);
//     playerBox.setFillColor(sf::Color::Transparent);
//     playerBox.setOutlineColor(this->player->getCanJump() ? sf::Color::Green : sf::Color::Yellow);
//     playerBox.setOutlineThickness(1.f);
//     this->window.draw(playerBox);
    
//     // Draw actual player sprite bounds for comparison (blue box)
//     sf::FloatRect spriteBounds = this->player->getSprite().getGlobalBounds();
//     sf::RectangleShape spriteBox(sf::Vector2f(spriteBounds.width, spriteBounds.height));
//     spriteBox.setPosition(spriteBounds.left, spriteBounds.top);
//     spriteBox.setFillColor(sf::Color::Transparent);
//     spriteBox.setOutlineColor(sf::Color::Blue);
//     spriteBox.setOutlineThickness(1.f);
//     this->window.draw(spriteBox);
    
//     // Text for jump status and player state
//     sf::Text jumpText;
//     jumpText.setFont(this->font);
//     jumpText.setString(this->player->getCanJump() ? "Can Jump: YES" : "Can Jump: NO");
//     jumpText.setCharacterSize(20);
//     jumpText.setFillColor(sf::Color::White);
//     jumpText.setPosition(10.f, 50.f);
//     this->window.draw(jumpText);
    
//     // Add state display
//     sf::Text stateText;
//     stateText.setFont(this->font);
//     std::string stateStr = "State: ";
//     switch (this->player->getAnimationState()) {
//         case PLAYER_ANIMATION_STATES::IDLE: stateStr += "IDLE"; break;
//         case PLAYER_ANIMATION_STATES::MOVING_LEFT: stateStr += "MOVING_LEFT"; break;
//         case PLAYER_ANIMATION_STATES::MOVING_RIGHT: stateStr += "MOVING_RIGHT"; break;
//         case PLAYER_ANIMATION_STATES::JUMPING: stateStr += "JUMPING"; break;
//         case PLAYER_ANIMATION_STATES::FALLING: stateStr += "FALLING"; break;
//         default: stateStr += "UNKNOWN"; break;
//     }
//     stateText.setString(stateStr);
//     stateText.setCharacterSize(20);
//     stateText.setFillColor(sf::Color::White);
//     stateText.setPosition(10.f, 80.f);
//     this->window.draw(stateText);
    
//     // Display velocity
//     sf::Text velText;
//     velText.setFont(this->font);
//     std::string velStr = "Velocity: X=" + std::to_string(this->player->getVelocity().x) + 
//                           " Y=" + std::to_string(this->player->getVelocity().y);
//     velText.setString(velStr);
//     velText.setCharacterSize(20);
//     velText.setFillColor(sf::Color::White);
//     velText.setPosition(10.f, 110.f);
//     this->window.draw(velText);
// }