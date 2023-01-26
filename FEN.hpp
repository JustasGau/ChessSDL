#pragma once

#include <string>
#include <map>

struct startState
{
	// position = pawn notation
	std::map<std::string, std::string> positions;
	bool isWhitesTurn = true;
	unsigned int castlingRights = 0;
	std::string EP = "-";
	unsigned int halfmoves = 0;
	unsigned int fullmoves = 0;
};

enum Castling {
	WhiteKingside = 0x1,
	WhiteQueenside = 0x2,
	BlackKingside = 0x4,
	BlackQueenside = 0x8,
};

/*
FEN format
--------------Field No.1------------------
Positions:
	p/P - black/white Pawn
	r/R - black/white Rook
	b/B - black/white Bishop
	n/N - black/white Knight
	q/Q - black/white Queen
	k/K - black/white King
	8 parts separated by / to denote piese positions
	if there are numbers that means - how many empty squares until next piece or end of board
	E.g. rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR
--------------Field No.2------------------
Turn:
	w - whites turn to move
	b - blacks turn to move
--------------Field No.3------------------
Castling rights:
	Q/K - white queen side/ king side
	q/k - black queen side/ king side
	"-" - no right
--------------Field No.4------------------
En Pasasnt:
	denotes file and rank of square where En Passant can happen
	This is the tile behind the pawn that moved two squares
	Is always denoted even when there is no piece than can perform En Passant
	"-" - if no pawn moved two tiles
--------------Field No.5------------------
Halfmoves:
	Number of halfmoves, usefull for enfocing a draw when the number reaches 100
	(both sides moved 50 times)
--------------Field No.6------------------
Fullmove:
	Number of black moves.

Full FEN notation: 
	rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
*/
class FEN
{
public:
	FEN();
	bool validateFEN(std::string fen);
	startState parseFEN(std::string fen);
};


