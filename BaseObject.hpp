#pragma once
#include <SDL.h>

class BaseObject {
	public:
		BaseObject(int x, int y, SDL_Texture* texture);
		void render();
	private:
		SDL_Texture* texture;
		int xPos;
		int yPos;
};