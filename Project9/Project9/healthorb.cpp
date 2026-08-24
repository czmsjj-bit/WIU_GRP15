#include "healthorb.h"










healthorb::healthorb(int xpos, int ypos, char d)
{
	icon = d;
	coordinates.Placey(ypos);
	coordinates.Placex(xpos);

}

healthorb::~healthorb()
{
}
