#pragma once

#include <SDL.h>
#include "BaseObject.hpp"
#include "Tile.hpp"

class RenderWindow 
{
public:
	RenderWindow(const char* title, int w, int h);
	~RenderWindow();
	void clear();
	SDL_Texture* loadTexture(const char* filePath);
	SDL_Renderer* getRenderer();
	//void render(BaseObject& d);
	void render(Tile& d);
	void display();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};