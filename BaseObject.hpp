#pragma once
#include <SDL.h>

class BaseObject {
	public:
		BaseObject(int x, int y, SDL_Texture* texture);
		int getX();
		int getY();
		SDL_Texture* getTexture();

	private:
		SDL_Texture* texture;
		int xPos;
		int yPos;
};