#pragma once
#include "gameobject.h"
#include "entity.h"
#include "Coordinates.h"



class button : public gameobject
{
public:


	//easy set up ltr
	button(int xpos, int ypos, char Icon, bool Lockstatus);

	void openupdoor(gameobject** gameobjectlist);

	void setlockstatus(bool stat);

	bool getlockstatus();



private:
	//has x has y has get icon because of game object 
	bool lockstatus;


};

