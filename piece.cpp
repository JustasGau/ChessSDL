#include "Piece.hpp"

Piece::Piece(int width, bool isDark, SDL_Texture* texture):
	 width(width), isDark(isDark), texture(texture)
{}

Piece::Piece()
{}

Tile Piece::getTile()
{
	return activeTile;
}

void Piece::setActiveTile(Tile tile)
{
	activeTile = tile;
}

int Piece::getWidth()
{
	return width;
}

SDL_Texture* Piece::getTexture()
{
	return texture;
}