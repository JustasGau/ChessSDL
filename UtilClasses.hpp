#pragma once
#include <SDL.h>

struct ColorDef
{
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 alpha;
};

struct PieceTextures
{
	SDL_Texture* wp;
	SDL_Texture* wk;
	SDL_Texture* wq;
	SDL_Texture* wb;
	SDL_Texture* wn;
	SDL_Texture* wr;
	SDL_Texture* bp;
	SDL_Texture* bk;
	SDL_Texture* bq;
	SDL_Texture* bb;
	SDL_Texture* bn;
	SDL_Texture* br;

};
