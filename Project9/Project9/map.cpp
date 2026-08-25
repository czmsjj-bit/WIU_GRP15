#include "map.h"
#include <iostream>
#include "wall.h"
#include "Cerberus.h"

//

wall** map::getwalllist()
{
	return walllist;
}

gameobject** map::getgameobjectlist()
{
	return gameobjectlist;
}

//make a whole function for rendering
entity** map::getentitylist() {
	return entitylist;
}

int map::getentitylistsize() {
	return entitylistsize;
}







//this makes everything its just poorly named
map::map(int buttonlocation , int doorlocation ,int Enemy1, int Enemy2, int Item, std::string Wall1, std::string wall2, std::string wall3, std::string wall4 , std::string wall5 , std::string wall6 , std::string wall7 , std::string wall8)
{

	
	srand((unsigned int)time(0));

	entitylist = new entity * [entitylistsize]; //SAME HERE 
	//1 HERO 
	//3 GOBLINS

	gameobjectlist = new gameobject * [gameobjectlistsize]; //CHANGE GAMEOBJECT LIST TO HOWEVER YOU LIKE
	//THIS CONTAINS LIKE 1 boulder

	walllist = new wall * [walllistsize]; //CHANGE GAMEOBJECT LIST TO HOWEVER YOU LIKE

	//intialises all spots in gameobjectlist
	for (int i = 0 ; i < gameobjectlistsize ; i++){
		gameobjectlist[i] = nullptr;
	}
	//initialsises all spots in entity list
	for (int i = 0; i < entitylistsize; i++) {
		entitylist[i] = nullptr;
	}
	for (int i = 0; i < walllistsize; i++) {
		walllist[i] = nullptr;
	}



	//assumed wall list goes here 
	
	//1404



	

	//void hero::spawn(int hp, int atk, int xpos, int ypos, char a, int rng)
	hero* player = new hero(999, 0, 0, 0, 'P', 1, 1);
	entitylist[0] = player;

	//out of the 7 objects 4 have been created
	
	for (int i = 1; i < abs(Enemy1); i++) {
		Cerberus* dog = new Cerberus(20, 5, 5, 5, 'W');
		entitylist[i] = dog;


		//goblin(int hp, int atk, int xpos, int ypos, char a);
	}
	for (int i = 1+Enemy1; i < Enemy1 + Enemy2; i++) {
		
		harpy * Tachy = new harpy(999, 5, rand() % 15, rand() % 15, 'H');
		entitylist[i] = Tachy;
	}
	//ORIGNAL CLASS CONSTRUCTOR AREA FOR OBJECTS still is...


	int value = buttonlocation;
	int part1 = value / 100;   // 14
	int part2 = value % 100;   // 4


	boulder* item = new boulder(part1, part2 , 'O');

	gameobjectlist[0] = item;
	value = doorlocation;
	 part1 = value / 100;   // 14
	 part2 = value % 100;   // 4


	door* DOOR = new door(part1, part2, 'U' , 0);

	gameobjectlist[1] = DOOR;

	button* BUTTON = new button(10, 10, '-', 0);
	gameobjectlist[2] = BUTTON;


	//amount of walls
	int offset = 1;
	if (!(Wall1[0] == '0')) {
		
		int count = digit(Wall1[0]);
		for (int i = 0; i < count; i++) {
			

			           
			wall* WallS = new wall(digit(Wall1[1]) -1 + digit(Wall1[4]), //y
				digit(Wall1[2]) -1 + digit(Wall1[5]), // x
			Wall1[3]); //icon

			if (!(digit(Wall1[4]) == 0)) {
				Wall1[4] += 1;
			}
			if (!(digit(Wall1[5]) == 0)) {
				Wall1[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}



	if (!(wall2[0] == '0')) {
		
		int count = digit(wall2[0]);
		for (int i = 0; i < count ; i++) {
			


			wall* WallS = new wall(digit(wall2[1]) - 1 + digit(wall2[4]),
				digit(wall2[2]) - 1 + digit(wall2[5]),
				wall2[3]);


			if (!(digit(wall2[4]) == 0)) {
				wall2[4] += 1;
			}
			if (!(digit(wall2[5]) == 0)) {
				wall2[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}




	if (!(wall3[0] == '0')) {
		int count = digit(wall3[0]);
		for (int i = 0; i < count; i++) {
		


			wall* WallS = new wall(digit(wall3[1]) - 1 + digit(wall3[4]),
				digit(wall3[2]) - 1 + digit(wall3[5]),
				wall3[3]);
			if (!(digit(wall3[4]) == 0)) {
				wall3[4] += 1;
			}
			if (!(digit(wall3[5]) == 0)) {
				wall3[5] += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}



	if (!(wall4[0] == '0')) {
		int count = digit(wall4[0]);


		//correct amount of thingies printed wrong number of shi
		for (int i = 0; i < count ; i++) {

			wall* WallS = new wall(digit(wall4[1]) - 1 + digit(wall4[4]),
				digit(wall4[2]) - 1 + digit(wall4[5]),
				wall4[3]);
			if (!(digit(wall4[4]) == 0)) {
				wall4[4] += 1;
			}
			if (!(digit(wall4[5]) == 0)) {
				wall4[5] += 1;
			}
			walllist[offset + i] = WallS;
		
		}
		offset += count;
	}

	if (!(wall5[0] == '0')) {
		int count = digit(wall5[0]);


		//correct amount of thingies printed wrong number of shi
		for (int i = 0; i < count; i++) {

			wall* WallS = new wall(digit(wall5[1]) - 1 + digit(wall5[4]),
				digit(wall5[2]) - 1 + digit(wall4[5]),
				wall5[3]);
			if (!(digit(wall5[4]) == 0)) {
				wall5[4] += 1;
			}
			if (!(digit(wall4[5]) == 0)) {
				wall5[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}

	if (!(wall6[0] == '0')) {
		int count = digit(wall6[0]);


		//correct amount of thingies printed wrong number of shi
		for (int i = 0; i < count; i++) {

			wall* WallS = new wall(digit(wall6[1]) - 1 + digit(wall6[4]),
				digit(wall6[2]) - 1 + digit(wall7[5]),
				wall6[3]);
			if (!(digit(wall6[4]) == 0)) {
				wall6[4] += 1;
			}
			if (!(digit(wall4[5]) == 0)) {
				wall6[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}

	if (!(wall6[0] == '0')) {
		int count = digit(wall6[0]);


		//correct amount of thingies printed wrong number of shi
		for (int i = 0; i < count; i++) {

			wall* WallS = new wall(digit(wall7[1]) - 1 + digit(wall7[4]),
				digit(wall7[2]) - 1 + digit(wall7[5]),
				wall7[3]);
			if (!(digit(wall7[4]) == 0)) {
				wall7[4] += 1;
			}
			if (!(digit(wall4[5]) == 0)) {
				wall7[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}
	if (!(wall8[0] == '0')) {
		int count = digit(wall8[0]);


		//correct amount of thingies printed wrong number of shi
		for (int i = 0; i < count; i++) {

			wall* WallS = new wall(digit(wall8[1]) - 1 + digit(wall8[4]),
				digit(wall8[2]) - 1 + digit(wall8[5]),
				wall8[3]);
			if (!(digit(wall8[4]) == 0)) {
				wall8[4] += 1;
			}
			if (!(digit(wall4[5]) == 0)) {
				wall8[5] += 1;
			}
			walllist[offset + i] = WallS;

		}
		offset += count;
	}


	//should create a 3x1 dead center 



//    }
	//loops through everything once to check if sm guy acting sussy and suspicuous


	// Entity vs Entity (self-check with i != u)
	for (int i = 0; i < entitylistsize; i++) {
		for (int u = 0; u < entitylistsize; u++) {
			if (i != u) {
				if (!(entitylist[i] == nullptr) && !(entitylist[u] ==nullptr)) {
					if (entitylist[i]->getx() == entitylist[u]->getx() &&
						entitylist[i]->gety() == entitylist[u]->gety())
					{
						entitylist[i]->setxy(rand() % 15, rand() % 15);
					}
				}
			}
		}
	}

	//// Entity vs GameObject (no self-check needed — different arrays, never the same object)
	//for (int i = 0; i < 4; i++) {
	//	for (int u = 0; u < 3; u++) {
	//		if (entitylist[i]->getx() == gameobjectlist[u]->getx() &&
	//			entitylist[i]->gety() == gameobjectlist[u]->gety())
	//		{
	//			entitylist[i]->setxy(rand() % 10, rand() % 10);
	//		}
	//	}
	//}

	//// GameObject vs GameObject (self-check with i != u)
	//for (int i = 0; i < 3; i++) {
	//	for (int u = 0; u < 3; u++) {
	//		if (i != u) {
	//			if (gameobjectlist[i]->getx() == gameobjectlist[u]->getx() &&
	//				gameobjectlist[i]->gety() == gameobjectlist[u]->gety())
	//			{
	//				gameobjectlist[i]->setxy(rand() % 10, rand() % 10);
	//			}
	//		}
	//	}
	//}

	//// GameObject vs Entity (no self-check needed — different arrays)
	//for (int i = 0; i < 3; i++) {
	//	for (int u = 0; u < 4; u++) {
	//		if (gameobjectlist[i]->getx() == entitylist[u]->getx() &&
	//			gameobjectlist[i]->gety() == entitylist[u]->gety())
	//		{
	//			gameobjectlist[i]->setxy(rand() % 10, rand() % 10);
	//		}
	//	}
	//}

	//healthorb(int a, int xpos, int ypos, char a);
	// 
	// 
	// 
	//generate the 2 health globe

}

//player icon //player y //player x

//it should take in my entity list


//now i need to loop thru entity list 

//how tf does one do that 

map::~map()
{
	for (int i = 0; i < entitylistsize; i++) {
		delete entitylist[i];
	}
	delete[] entitylist;

	for (int i = 0; i < gameobjectlistsize; i++) {
		delete gameobjectlist[i];
	}
	delete[] gameobjectlist;

	for (int i = 0; i < walllistsize; i++) {
		delete walllist[i];
	}
	delete[] walllist;
}



void map::print()
{

	//this initialises every part of the array first by filling everything in [10][10] with dots 
	//if this is changed replace the 10s in the foreloop here



	char map[15][15];//lol

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			map[i][j] = ' ';
		}
	}
	//hello just read me i explain
//this gets sets the x then sets the y followed by getting the icon repeats
	for (int i = 0; i < entitylistsize; i++) {
		if (!(entitylist[i] == nullptr)) {
			map[entitylist[i]->gety()][entitylist[i]->getx()] = entitylist[i]->geticon();
		}

	}

	//hello just read me i explain
	//this gets sets the x then sets the y followed by getting the icon repeats





	//temp disable 
	// 
	// 
	for (int i = 0; i < gameobjectlistsize; i++) {
		if (!(gameobjectlist[i] == nullptr)) {
			map[gameobjectlist[i]->gety()][gameobjectlist[i]->getx()] = gameobjectlist[i]->geticon();
		}
	}



	for (int i = 0; i < walllistsize; i++) {
		if (!(walllist[i] == nullptr)) {
			map[walllist[i]->gety()][walllist[i]->getx()] = walllist[i]->geticon();
		}
	}




	//if your adding a newlist aka me(jayden)
	//for (int i = 0; i < 3; i++) {
	//	if (!(YOURLIST[i] == nullptr)) { //basically if the object ur printing does not exist it does not print

	//		map[gameobjectlist[i]->gety()][gameobjectlist[i]->getx()] = gameobjectlist[i]->geticon();
	//	}
	//}


	// i get the full map and print out everything 

	for (int i = 0; i < 15; i++) {
	}

	for (int i = 0; i < 15; i++) {
		std::cout << std::endl;
		std::cout << '|';
		for (int j = 0; j < 15; j++) {
			std::cout << map[i][j];

		}
		std::cout << '|';
	}
}

int map::digit(char c)
{
	return c - '0';
}





//creation of dots

//hero //enemy1 // enemy2 use troublesome method

//boulder , button , door use troublesome method

//wall use the string method

void map::worldswap()
{

	



}
