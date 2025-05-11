#pragma once
#include "Tile.h"

class TileMap
{
    std::vector< std::vector<Tile*> > tiles;
    sf::Texture* tileSheet;
    unsigned tileSize;

    public:
        TileMap();
        TileMap(unsigned width, unsigned height, sf::Texture* tileSheet, unsigned tileSize);
        ~TileMap();

        // Inline funcs
        inline const unsigned& getTileSize() const { return this->tileSize; }
        inline const sf::Vector2u getSize() const { 
            return sf::Vector2u(this->tiles.size(), 
                               this->tiles.empty() ? 0 : this->tiles[0].size()); 
        }
        
        inline Tile* getTile(const unsigned x, const unsigned y) const {
            if (x < this->tiles.size() && y < this->tiles[x].size()) {
                return this->tiles[x][y];
            }
            return nullptr;
        }

        //funcs
        void addTile(unsigned x, unsigned y);
        void removeTile(unsigned x, unsigned y);

        void update();
        void render(sf::RenderTarget& target);
};
