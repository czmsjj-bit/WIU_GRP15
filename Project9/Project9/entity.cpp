#include "entity.h"
#include <iostream>
#include "goblin.h"
#include "map.h"
//attack function]]
void entity::setattack(int atack) {
	return;
}

void entity::sethealth(int Health)
{
	health = Health;
}



int entity::gethealth()
{
	return health;
}

int entity::getrange() {
	return range;
}

entity::entity()
{
	coordinates = Coordinates();
	entitylist = nullptr;
	health = 0;
	range = 0;
	icon = 'a';
}

entity::~entity()
{
	return;
}

void entity::seticon(char a)
{
	return;
}

char entity::geticon() {

	return icon;

}

Coordinates entity::getxy()
{

	return coordinates;
}

int entity::getx()
{
	return coordinates.Returnx();

}

int entity::gety()
{
	return coordinates.Returny();
}
void entity::sety(int y)
{
	if (!(y == -1 || y == 15)) {
		coordinates.Placey(y);
	}
	else {
		std::cout << "invalid input";
	}
}

void entity::setxy(int y, int x)
{

	if (!(x == -1 || x == 15 || y == -1 || y == 15)) {
		coordinates.Placex(x);
		coordinates.Placey(y);

	}
	else {
		std::cout << "invalid input";
	}



}


void entity::setx(int x)
{
	if (!(x == -1 || x == 15)) {
		coordinates.Placex(x);


	}
	else {
		std::cout << "invalid input";
	}
}








