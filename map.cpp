#include "map.h"
#include <iostream>
#include "wall.h"
#include "Cerberus.h"
#include "soul.h"

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
map::map(int boulderlocation, int buttonlocation, int doorlocation, int Enemy1, int Enemy2, int Item, std::string Wall1, std::string wall2, std::string wall3, std::string wall4, std::string wall5, std::string wall6, std::string wall7, std::string wall8)
{

	srand((unsigned int)time(0));

	entitylist = new entity * [entitylistsize]; //SAME HERE 
	//1 HERO 
	//3 GOBLINS

	gameobjectlist = new gameobject * [gameobjectlistsize]; //CHANGE GAMEOBJECT LIST TO HOWEVER YOU LIKE
	//THIS CONTAINS LIKE 1 boulder

	walllist = new wall * [walllistsize]; //CHANGE GAMEOBJECT LIST TO HOWEVER YOU LIKE

	//intialises all spots in gameobjectlist
	for (int i = 0; i < gameobjectlistsize; i++) {
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
	hero* player = new hero(100, 0, 0, 0, 'P', 1, 1);
	entitylist[0] = player;

	//out of the 7 objects 4 have been created
		for (int i = 1; i < abs(Enemy1); i++) {
			Cerberus* dog = new Cerberus(20, 5, 5, 5, 'W');
			entitylist[i] = dog;

		}
		//goblin(int hp, int atk, int xpos, int ypos, char a);
	
	for (int i = 1 + Enemy1; i < Enemy1 + Enemy2; i++) {

		harpy* Tachy = new harpy(999, 5, rand() % 15, rand() % 15, 'H');
		entitylist[i] = Tachy;
	}

	//ORIGNAL CLASS CONSTRUCTOR AREA FOR OBJECTS still is...


	int value = boulderlocation;
	int part1 = value / 100;   // 14
	int part2 = value % 100;   // 4


	boulder* item = new boulder(part1, part2, 'O');

	gameobjectlist[0] = item;
	value = doorlocation;
	part1 = value / 100;   // 14
	part2 = value % 100;   // 4


	door* DOOR = new door(part1, part2, 'U', 0);

	gameobjectlist[1] = DOOR;

	value = buttonlocation;
	part1 = value / 100;   // 14
	part2 = value % 100;   // 4
	button* BUTTON = new button(part1, part2, '-', 0);
	gameobjectlist[2] = BUTTON;

	// Item==0 decodes to (-1,-1), which is out of bounds.
// Guarded so a placeholder Item of 0 doesn't create an invalid soul.
	if (Item != 0) {
		value = Item;
		part1 = value / 100;
		part1 -= 1;
		part2 = value % 100;
		part2 -= 1;
		soul* Soul = new soul(part1, part2, '@');
		gameobjectlist[3] = Soul;
	}

	//amount of walls
	int offset = 1;
	int wallx;
	int wally;
	if (!(Wall1[0] == '0')) {
		wallx = (upgradeddigit(Wall1[1], Wall1[2])) - 1;
		wally = (upgradeddigit(Wall1[3], Wall1[4])) - 1;
		int count = digit(Wall1[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, Wall1[5]);

			if (Wall1[6] == 'y') {
				wally += 1;
			}
			if (Wall1[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall2[0] == '0')) {
		wallx = (upgradeddigit(wall2[1], wall2[2])) - 1;
		wally = (upgradeddigit(wall2[3], wall2[4])) - 1;
		int count = digit(wall2[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall2[5]);

			if (wall2[6] == 'y') {
				wally += 1;
			}
			if (wall2[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall3[0] == '0')) {
		wallx = (upgradeddigit(wall3[1], wall3[2])) - 1;
		wally = (upgradeddigit(wall3[3], wall3[4])) - 1;
		int count = digit(wall3[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall3[5]);

			if (wall3[6] == 'y') {
				wally += 1;
			}
			if (wall3[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall4[0] == '0')) {
		wallx = (upgradeddigit(wall4[1], wall4[2])) - 1;
		wally = (upgradeddigit(wall4[3], wall4[4])) - 1;
		int count = digit(wall4[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall4[5]);

			if (wall4[6] == 'y') {
				wally += 1;
			}
			if (wall4[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall5[0] == '0')) {
		wallx = (upgradeddigit(wall5[1], wall5[2])) - 1;
		wally = (upgradeddigit(wall5[3], wall5[4])) - 1;
		int count = digit(wall5[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall5[5]);

			if (wall5[6] == 'y') {
				wally += 1;
			}
			if (wall5[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall6[0] == '0')) {
		wallx = (upgradeddigit(wall6[1], wall6[2])) - 1;
		wally = (upgradeddigit(wall6[3], wall6[4])) - 1;
		int count = digit(wall6[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall6[5]);

			if (wall6[6] == 'y') {
				wally += 1;
			}
			if (wall6[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall7[0] == '0')) {
		wallx = (upgradeddigit(wall7[1], wall7[2])) - 1;
		wally = (upgradeddigit(wall7[3], wall7[4])) - 1;
		int count = digit(wall7[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall7[5]);

			if (wall7[6] == 'y') {
				wally += 1;
			}
			if (wall7[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	if (!(wall8[0] == '0')) {
		wallx = (upgradeddigit(wall8[1], wall8[2])) - 1;
		wally = (upgradeddigit(wall8[3], wall8[4])) - 1;
		int count = digit(wall8[0]);
		for (int i = 0; i < count; i++) {
			wall* WallS = new wall(wallx, wally, wall8[5]);

			if (wall8[6] == 'y') {
				wally += 1;
			}
			if (wall8[7] == 'y') {
				wallx += 1;
			}
			walllist[offset + i] = WallS;
		}
		offset += count;
	}


	//should create a 3x1 dead center 



//    }
	//loops through everything once to check if sm guy acting sussy and suspicuous

	for (int i = 0; i < entitylistsize; i++) {
		for (int i = 1; i < entitylistsize; i++) {
			if (entitylist[i] == nullptr) continue;

			int attempts = 0;
			while (isPositionBlocked(entitylist[i]->getx(), entitylist[i]->gety(), entitylist[i]) && attempts < 100) {
				entitylist[i]->setxy(rand() % 15, rand() % 15);
				attempts++;
			}
		}
	}
}

bool map::isPositionBlocked(int x, int y, entity* ignoreEntity)
{
	for (int i = 0; i < entitylistsize; i++) {
		if (entitylist[i] != nullptr && entitylist[i] != ignoreEntity) {
			if (entitylist[i]->getx() == x && entitylist[i]->gety() == y) {
				return true;
			}
		}
	}
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

	// i get the full map and print out everything 


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

int map::upgradeddigit(char a, char c) {
	std::string bothadded;
	bothadded += a;
	bothadded += c;
	int result = std::stoi(bothadded);
	return result;
}

// Reset the current room back to its original layout

void map::reset(map* originalmap)
{
	// Reset player
	if (!(entitylist[0] == nullptr)) {
		entitylist[0]->setxy(0, 0);
	}

	// Reset boulder
	if (!(gameobjectlist[0] == nullptr) && !(originalmap->getgameobjectlist()[0] == nullptr)) {
		gameobjectlist[0]->setxy(
			originalmap->getgameobjectlist()[0]->getx(),
			originalmap->getgameobjectlist()[0]->gety()
		);
	}

	// Reset door
	if (!(gameobjectlist[1] == nullptr) && !(originalmap->getgameobjectlist()[1] == nullptr)) {
		gameobjectlist[1]->setxy(
			originalmap->getgameobjectlist()[1]->getx(),
			originalmap->getgameobjectlist()[1]->gety()
		);
	}

	// Reset button
	if (!(gameobjectlist[2] == nullptr) && !(originalmap->getgameobjectlist()[2] == nullptr)) {
		gameobjectlist[2]->setxy(
			originalmap->getgameobjectlist()[2]->getx(),
			originalmap->getgameobjectlist()[2]->gety()
		);
	}

	// Reset walls
	for (int i = 0; i < walllistsize; i++) {
		if (!(walllist[i] == nullptr) && !(originalmap->getwalllist()[i] == nullptr)) {
			walllist[i]->setxy(
				originalmap->getwalllist()[i]->getx(),
				originalmap->getwalllist()[i]->gety()
			);
		}
	}
}


// creation of dots

// hero // enemy1 // enemy2 use troublesome method

// boulder, button, door use troublesome method

// wall use the string method

void map::worldswap()
{

}