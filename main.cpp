#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

#include "Renderer.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//Starts up SDL and creates window
//bool init();


//Frees media and shuts down SDL
//void close();


//bool init()
//{
//	//Initialization flag
//	bool success = true;
//
//	//Initialize SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else
//	{
//		//Set texture filtering to linear
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
//		{
//			printf("Warning: Linear texture filtering not enabled!");
//		}
//
//		//Create window
//		RenderWindow window("ChessSDL", SCREEN_WIDTH, SCREEN_HEIGHT);
//
//		//Initialize PNG loading
//		int imgFlags = IMG_INIT_PNG;
//		if (!(IMG_Init(imgFlags) & imgFlags))
//		{
//			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//			success = false;
//		}
//	}
//
//	return success;
//}

//void close()
//{
//
//	//Quit SDL subsystems
//	IMG_Quit();
//	SDL_Quit();
//}


int main(int argc, char* args[])
{
	RenderWindow window("ChessSDL", SCREEN_WIDTH, SCREEN_HEIGHT);

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

		////Clear screen
		//SDL_SetRenderDrawColor(gRenderer, 0x31, 0x2E, 0x2B, 0xFF);
		window.clear();

		//SDL_Rect fillRect = { 100, 100, 100, 100 };
		//SDL_SetRenderDrawColor(gRenderer, 0xEE, 0xEE, 0xD2, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect);

		//SDL_Rect fillRect2 = { 200, 200, 100, 100 };
		//SDL_SetRenderDrawColor(gRenderer, 0x76, 0x96, 0x56, 0xFF);
		//SDL_RenderFillRect(gRenderer, &fillRect2);

		//SDL_Rect renderQuad = { 10, 20, 100, 100 };

		//SDL_RenderCopy(gRenderer, loadTexture("./dot.bmp"), NULL, &renderQuad);


		//Update screen
		//SDL_RenderPresent(gRenderer);
	}

	//Free resources and close SDL
	//close();

	return 0;
}