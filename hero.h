#pragma once
#include "Inventory.h"
#include <stdlib.h>
#include <string>
#include "wall.h"
#include "entity.h"
#include "gameobject.h"

class map;

class hero : public entity
{
public:

	hero(int hp, int atk, int xpos, int ypos, char a, int rng, bool status);

	void movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;

	void setattack(int atack);

	int getattack();

	void SetInventory(Inventory* inv);
	void SetMap(map* m);

	// Called by main.cpp with the key it already read via _getch(), before
	// movementcheck() runs on this turn. hero uses this instead of calling
	// _getch() itself, so the same keypress isn't read twice (once by
	// main.cpp's own dispatch loop, once inside movementcheck()).
	void SetInput(char c);

	void PrintNearbyBoulderPrompt(gameobject** gameobjectlist);

	void PrintEquippedItemPrompt();
private:
	bool status;
	int attack;
	Inventory* inventory;
	map* world;
	char pendingInput;

	//hp and everything stored in entity

	//xpos and ypos stored in coordinates
};