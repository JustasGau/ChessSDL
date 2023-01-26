#include "FEN.hpp"
#include <vector>
#include <iostream>

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

FEN::FEN()
{}

bool FEN::validateFEN(std::string fen)
{
	std::vector<std::string> tokens = splitString(fen);
	if (tokens.size() != 6) {
		printf("Incorrect amount of parts in FEN string\n");
		return false;
	}
	std::vector<std::string> files = splitString(tokens[0], "/");
	if (files.size() != 8) {
		printf("Incorrect amount of files in position part of FEN string\n");
		return false;
	}
	if (!is_number(tokens[4])) {
		std::cout << stoi(tokens[4]) << "\n";
		printf("Halfmoves '%s' is not a number\n", tokens[4]);
		return false;
	}

	if (!is_number(tokens[5])) {
		std::cout << stoi(tokens[5]) << "\n";
		printf("Fullmoves '%s' is not a number\n", tokens[5]);
		return false;
	}

	return true;
}

startState FEN::parseFEN(std::string fen)
{
	std::map<std::string, std::string> positions;
	startState parsedState = {
		positions,
		true,
		0,
		"-",
		0,
		0,
	};
	return parsedState;
}

