#pragma once

#include <SDL.h>
#include "BaseObject.hpp"

class RenderWindow 
{
public:
	RenderWindow(const char* title, int w, int h);
	~RenderWindow();
	void clear();
	SDL_Texture* loadTexture(const char* filePath);
	void render(BaseObject& d);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};