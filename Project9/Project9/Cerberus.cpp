
#include "cerberus.h"
#include <iostream>
#include <cstdlib>   // for abs()

Cerberus::Cerberus(int hp, int atk, int xpos, int ypos, char a)
{
    health = hp;
    attack = atk;
    coordinates.Placex(xpos);
    coordinates.Placey(ypos);
    icon = a;
}

void Cerberus::Damage(entity* victim)
{
    victim->sethealth(victim->gethealth() - getattack());
}

int Cerberus::getattack()
{
    return attack;
}

Cerberus::~Cerberus()
{
    // nothing extra needed
}

void Cerberus::movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    // Cerberus never moves. He only checks if the player is in his row,
    // one row above, or one row below, and attacks if so.

    if (entitylist[0] == nullptr) {
        return;   // player is dead
    }

    int boulderY = gameobjectlist[0]->gety();
    int playerY = entitylist[0]->gety();
    int myY = gety();

    // If the player is on the same row, one above, or one below

    // lol if boulder y does not == playery and bouldery d
    if (!((std::abs(boulderY - myY) <= 1) && (boulderY == playerY)))
    if (std::abs(playerY - myY) <= 1) {
        Damage(entitylist[0]);
        if (entitylist[0]->gethealth() <= 0) {
            delete entitylist[0];
            entitylist[0] = nullptr;
            std::cout << "Cerberus devoured the hero!" << std::endl;
        }
    }
    // No movement logic – he stays put.
}
