#pragma once
#include<stdafx.h>
#include<Player.h>
#include<TileMap.h>
#include<Coin.h>

class Game {

    private:
        sf :: RenderWindow window;
        sf :: Event event;
        sf :: Texture tileSheet;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        sf::Texture coinTexture;
        sf::Font font;
        sf::Text scoreText;

        unsigned int score;
        
        Player* player;
        TileMap* tileMap;
        std::vector<Coin*> coins;
        
        std::map<std::string, sf::Keyboard::Key> keyboardMappings;
        std::map<std::string, sf::Mouse::Button> mouseMappings;

        void initWindow();
        void initInput();
        void initTileSheet();
        void initPlayer();
        void initTileMap();
        void initBackground();
        void initCoins();
        void initGUI();
        void createPlatforms();

    public:
        // constructor 
        Game();
        ~Game();

        // functions 
        void updateInput();
        void update();
        void updateCollision();
        void updatePlayer();
        void updateTileMap();
        void updateCoins();
        void updateGUI();

        void render();
        void renderPlayer();
        void renderTileMap();
        void renderCoins();
        void renderGUI();
        void renderDebug();

        void addCoin(float x, float y);
        void checkCoinCollisions();
        
        const sf::RenderWindow& getwindow() const;
};