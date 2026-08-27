#include "gameobject.h"





char gameobject::geticon() {

	return icon;

}

void gameobject::seticon(char a)
{
	icon = a;
}


Coordinates gameobject::getxy()
{

	return coordinates;
}

int gameobject::getx()
{
	return coordinates.Returnx();

}

int gameobject::gety()
{
	return coordinates.Returny();
}
void gameobject::sety(int y)
{
	if (!(y == -1 || y == 15)) {
		coordinates.Placey(y);
	}
	else {

	}
}

void gameobject::setxy(int y, int x)
{

	if (!(x == -1 || x == 1 || y == -1 || y == 15)) {
		coordinates.Placex(x);
		coordinates.Placey(y);

	}
	else {
		std::cout << "invalid input";
	}



}


void gameobject::setx(int x)
{
	if (!(x == -1 || x == 15)) {
		coordinates.Placex(x);


	}
	else {
		std::cout << "invalid input";
	}
}








