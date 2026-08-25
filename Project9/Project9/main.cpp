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


int main(void) {
	Inventory inventory;
	Inventory inv;

	Encounter encounter;


	encounter.GenerateEncounter();     // stock 3 random scrolls
	encounter.scrollPick(inv);   // player picks one; encounter closes; inventory opens

	//map world;
	////New


	////map printing


	//int num = 0;
	//char input = 'a';

	////so this is how it works the first number is the Y position and the X is the second
	////-> (*...).getfunc

	////lowkey just store all the positions here

	////map gets all cordinates of everything 
	////after everything moves???

	////world.mapx(

	////enemies into 

	////enemies[3]

	////forloop [3]

	//while (enemy::getenemycount() > 0 && world.getentitylist()[0] != nullptr) {
	//	//map rendering
	//	system("cls");
	//	world.print();
	//	std::cout << std::endl;




	//	if (!(world.getentitylist()[0] == nullptr)) {
	//		std::cout << "you have" << world.getentitylist()[0]->gethealth() << "hp left";
	//	}
	//	std::cout << std::endl;
	//	//rebuild the map each time
	//	for (int i = 0; i < 4; i++) {
	//		if (world.getentitylist()[i] == nullptr) {
	//			continue;
	//		}

	//		world.getentitylist()[i]->movementcheck(world.getentitylist(), world.getgameobjectlist());

	//	}

	//}

	//if (world.getentitylist()[0] == nullptr) {
	//	std::cout << "you lost";
	//	std::cout << std::endl;
	//}

	//else {
	//	std::cout << std::endl;
	//	std::cout << "you won!";
	//	std::cout << std::endl;
	//}

	bool worldcomplete = 0;
	int worldcount = 0;

	//zi ming world code goes here 

	//


	//this can only print at max 8 walls
	//if this can run then its perfect already


	map world(0, 0, 0, "0", "0", "520_01", "529_01");






	//map printing


	//enemy1 , enemy2 , nul , 

	int num = 0;
	char input = 'a';

	//so this is how it works the first number is the Y position and the X is the second
	//-> (*...).getfunc

	//lowkey just store all the positions here

	//map gets all cordinates of everything 
	//after everything moves???

	//world.mapx(
	//enemies into 

	//enemies[3]

	//forloop [3]

	while (worldcomplete == 0 && world.getentitylist()[0] != nullptr) {
		//map rendering
		system("cls");
		world.print();
		std::cout << std::endl;



		std::cout << std::endl;

		if (!(world.getentitylist()[0] == nullptr)) {
			std::cout << "you have" << world.getentitylist()[0]->gethealth() << "hp left";
		}





		//rebuild the map each time
		for (int i = 0; i < world.getentitylistsize(); i++) {
			if (world.getentitylist()[i] == nullptr) {
				continue;
			}
			world.getentitylist()[i]->movementcheck(world.getentitylist(), world.getgameobjectlist(), world.getwalllist());

		}

	}
	return 0;
}





//movex
