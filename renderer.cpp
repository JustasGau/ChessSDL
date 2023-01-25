#include "Renderer.hpp"
#include <SDL_image.h>
#include <stdio.h>
#include "UtilClasses.hpp"


RenderWindow::RenderWindow(const char* title, int w, int h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		printf("Unable to load texture %s! SDL_image Error: %s\n", filePath, IMG_GetError());
	}

	return texture;
}

RenderWindow::~RenderWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
}

void RenderWindow::clear()
{
	SDL_SetRenderDrawColor(renderer, 0x31, 0x2E, 0x2B, 0xFF);
	SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::render(Tile& d)
{
	ColorDef* color = d.getColor();
	SDL_Rect fillRect = { d.getX(), d.getY(), d.getWidth(), d.getWidth() };
	SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->alpha);
	SDL_RenderFillRect(renderer, &fillRect);
}

SDL_Renderer* RenderWindow::getRenderer()
{
	return renderer;
}