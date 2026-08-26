#include "wall.h"
#include <iostream>
#include <string>

wall::wall(int xpos, int ypos, char icon)
{
	coordinates.Placey(xpos);

	coordinates.Placex(ypos);

	seticon(icon);
}

