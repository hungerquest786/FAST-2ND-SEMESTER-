#include "TileMap.h"

TileMap::TileMap()
{
    this->tileSheet = NULL;
    this->tileSize = 0;
}

TileMap::TileMap(unsigned width, unsigned height, sf::Texture* tileSheet, unsigned tileSize)
{
    this->tileSheet = tileSheet;
    this->tileSize = tileSize;

    this->tiles.resize(width);
    for(size_t i = 0; i < this->tiles.size(); i++)
    {
        this->tiles[i].resize(height, nullptr);
    }
}

TileMap::~TileMap()
{
    for(size_t i = 0; i < this->tiles.size(); i++)
    {
        for(size_t j = 0; j < this->tiles[i].size(); j++)
        {
            delete this->tiles[i][j];
            this->tiles[i][j] = nullptr;
        }
    }
}

void TileMap :: addTile(unsigned x, unsigned y)
{
    if(x < this->tiles.size() && x >= 0)
    {
        if(y < this->tiles[x].size() && y >= 0)
        {
            if(this->tiles[x][y] == nullptr)
            {
                this->tiles[x][y] = new Tile(x, y, this->tileSize,this->tileSheet, sf::IntRect(0,0, this->tileSize, this->tileSize), false);
            
            }
        }
    }
}

void TileMap :: removeTile(unsigned x, unsigned y)
{
    if(x < this->tiles.size())
    {
        if(y < this->tiles[x].size())
        {
            if(this->tiles[x][y] != nullptr)
            {
                delete this->tiles[x][y];
                this->tiles[x][y] = nullptr;
            }
        }
    }
}

void TileMap ::  update()
{
    for(size_t i = 0; i < this->tiles.size(); i++)
    {
        for(size_t j = 0; j < this->tiles[i].size(); j++)
        {
            if(this->tiles[i][j] != nullptr)
                this->tiles[i][j]->update();
        }
    }
}

void TileMap :: render(sf::RenderTarget& target)
{
    for(size_t i = 0; i < this->tiles.size(); i++)
    {
        for(size_t j = 0; j < this->tiles[i].size(); j++)
        {
            if(this->tiles[i][j] != nullptr)
                this->tiles[i][j]->render(target);
        }
    }
}