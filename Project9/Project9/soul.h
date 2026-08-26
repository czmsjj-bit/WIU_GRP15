#pragma once
#include "gameobject.h"
class soul : public gameobject
{
public:
	//creates the class and the icon 

	soul(int x, int y, char icon);

	~soul(); // called when class is destroyed 


private:
	static int soulcount;
};

