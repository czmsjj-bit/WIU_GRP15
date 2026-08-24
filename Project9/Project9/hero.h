#pragma once
#include <stdlib.h>
#include <string>

#include "entity.h"
#include "gameobject.h"

class hero : public entity
{
public:

	hero(int hp, int atk, int xpos, int ypos, char a, int rng, bool status);



	void movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist);

	void setattack(int atack);

	int getattack();



private:
	bool status;
	int attack;

	//hp and everything stored in entity

	//xpos and ypos stored in coordinates
};

//we set a class to make a function reusable

//we have a cla



