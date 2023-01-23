#include "Tile.hpp"

Tile::Tile(int x, int y, ColorDef* color)
	: xPos(x), yPos(y), color(color)
	{}

ColorDef* Tile::getColor()
{
	return color;
}

int Tile::getX()
{
	return xPos;
}

int Tile::getY()
{
	return yPos;
}

int Tile::getWidth()
{
	return width;
}