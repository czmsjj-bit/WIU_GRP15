#include "hero.h"
#include "map.h"
#include "boulder.h"
#include "wall.h"
#include <iostream>
#include <conio.h>

void hero::SetMap(map* m)
{
	world = m;
}

hero::hero(int hp, int atk, int xpos, int ypos, char a, int rng, bool Status)
{
	health = hp;
	attack = atk;
	coordinates.Placey(ypos);
	coordinates.Placex(xpos);
	icon = a;
	range = rng;
	status = Status;

	inventory = nullptr;
	world = nullptr;
	pendingInput = 0;
}

void hero::SetInput(char c)
{
	pendingInput = c;
}

void hero::PrintNearbyBoulderPrompt(gameobject** gameobjectlist)
{
	for (int u = 0; u < 10; u++) {
		if (gameobjectlist[u] != nullptr) {
			boulder* castAttempt = dynamic_cast<boulder*>(gameobjectlist[u]);
			if (castAttempt == nullptr) continue;

			int dx = std::abs(getx() - gameobjectlist[u]->getx());
			int dy = std::abs(gety() - gameobjectlist[u]->gety());
			bool isInRange = (dx <= 1 && dy == 0) || (dx == 0 && dy <= 1);
			if (isInRange) {
				if (gameobjectlist[u]->geticon() == 'O') {
					std::cout << std::endl;
					std::cout << "Theres a boulder you can grab (press g to grab): ";
				}
				else if (gameobjectlist[u]->geticon() == '0') {
					std::cout << std::endl;
					std::cout << "You are grabbing a boulder (Press g to drop): ";
				}
			}
		}
	}
}
void hero::PrintEquippedItemPrompt()
{
	if (inventory == nullptr)
	{
		return;
	}

	Item* equipped = inventory->GetEquippedItem();
	if (equipped != nullptr)
	{
		std::cout << std::endl;
		std::cout << "Equipped: [" << equipped->GetSymbol() << "] " << equipped->GetName()
			<< " (press p to use): ";
	}
}

//include thread include chrono
void hero::movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
	gameobject* target = nullptr;
	boulder* b = nullptr;
	for (int u = 0; u < 10; u++) {
		if (gameobjectlist[u] != nullptr) {
			// FIX: cast into a temporary first. Previously this assigned
			// straight into `b`, so a non-boulder later in the array
			// (the door, the button) would reset b back to nullptr even
			// after a real boulder had already been found — that's what
			// caused "this was nullptr" when b->geticon() was called below.
			boulder* castAttempt = dynamic_cast<boulder*>(gameobjectlist[u]);
			if (castAttempt == nullptr) continue;

			int dx = std::abs(getx() - gameobjectlist[u]->getx());
			int dy = std::abs(gety() - gameobjectlist[u]->gety());
			bool isInRange = (dx <= 1 && dy == 0) || (dx == 0 && dy <= 1);
			if (isInRange) {
				target = gameobjectlist[u];
				b = castAttempt; // FIX: only commit to b once confirmed in range
				//this check if its a boulder so 
				if (target->geticon() == 'O') {
					std::cout << std::endl;
					std::cout << "Theres a boulder you can grab (press g to grab): ";
				}
				else if (target->geticon() == '0') {
					std::cout << std::endl;
					std::cout << "You are grabbing a boulder (Press g to drop): ";
				}
			}
		}
	}
	//nvm its ok 
	int prevx = getx();
	int prevy = gety();

	// Use the key main.cpp already read via _getch() instead of reading our
	// own -- otherwise every keypress gets consumed twice (once by
	// main.cpp's dispatch loop, once here), so the player would need to
	// press each key twice for it to register.
	char input = pendingInput;

	if (target != nullptr) {
		if (b->geticon() == '0') {   // b is now guaranteed non-null when target is non-null
			b->validmovecheck(input, entitylist, gameobjectlist, walllist);
			if (b->getgrabstatus() == 0) {
				b->setgrabstatus(1);
				return;
			}
		}
		//boulder code here 
	}

	// Note: 'i' is no longer handled here. main.cpp reads input and gives
	// Menu first refusal on it (Menu::handleGameInput), which opens the
	// inventory and continues the outer loop *before* movementcheck() is
	// ever called -- so this function now only ever sees whatever Menu
	// didn't already claim.

	if (input == 'p' || input == 'P')
	{
		if (inventory != nullptr)
		{
			Item* equipped = inventory->GetEquippedItem();

			if (equipped != nullptr)
			{
				bool used = equipped->Use(this, entitylist, gameobjectlist, walllist);

				if (used)
				{
					std::cout << equipped->GetName() << " used!\n";
					inventory->UseEquippedItem(); // one-time use
				}
				else
				{
					std::cout << "Nothing happens.\n";
				}
			}
			else
			{
				std::cout << "No item equipped.\n";
			}
		}

		return; // using an item is its own turn -- doesn't also move the player
	}

	switch (input) {
	case 'w':
		sety(gety() - 1);
		break;
	case 'a':
		setx(getx() - 1);
		break;
	case 'd':
		setx(getx() + 1);
		break;
	case's':
		sety(gety() + 1);
		break;

		//if boulder is currently grabbed use boulder check to check if the boulder can be moved

			//idea use static cast on this to call boulder move function 
			//
	case'g': //universal grab for button
		if (!(target == nullptr)) {
			if (target->geticon() == '0' || target->geticon() == 'O')
				if (target->geticon() == 'O') {
					target->seticon('0');
					break;
				}
			if (target->geticon() == '0') {
				target->seticon('O');
				break;
			}
		}
		break;
	default:
		std::cout << "invalid input";
	}
	//runs thru the item list 
	for (int u = 0; u < 4; u++) {
		if (u == 0) { // checking for itself
			//if gameobject
			if (!(target == nullptr)) {

			}
			continue;
		}
		if (entitylist[u] != nullptr) {
			if (getx() == entitylist[u]->getx() &&
				gety() == entitylist[u]->gety())
			{
				setx(prevx);
				sety(prevy);
				return;
			}
		}
	}
	//run through walllist
	for (int u = 0; u < 100; u++) {
		if (walllist[u] != nullptr) {
			if (getx() == walllist[u]->getx() &&
				gety() == walllist[u]->gety())
			{
				setx(prevx);
				sety(prevy);

			}
		}
	}
	//remeber its called a destructor
	for (int u = 0; u < 10; u++) {
		if (gameobjectlist[u] != nullptr) {
			if (getx() == gameobjectlist[u]->getx() &&
				gety() == gameobjectlist[u]->gety())
			{
				//uh if you set your icon for your wall to be t it becomes a wall now
				if (gameobjectlist[u]->geticon() == 'U') {//door is still locked
					setx(prevx);
					sety(prevy);
					return;
				}
				if (gameobjectlist[u]->geticon() == 'N') {//door is unlocked

					return;
				}

				//button
				if (gameobjectlist[u]->geticon() == '-') {
					setx(prevx);
					sety(prevy);
					return;
				}
				if (gameobjectlist[u]->geticon() == '@') {
					delete gameobjectlist[u];
					gameobjectlist[u] = nullptr;
					return;
				}
				////i am a boulder pushing 
				//boulder pushing time 
				if (gameobjectlist[u]->geticon() == 'O' || gameobjectlist[u]->geticon() == '0') {
					std::cout << "boulder push";
					setx(prevx);
					sety(prevy);
					return;
				}
			}
		}
	}
}

void hero::setattack(int atack) {
	attack = atack;
}

int hero::getattack() {
	return attack;
}

void hero::SetInventory(Inventory* inv)
{
	inventory = inv;
}