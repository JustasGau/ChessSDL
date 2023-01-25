#pragma once
#include <SDL.h>

#include "Piece.hpp"
#include "Tile.hpp"
#include "UtilClasses.hpp"
#include <map>
#include <vector>

const int PiecesAmount = 32;

class Board
{
public:
	Board(int tileWidth, ColorDef* primaryColor, ColorDef* secondaryColor, PieceTextures textures);
	void render(SDL_Renderer* renderer);
private:
	void renderBoard(SDL_Renderer* renderer);
	void renderPieces(SDL_Renderer* renderer);
	void initPeaces();
	void addWP(std::string id);
	void addBP(std::string id);
	std::map<std::string, Tile> tiles;
	std::vector<Piece> pieces;
	PieceTextures textures;
};