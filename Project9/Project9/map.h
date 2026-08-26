#pragma once
#include "entity.h"
#include "healthorb.h"
#include "hero.h"
#include "goblin.h"
#include "boulder.h"
#include "gameobject.h"
#include "harpy.h"
#include "wall.h"
#include "door.h"
#include "button.h"
#include "soul.h"

class map
{
protected:


public:
	wall** getwalllist();
	gameobject** getgameobjectlist();
	entity** getentitylist();

	//
	int getentitylistsize();

	map(int boulderlocation, int buttonlocation, int doorlocation, int Enemy1, int Enemy2, int Item, std::string Wall1, std::string wall2, std::string wall3, std::string wall4, std::string wall5, std::string wall6, std::string wall7, std::string wall8);

	

	



	//added boulder location button location and hero location 
	


	void worldswap();


	~map();
	void print();


	

	int digit(char c);

	int upgradeddigit(char a, char c);

	int digit2(const std::string& s, int startIndex);

	//this is a pointer that points to a list full of entity pointers

	//create

	//map.entity = new

	//entitylist = entity* entitylist[9] 

	//


private:
	entity** entitylist;
	gameobject** gameobjectlist;
	wall** walllist;
	int entitylistsize = 10;
	int gameobjectlistsize = 10;
	int maxenemycount = 0;
	int walllistsize = 100;


};

