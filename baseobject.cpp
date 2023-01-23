#include "BaseObject.hpp"

BaseObject::BaseObject(int x, int y, SDL_Texture* texture) 
	: xPos(x), yPos(y), texture(texture)
	{}

int BaseObject::getX()
{
	return xPos;
}

int BaseObject::getY()
{
	return yPos;
}

SDL_Texture* BaseObject::getTexture()
{
	return texture;
}
 