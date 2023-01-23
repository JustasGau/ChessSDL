#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstdlib>

#include "Renderer.hpp"
#include "UtilClasses.hpp"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


//Frees media and shuts down SDL
//void close();


void init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		std::exit(1);
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
			std::exit(1);
		}

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			std::exit(1);
		}
	}

}

void close()
{

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	RenderWindow window("ChessSDL", SCREEN_WIDTH, SCREEN_HEIGHT);

	init();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		window.clear();

		ColorDef colorWhite = { 0xEE, 0xEE, 0xD2, 0xFF };
		ColorDef colorGreen = { 0x76, 0x96, 0x56, 0xFF };
		ColorDef currentColor = colorWhite;
		int width = 100;
		for (int i = 0; i < 8; i++)
		{
			currentColor = currentColor == colorWhite ? colorGreen : colorWhite;
			for (int j = 0; j < 8; j++)
			{
				currentColor = currentColor == colorWhite ? colorGreen : colorWhite;
				Tile tile1(i* width, j* width, &currentColor);
				window.render(tile1);
			}
		}


		
		//SDL_Rect fillRect = { 100, 100, 100, 100 };
		//SDL_SetRenderDrawColor(gRenderer, 0xEE, 0xEE, 0xD2, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect);

		//SDL_Rect fillRect2 = { 200, 200, 100, 100 };
		//SDL_SetRenderDrawColor(gRenderer, 0x76, 0x96, 0x56, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect2);

		//SDL_Rect renderQuad = { 10, 20, 100, 100 };

		//SDL_RenderCopy(gRenderer, loadTexture("./dot.bmp"), NULL, &renderQuad);


		//Update screen
		window.display();
	}

	close();

	return 0;
}