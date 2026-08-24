#include "door.h"

door::door(int xpos, int ypos, char Icon, bool Lockstatus)
{
	coordinates.Placex(xpos);
	coordinates.Placey(ypos);

	seticon(Icon);
	openstatus = Lockstatus;

}


//using this when player collides with door check if openstatus = true 

//the if true go to next map aka delete current map 

//soooo this will probably use a static int 
void door::setopenstatus(bool stat)
{
	openstatus = stat;
}

bool door::getopenstatus()
{
	return openstatus;
}
