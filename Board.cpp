#include "Board.hpp"
#include "Tile.hpp"
#include "UtilClasses.hpp"
#include <SDL.h>
#include <iostream>


Board::Board(int tileWidth, ColorDef* primaryColor, ColorDef* secondaryColor, PieceTextures textures)
	: textures(textures)
{
	const char letterMap[9] = "ABCDEFGH";
	ColorDef* currentColor = primaryColor;
	for (int file = 0; file < 8; file++)
	{
		for (int rank = 0; rank < 8; rank++)
		{
			std::string newId = letterMap[file] + std::to_string(8 - rank);
			std::cout << newId << "\n";
			currentColor = (file + rank)%2 == 0 ? secondaryColor : primaryColor;
			Tile newTile(file * tileWidth, rank * tileWidth, tileWidth, currentColor, newId);
			tiles[newId] = newTile;
		}
	}

	initPeaces();
}

void Board::addWP(std::string id)
{
	Tile tile = tiles[id];
	Piece newPiece(tile.getWidth(), false, textures.wp);
	newPiece.setActiveTile(tile);
	pieces.push_back(newPiece);
}

void Board::addBP(std::string id)
{
	Tile tile = tiles[id];
	Piece newPiece(tile.getWidth(), true, textures.bp);
	newPiece.setActiveTile(tile);
	pieces.push_back(newPiece);
}

void Board::initPostitions(std::string fenNotation)
{

}

void Board::initPeaces()
{
	addWP("A2");
	addWP("B2");
	addWP("C2");
	addWP("D2");
	addWP("E2");
	addWP("F2");
	addWP("G2");
	addWP("H2");

	addBP("A7");
	addBP("B7");
	addBP("C7");
	addBP("D7");
	addBP("E7");
	addBP("F7");
	addBP("G7");
	addBP("H7");

}

void Board::render(SDL_Renderer* renderer)
{
	renderBoard(renderer);
	renderPieces(renderer);
}

void Board::renderBoard(SDL_Renderer* renderer)
{
	for (const auto& tileTuple : tiles)
	{
		Tile tile = tileTuple.second;
		ColorDef* color = tile.getColor();
		SDL_Rect fillRect = { tile.getX(), tile.getY(), tile.getWidth(), tile.getWidth() };
		SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->alpha);
		SDL_RenderFillRect(renderer, &fillRect);
	}
}

void Board::renderPieces(SDL_Renderer* renderer)
{
	for (Piece piece : pieces) {
		Tile tile = piece.getTile();
		SDL_Rect renderQuad = { tile.getX(), tile.getY(), piece.getWidth(), piece.getWidth() };
		SDL_RenderCopy(renderer, piece.getTexture(), NULL, &renderQuad);
	}
}