#pragma once
#include "entity.h"
#include "gameobject.h"



//when you get into a range around this unit it says 

//haha i am tachyon and then puts M all around the map 




class harpy : public entity
{
public:
	harpy(int hp, int atk, int xpos, int ypos, char32_t a);


	void Damage(entity* victim);

	int getattack();

	void move();

	void movementcheck(entity** entitylist, gameobject** gameobjectlist ,wall** walllist) override;

private:
	int health;
	int attack;
};

