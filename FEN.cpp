#include "FEN.hpp"
#include <vector>
#include <iostream>
#define DEBUG 0

std::vector<std::string> splitString(std::string str, std::string deli = " ")
{
	int start = 0;
	int end = str.find(deli);
	std::vector<std::string> tokens;
	while (end != -1) {
		tokens.push_back(str.substr(start, end - start));
		start = end + deli.size();
		end = str.find(deli, start);
	}
	tokens.push_back(str.substr(start, end - start));

	return tokens;
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool validateCastling(std::string castling) {
	std::string castlingAvailable = "KQkq";
	std::string uniqueAccum = "";

	if (castling.size() > 4)
	{
		printf("Castling '%s' is incorrect - too long. Acceptable notation '%s'.\n", castling.c_str(), castlingAvailable.c_str());
		return false;
	}
	if (castling != "-")
	{
		for (int i = 0; i < castling.size(); i++)
		{
			std::size_t found = castlingAvailable.find(castling[i]);
			std::size_t foundDup = uniqueAccum.find(castling[i]);

			if (found == -1)
			{
				printf("Castling '%s' is incorrect. Acceptable notation '%s'.\n", castling.c_str(), castlingAvailable.c_str());
				return false;
			}
			else if (foundDup != -1)
			{
				printf("Castling '%s' is incorrect. Symbols can not repeat.\n", castling.c_str());
				return false;
			}
			else
			{
				uniqueAccum += castling[i];
			}
		}
	}
	return true;
}

// TODO
bool validatePosition(std::string positions)
{
	return true;
}

// TODO
bool validateEnPassant(std::string enp)
{
	return true;
}

FEN::FEN()
{}


bool FEN::validateFEN(std::string fen)
{
	std::vector<std::string> tokens = splitString(fen);

#if DEBUG == 1
	for (const std::string &token : tokens) {
		std::cout << token << "\n";
	}
#endif
	if (tokens.size() != 6) {
		printf("Incorrect amount of parts in FEN string\n");
		return false;
	}
	std::vector<std::string> files = splitString(tokens[0], "/");
	if (files.size() != 8) {
		printf("Incorrect amount of files in position part of FEN string\n");
		return false;
	}

	std::string positions = tokens[0];
	std::string turn = tokens[1];
	std::string castling = tokens[2];
	std::string enp = tokens[3];
	std::string halfmoves = tokens[4];
	std::string fullmoves = tokens[5];

	if (!validatePosition(positions)) return false;
	if (!validateCastling(castling)) return false;
	if (!validateEnPassant(enp)) return false;

	if (turn != "w" && turn != "b")
	{
		printf("Turn '%s' is incorrect. Values: w or b are acceptable.\n", turn.c_str());
		return false;
	}

	if (!is_number(halfmoves))
	{
		printf("Halfmoves '%s' is not a number\n", halfmoves.c_str());
		return false;
	}

	if (!is_number(fullmoves))
	{
		printf("Fullmoves '%s' is not a number\n", fullmoves.c_str());
		return false;
	}

	return true;
}

startState FEN::parseFEN(std::string fen)
{
	std::vector<std::string> tokens = splitString(fen);
	std::string positions = tokens[0];
	std::string turn = tokens[1];
	std::string castling = tokens[2];
	std::string enp = tokens[3];
	std::string halfmoves = tokens[4];
	std::string fullmoves = tokens[5];

	bool whitesTurn = turn == "w" ? true : false;
	unsigned int castlingRights = 0;
	if (castling.find("K")) castlingRights = castlingRights | WhiteKingside;
	if (castling.find("k")) castlingRights = castlingRights | BlackKingside;
	if (castling.find("Q")) castlingRights = castlingRights | WhiteQueenside;
	if (castling.find("q")) castlingRights = castlingRights | BlackQueenside;


	std::map<std::string, std::string> positionsParsed;
	startState parsedState = {
		positionsParsed,
		whitesTurn,
		castlingRights,
		enp,
		(unsigned int) std::stoi(halfmoves),
		(unsigned int) std::stoi(fullmoves),
	};
	return parsedState;
}

