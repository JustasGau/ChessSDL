#pragma once
#include <SDL.h>
#include "Tile.hpp"

// generic piece that has basic parameters
// must be inherited by actual pieces that have different mechanics
class Piece
{
public:
	Piece();
	Piece(int width, bool isDark, SDL_Texture* texture);
	Tile getTile();
	void setActiveTile(Tile tile);
	int getWidth();
	SDL_Texture* getTexture();
private:
	int width;
	int xPos;
	int yPos;
	bool isDark = false;
	bool isAlive = true;
	SDL_Texture* texture;
	Tile activeTile;
};