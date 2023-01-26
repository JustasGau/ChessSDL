#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstdlib>

#include "Renderer.hpp"
#include "Board.hpp"
#include "FEN.hpp"
#include <iostream>


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

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
	FEN fen;
	bool isValid = fen.validateFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 10 a");
	std::cout << isValid << "\n";
	// early return for faster testing
	return 0;
	RenderWindow window("ChessSDL", SCREEN_WIDTH, SCREEN_HEIGHT);

	init();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	// board style
	ColorDef colorWhite = { 0xEE, 0xEE, 0xD2, 0xFF };
	ColorDef colorGreen = { 0x76, 0x96, 0x56, 0xFF };

	// preload textures
	SDL_Texture* white_pawn = window.loadTexture("./gfx/white_pawn.png");
	SDL_Texture* white_rook = window.loadTexture("./gfx/white_rook.png");
	SDL_Texture* white_bishop = window.loadTexture("./gfx/white_bishop.png");
	SDL_Texture* white_knight = window.loadTexture("./gfx/white_knight.png");
	SDL_Texture* white_king = window.loadTexture("./gfx/white_king.png");
	SDL_Texture* white_queen = window.loadTexture("./gfx/white_queen.png");

	SDL_Texture* black_pawn = window.loadTexture("./gfx/black_pawn.png");
	SDL_Texture* black_rook = window.loadTexture("./gfx/black_rook.png");
	SDL_Texture* black_bishop = window.loadTexture("./gfx/black_bishop.png");
	SDL_Texture* black_knight = window.loadTexture("./gfx/black_knight.png");
	SDL_Texture* black_king = window.loadTexture("./gfx/black_king.png");
	SDL_Texture* black_queen = window.loadTexture("./gfx/black_queen.png");

	PieceTextures allTextures = {
		white_pawn,
		white_knight,
		white_queen,
		white_bishop,
		white_knight,
		white_rook,
		black_pawn,
		black_knight,
		black_queen,
		black_bishop,
		black_knight,
		black_rook
	};
	Board board(90, &colorWhite, &colorGreen, allTextures);

	board.initPostitions("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 0");

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

		board.render(window.getRenderer());

		//Update screen
		window.display();
	}

	close();

	return 0;
}