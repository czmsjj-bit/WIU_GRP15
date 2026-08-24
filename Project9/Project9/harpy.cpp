#include "Harpy.h"

#include <iostream>

harpy::harpy(int hp, int atk, int xpos, int ypos, char32_t a)
{
	health = hp;
	attack = atk;
	coordinates.Placex(xpos);
	coordinates.Placey(ypos);
	icon = a;
}

void harpy::move()
{
	int num;
	num = rand() % 4;
	switch (num) {
	case 0:
		sety(gety() - 1);

		break;
	case 1:
		setx(getx() - 1);
		break;
	case 2:
		setx(getx() + 1);
		break;
	case 3:
		sety(gety() + 1);
		break;
	default:
		break;
	}
}
int harpy::getattack() {
	return attack;
}
void harpy::Damage(entity* victim)
{
	victim->sethealth(victim->gethealth() - getattack());
}
void harpy::movementcheck(entity** entitylist, gameobject** gameobjectlist)
{
	if (entitylist[0] == nullptr) {
		return;
	}
	int adjacent = false;

		int dx = std::abs(getx() - entitylist[0]->getx());
			int dy = std::abs(gety()- entitylist[0]->gety());
			//attack on player
			if (dx <= 1 && dy <= 1)
			{
				adjacent = true;
			
			}
		
	


	if (adjacent == true) {
		Damage(entitylist[0]);
		adjacent = false;
		if (entitylist[0]->gethealth() <= 0) {
			delete entitylist[0];
			std::cout << "attacked";
			entitylist[0] = nullptr;

		}
	}
	else {
		int prevx = getx();
		int prevy = gety();

		bool validMove = false;
		int attempts = 0;

		while (!validMove && attempts < 10) {
			setx(prevx);
			sety(prevy);
			move();




			validMove = true;
			for (int u = 0; u < 4; u++) {
				if (entitylist[u] != nullptr && entitylist[u] != this) {
					if (getx() == entitylist[u]->getx() &&
						gety() == entitylist[u]->gety())
					{
						validMove = false;
					}
				}
			}




			for (int u = 0; u < 3; u++) {
				if (gameobjectlist[u] != nullptr) {
					if (getx() == gameobjectlist[u]->getx() &&
						gety() == gameobjectlist[u]->gety())
					{
						validMove = false;
					}
				}
			}
			attempts++;
		}

	}
}

