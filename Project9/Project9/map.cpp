#include "map.h"
#include <iostream>
#include "wall.h"

wall** map::getwalllist()
{
	return walllist;
}

gameobject** map::getgameobjectlist()
{
	return gameobjectlist;
}

entity** map::getentitylist() {
	return entitylist;
}

int map::getentitylistsize() {
	return entitylistsize;
}

int map::mapcount = 9;


// ROOM GENERATION
map::map(int Enemy1, int Enemy2, int Item, std::string Wall1, std::string wall2, std::string wall3, std::string wall4)
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

	// Generate the first room
	worldswap();
}


// ROOM 1
void map::room1()
{
	// Clear previous room
	for (int i = 0; i < entitylistsize; i++) {
		delete entitylist[i];
		entitylist[i] = nullptr;
	}

	for (int i = 0; i < gameobjectlistsize; i++) {
		delete gameobjectlist[i];
		gameobjectlist[i] = nullptr;
	}

	for (int i = 0; i < walllistsize; i++) {
		delete walllist[i];
		walllist[i] = nullptr;
	}


	// PLAYER
	hero* player = new hero(999, 0, 1, 1, 'P', 1, 1);
	entitylist[0] = player;


	// ENEMIES
	goblin* Goblin1 = new goblin(20, 5, 5, 5, 'G');
	entitylist[1] = Goblin1;

	goblin* Goblin2 = new goblin(20, 5, 10, 10, 'G');
	entitylist[2] = Goblin2;


	// OBJECT
	boulder* item = new boulder(7, 7, 'O');
	gameobjectlist[0] = item;


	// WALLS
	// Example walls for Room 1

	walllist[0] = new wall(0, 0, '#');
	walllist[1] = new wall(0, 1, '#');
	walllist[2] = new wall(0, 2, '#');
	walllist[3] = new wall(0, 3, '#');
	walllist[4] = new wall(0, 4, '#');
}


// ROOM 2
void map::room2()
{
	// Clear previous room
	for (int i = 0; i < entitylistsize; i++) {
		delete entitylist[i];
		entitylist[i] = nullptr;
	}

	for (int i = 0; i < gameobjectlistsize; i++) {
		delete gameobjectlist[i];
		gameobjectlist[i] = nullptr;
	}

	for (int i = 0; i < walllistsize; i++) {
		delete walllist[i];
		walllist[i] = nullptr;
	}


	// PLAYER
	hero* player = new hero(999, 0, 1, 1, 'P', 1, 1);
	entitylist[0] = player;


	// ENEMIES
	goblin* Goblin1 = new goblin(20, 5, 4, 4, 'G');
	entitylist[1] = Goblin1;

	goblin* Goblin2 = new goblin(20, 5, 8, 8, 'G');
	entitylist[2] = Goblin2;

	harpy* Tachy = new harpy(999, 5, 12, 5, U'ン');
	entitylist[3] = Tachy;


	// OBJECT
	boulder* item = new boulder(10, 10, 'O');
	gameobjectlist[0] = item;


	// WALLS
	// Example walls for Room 2

	walllist[0] = new wall(0, 0, '#');
	walllist[1] = new wall(0, 1, '#');
	walllist[2] = new wall(0, 2, '#');
	walllist[3] = new wall(0, 3, '#');
	walllist[4] = new wall(1, 3, '#');
	walllist[5] = new wall(2, 3, '#');
}


// ROOM 3
void map::room3()
{
	// Clear previous room
	for (int i = 0; i < entitylistsize; i++) {
		delete entitylist[i];
		entitylist[i] = nullptr;
	}

	for (int i = 0; i < gameobjectlistsize; i++) {
		delete gameobjectlist[i];
		gameobjectlist[i] = nullptr;
	}

	for (int i = 0; i < walllistsize; i++) {
		delete walllist[i];
		walllist[i] = nullptr;
	}


	// PLAYER
	hero* player = new hero(999, 0, 1, 1, 'P', 1, 1);
	entitylist[0] = player;


	// ENEMIES
	goblin* Goblin1 = new goblin(20, 5, 4, 4, 'G');
	entitylist[1] = Goblin1;

	goblin* Goblin2 = new goblin(20, 5, 8, 4, 'G');
	entitylist[2] = Goblin2;

	harpy* Tachy1 = new harpy(999, 5, 5, 10, U'ン');
	entitylist[3] = Tachy1;

	harpy* Tachy2 = new harpy(999, 5, 10, 10, U'ン');
	entitylist[4] = Tachy2;


	// OBJECT
	boulder* item = new boulder(7, 7, 'O');
	gameobjectlist[0] = item;


	// WALLS
	// Example walls for Room 3

	walllist[0] = new wall(0, 0, '#');
	walllist[1] = new wall(0, 1, '#');
	walllist[2] = new wall(0, 2, '#');
	walllist[3] = new wall(0, 3, '#');
	walllist[4] = new wall(1, 3, '#');
	walllist[5] = new wall(2, 3, '#');
	walllist[6] = new wall(2, 4, '#');
	walllist[7] = new wall(2, 5, '#');
}


// SWITCH BETWEEN ROOMS
void map::worldswap()
{
	switch (currentroom)
	{
	case 1:
		room1();
		break;

	case 2:
		room2();
		break;

	case 3:
		room3();
		break;
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

	mapcount--;
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