#pragma once
#include "entity.h"
#include <string>
#include "gameobject.h"


class goblin : public entity
{
public:
	goblin(int hp, int atk, int xpos, int ypos, char a);

	int gethealth();

	void sethealth(int Health);

	void movementcheck(entity** entitylist, gameobject** gameobjectlist  , wall** walllist) override;

	void Damage(entity* victim);

	void move();

	static int getgoblincount();
	int getattack();
	//only one way to delete something 
	~goblin();
private:

	int attack;
	static int goblincount;
};


//if nullpointer then ignore??

//run through all 4 moves

//if nullpointer skips ??

//
