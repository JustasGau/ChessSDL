#include "Tile.hpp"

Tile::Tile(int x, int y, int width, ColorDef* color, std::string id)
	: xPos(x), yPos(y), width(width), color(color), ID(id)
{}

Tile::Tile()
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