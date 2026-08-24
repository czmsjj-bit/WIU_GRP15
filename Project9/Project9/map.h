#pragma once
#include "entity.h"
#include "healthorb.h"
#include "hero.h"
#include "goblin.h"
#include "boulder.h"
#include "gameobject.h"
#include "harpy.h"
#include "wall.h"

class map

{

public:
	wall** getwalllist();
	gameobject** getgameobjectlist();
	entity** getentitylist();

	//
	int getentitylistsize();

	map(int Enemy1, int Enemy2, int Item, std::string wall1, std::string wall2, std::string wall3, std::string wall4);

	void getmapcount() {

	}

	// ROOM GENERATION
	void room1();
	void room2();
	void room3();
	void worldswap();

	~map();
	void print();
	int digit(char c);

private:
	entity** entitylist;
	gameobject** gameobjectlist;
	wall** walllist;

	int entitylistsize = 10;
	int gameobjectlistsize = 10;
	int maxenemycount = 0;
	int walllistsize = 100;

	// ROOM GENERATION
	int currentroom = 1;

	static int mapcount;

};