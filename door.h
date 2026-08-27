#pragma once

#pragma once
#include "gameobject.h"
#include "entity.h"
#include "Coordinates.h"





class door : public gameobject
{
public:


	//easy set up ltr
	door(int xpos, int ypos, char Icon, bool Lockstatus);

	void setopenstatus(bool stat);

	bool getopenstatus();



private:
	//has x has y has get icon because of game object 
	bool openstatus;


};




