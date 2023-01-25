#pragma once
#include "UtilClasses.hpp"
#include <string>

class Tile {
public:
	Tile(int x, int y, int width, ColorDef* color, std::string id);
	Tile();
	int getX();
	int getY();
	int getWidth();
	ColorDef* getColor();

private:
	int width;
	ColorDef* color;
	int xPos;
	int yPos;
	std::string ID = "XX";
};