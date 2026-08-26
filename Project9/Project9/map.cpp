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

//this makes everything its just poorly named                          //soul position lol
map::map(int boulderlocation, int buttonlocation, int doorlocation, int Enemy1, int Enemy2, int Item, std::string Wall1, std::string wall2, std::string wall3, std::string wall4, std::string wall5, std::string wall6, std::string wall7, std::string wall8)
{


	srand((unsigned int)time(0));

	entitylist = new entity * [entitylistsize];
	gameobjectlist = new gameobject * [gameobjectlistsize];
	walllist = new wall * [walllistsize];

	for (int i = 0; i < gameobjectlistsize; i++) {
		gameobjectlist[i] = nullptr;
	}
	for (int i = 0; i < entitylistsize; i++) {
		entitylist[i] = nullptr;
	}
	for (int i = 0; i < walllistsize; i++) {
		walllist[i] = nullptr;
	}

	hero* player = new hero(999, 0, 0, 0, 'P', 1, 1);
	entitylist[0] = player;

	for (int i = 1; i < abs(Enemy1); i++) {
		Cerberus* dog = new Cerberus(20, 5, 5, 5, 'W');
		entitylist[i] = dog;
	}
	for (int i = 1 + Enemy1; i < Enemy1 + Enemy2; i++) {
		harpy* Tachy = new harpy(999, 5, rand() % 15, rand() % 15, 'H');
		entitylist[i] = Tachy;
	}


	int value = boulderlocation;
	int part1 = value / 100;
	part1 -= 1;
	int part2 = value % 100;
	part2 -= 1;

	boulder* item = new boulder(part1, part2, 'O');
	gameobjectlist[0] = item;

	value = doorlocation;
	part1 = value / 100;
	part1 -= 1;
	part2 = value % 100;
	part2 -= 1;

	door* DOOR = new door(part1, part2, 'U', 0);
	gameobjectlist[1] = DOOR;

	value = buttonlocation;
	part1 = value / 100;
	part1 -= 1;
	part2 = value % 100;
	part2 -= 1;

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


	// Entity vs Entity (self-check with i != u)
	for (int i = 0; i < entitylistsize; i++) {
		for (int u = 0; u < entitylistsize; u++) {
			if (i != u) {
				if (!(entitylist[i] == nullptr) && !(entitylist[u] == nullptr)) {
					if (entitylist[i]->getx() == entitylist[u]->getx() &&
						entitylist[i]->gety() == entitylist[u]->gety())
					{
						entitylist[i]->setxy(rand() % 15, rand() % 15);
					}
				}
			}
		}
	}

}

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
	char map[15][15];

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < entitylistsize; i++) {
		if (!(entitylist[i] == nullptr)) {
			map[entitylist[i]->gety()][entitylist[i]->getx()] = entitylist[i]->geticon();
		}
	}

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

void map::worldswap()
{
}