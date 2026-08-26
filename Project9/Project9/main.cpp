#include <conio.h>
#include <string>
#include <iostream>
#include "map.h"
#include "hero.h"
#include "entity.h"
#include "harpy.h"
#include "Inventory.h"
#include "Item.h"
#include "Encounter.h"
#include "ScrollList.h"
#include "Menu.h"
#include "Dialogue.h"
#include "maphandler.h"
#include "door.h"   // <-- needed for static_cast<door*> and getopenstatus()

int main(void) {
	maphandler handler;

	Menu menu;
	menu.showTitleScreen();

	Inventory inv;
	Encounter encounter;
	encounter.GenerateEncounter();
	encounter.scrollPick(inv);

	bool worldcomplete = 0;
	int worldcount = 0;

	map* world = handler.getcurrentmapptr();

	while (worldcomplete == 0 && world->getentitylist()[0] != nullptr) {
		system("cls");
		handler.printcurrentmap();
		std::cout << std::endl << std::endl;

		entity* player = world->getentitylist()[0];

		if (player != nullptr) {
			std::cout << "you have" << player->gethealth() << "hp left";
		}

		// --- movement/collision updates ---
		for (int i = 0; i < world->getentitylistsize(); i++) {
			if (world->getentitylist()[i] == nullptr) continue;
			world->getentitylist()[i]->movementcheck(world->getentitylist(), world->getgameobjectlist(), world->getwalllist());
		}

		// --- door check: has player reached an unlocked door? ---
		door* thedoor = static_cast<door*>(world->getgameobjectlist()[1]);

		if (thedoor != nullptr && player != nullptr &&
			player->getx() == thedoor->getx() && player->gety() == thedoor->gety() &&
			thedoor->getopenstatus() == true) {

			handler.setcurrentmap(handler.getcurrentmap() + 1);
			world = handler.getcurrentmapptr(); // refresh pointer — now points at the new map
			
		}
	}

	return 0;
}