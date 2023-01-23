#pragma once
#include <SDL_stdinc.h>

struct ColorDef
{
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 alpha;
public:
	bool operator==(const ColorDef& first)
	{
		return first.red == red;
	}
};



//auto operator<=>(const ColorDef&) const = default;