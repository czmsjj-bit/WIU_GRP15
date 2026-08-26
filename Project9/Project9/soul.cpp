#include "soul.h"

int soul::soulcount = 0;
soul::soul(int x, int y, char icon)
{
	coordinates.Placex(x);
	coordinates.Placey(y);

	seticon(icon);
}

soul::~soul()
{
	//soul goes up to 10
	soulcount++;
	std::cout << "you freed me ";
	//this will most likely be skipped anyway but for the 5 seconds of vision it will be quite funny
}

