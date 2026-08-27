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

//New
#include "Menu.h"
#include "Dialogue.h"
#include "maphandler.h"
#include "door.h"   // <-- needed for static_cast<door*> and getopenstatus()

int main(void) {
	Inventory& inv = Inventory::GetInstance();
	Encounter encounter;


	//encounter.GenerateEncounter();     // stock 3 random scrolls
	//encounter.scrollPick();   // player picks one; encounter closes; inventory opens


	//zi ming world code goes here 


	maphandler handler;

	Menu menu(&handler);
	menu.showTitleScreen();

	//encounter.GenerateEncounter();
	//encounter.scrollPick();

	bool worldcomplete = 0;
	int worldcount = 0;

	map* world = handler.getcurrentmapptr();
	static_cast<hero*>(world->getentitylist()[0])->SetMap(world);
	static_cast<hero*>(world->getentitylist()[0])->SetInventory(&inv);

	while (worldcomplete == 0 && world->getentitylist()[0] != nullptr) {

			system("cls");
			handler.printcurrentmap();
			std::cout << std::endl << std::endl;

			entity* player = world->getentitylist()[0];

			if (player != nullptr) {
				std::cout << "you have " << player->gethealth() << "hp left";
				std::cout << "\nLegend:			Control menu: 0\n@ = Soul		Dialogue: k\nW = Cerberus		Inventory menu: I\nH = Harpy\nP = Player\n- = Button";
			}

			static_cast<hero*>(world->getentitylist()[0])->PrintNearbyBoulderPrompt(world->getgameobjectlist());
			static_cast<hero*>(world->getentitylist()[0])->PrintEquippedItemPrompt();

			char input = _getch();

			// ==========================================
			// LET MENU HANDLE SPECIAL KEYS
			// ==========================================

			if (menu.handleGameInput(input))
			{
				continue;
			}

			// Give the hero the key we already read, so movementcheck() doesn't
			// need to (and doesn't) call _getch() itself.
			static_cast<hero*>(world->getentitylist()[0])->SetInput(input);

			// --- movement/collision updates ---
			for (int i = 0; i < world->getentitylistsize(); i++) {
				if (world->getentitylist()[i] == nullptr) continue;
				world->getentitylist()[i]->movementcheck(world->getentitylist(), world->getgameobjectlist(), world->getwalllist());
			}

			// --- door check: has player reached an unlocked door? ---
			door* thedoor = static_cast<door*>(world->getgameobjectlist()[1]);

			if (thedoor != nullptr && player != nullptr &&
				player->getx() == thedoor->getx() && player->gety() == thedoor->gety() &&
				thedoor->geticon() == 'N') {
				// Check if this is the LAST room
				if (handler.getcurrentmap() == 7)
				{
					worldcomplete = 1;
					break;
				}
				encounter.GenerateEncounter();
				encounter.scrollPick();
				handler.setcurrentmap(handler.getcurrentmap() + 1);
				world = handler.getcurrentmapptr(); // refresh pointer — now points at the new map

				// Give the new hero the same inventory
				hero* newHero = static_cast<hero*>(world->getentitylist()[0]);

				newHero->SetInventory(&inv);
				newHero->SetMap(world);
				if (handler.getcurrentmap() == 7){ handler.setcurrentmap(handler.getcurrentmap() + 2); }
			}
	}
	menu.showEnding();
	menu.showCredits();
	return 0;
}