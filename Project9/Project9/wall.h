#pragma once
#include "gameobject.h"
class wall : public gameobject
{
public:
	wall(int xpos, int ypos,char icon);


protected:
	wall** walllist;
};



