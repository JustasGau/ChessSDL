#pragma once
#include "UtilClasses.hpp"

class Tile {
public:
	Tile(int x, int y, ColorDef* color);
	int getX();
	int getY();
	int getWidth();
	ColorDef* getColor();

private:
	int width = 100;
	ColorDef* color;
	int xPos;
	int yPos;
};