#include "goblin.h"
#include <iostream>

int goblin::goblincount = 0;
goblin::goblin(int hp, int atk, int xpos, int ypos, char a)
{
	goblincount++;
	health = hp;
	attack = atk;
	coordinates.Placex(xpos);
	coordinates.Placey(ypos);
	icon = a;
}

//return health 
void goblin::Damage(entity* victim)
{

	//this work
	victim->sethealth(victim->gethealth() - getattack());
}

void goblin::move()
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

goblin:: ~goblin() {
	goblincount--;
}
int goblin::getgoblincount() {
	return goblincount;
}
int goblin::getattack() {
	return attack;
}

void goblin::movementcheck(entity** entitylist, gameobject** gameobjectlist  , wall** walllist)
{
	if (entitylist[0] == nullptr) {
		return;
	}
	int dx = std::abs(getx() - entitylist[0]->getx());
	int dy = std::abs(gety() - entitylist[0]->gety());

	if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1))
	{
		Damage(entitylist[0]);
		if (entitylist[0]->gethealth() <= 0) {
			delete entitylist[0];
			entitylist[0] = nullptr;
		}
	}
	else {

		//no longer attack func

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



			/*hello i check if any items interact with 
			
			
			*/
			for (int u = 0; u < 3; u++) {
				if (gameobjectlist[u] != nullptr) {
					if (getx() == gameobjectlist[u]->getx() &&
						gety() == gameobjectlist[u]->gety())
					{
						validMove = false;   // goblins treat items as obstacles, don't pick them up
					}
				}
			}
			attempts++;
		}
	}
	}





