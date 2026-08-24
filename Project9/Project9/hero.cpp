#include "hero.h"
#include "map.h"
#include "boulder.h"
#include "wall.h"
#include <iostream>
#include <conio.h>
hero::hero(int hp, int atk, int xpos, int ypos, char a, int rng, bool Status)
{
	health = hp;
	attack = atk;
	coordinates.Placey(ypos);
	coordinates.Placex(xpos);
	icon = a;
	range = rng;
	status = Status;

}




//include thread include chrono



void hero::movementcheck(entity** entitylist, gameobject** gameobjectlist , wall** walllist)

{
	gameobject* target = nullptr;
	boulder* b = nullptr;
	for (int u = 0; u < 3; u++) {
		if (gameobjectlist[u] != nullptr) {

			b = dynamic_cast<boulder*>(gameobjectlist[u]);
			if (b == nullptr) continue;

			int dx = std::abs(getx() - gameobjectlist[u]->getx());
			int dy = std::abs(gety() - gameobjectlist[u]->gety());
			bool isInRange = (dx <= 1 && dy == 0) || (dx == 0 && dy <= 1);
			if (isInRange) {
				target = gameobjectlist[u];

				//this check if its a boulder so 

				if (target->geticon() == 'O') {

					if (target)
						std::cout << std::endl;
					std::cout << "Theres a boulder you can grab (press g to grab): ";


				}
				else if (target->geticon() == '0') {
						if (target)
							std::cout << std::endl;
					std::cout << "You are grabbing a boulder (Press g to drop): ";


				}
			}
		}
	}


	//nvm its ok 

	int prevx = getx();
	int prevy = gety();


	char input = _getch();

	if (target != nullptr) {
		if (b->geticon() == '0') {
			b->validmovecheck(input, entitylist, gameobjectlist, walllist);

			if (b->getgrabstatus() == 0) {
				b->setgrabstatus(1);
				return;
			}
		}
		//boulder code here 
	}



	
	switch (input) {
	case 'w':
		sety(gety() - 1);
	

		break;
	case 'a':

		setx(getx() - 1);


		break;
	case 'd':
		setx(getx() + 1);

		break;
	case's':
		sety(gety() + 1);

		break;
	//if boulder is currently grabbed use boulder check to check if the boulder can be moved

	


		//idea use static cast on this to call boulder move function 

		//

	case'g': //universal grab for button
		if (!(target == nullptr)) {
			if (target->geticon() == '0' || target->geticon() == 'O')
				if (target->geticon() == 'O') {
					target->seticon('0');
					break;
				}
			if (target->geticon() == '0') {
				target->seticon('O');
				break;
			}
		}
		break;

	default:
		std::cout << "invalid input";
	}

	//runs thru the item list 
	for (int u = 0; u < 4; u++) {
		if (u == 0) { // checking for itself
			//if gameobject
			if (!(target == nullptr)) {
				
			}
			continue;
		}
		if (entitylist[u] != nullptr) {
			if (getx() == entitylist[u]->getx() &&
				gety() == entitylist[u]->gety())
			{
				setx(prevx);
				sety(prevy);
				return;
			}
		}
	}

	//run through walllist


	for (int u = 0; u < 100; u++) {
		if (walllist[u] != nullptr) {
			if (getx() == walllist[u]->getx() &&
				gety() == walllist[u]->gety())
			{
				setx(prevx);
				sety(prevy);

			}
		}
	}
	//remeber its called a destructor
	for (int u = 0; u < 3; u++) {
		if (gameobjectlist[u] != nullptr) {
			if (getx() == gameobjectlist[u]->getx() &&
				gety() == gameobjectlist[u]->gety())
			{

				////uh if you set your icon for your wall to be T it becomes a wall now
				//if (gameobjectlist[u]->geticon() == '_') {
				//	setx(prevx);
				//	sety(prevy);
				//	return;
				//}
				////i am a boulder pushing 






				//boulder pushing time 
				if (gameobjectlist[u]->geticon() == 'O' || gameobjectlist[u]->geticon() == '0') {

					std::cout << "boulder push";
					setx(prevx);
					sety(prevy);




					return;
				}
			}
		}
	}
}
void hero::setattack(int atack) {
	attack = atack;
}
int hero::getattack() {
	return attack;
}