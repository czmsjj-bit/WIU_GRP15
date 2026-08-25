#pragma once
#include "entity.h"
#include "gameobject.h"

class Cerberus : public entity
{
public:
    Cerberus(int hp, int atk, int xpos, int ypos, char a);
    void movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
    void Damage(entity* victim);
    int getattack();
    ~Cerberus();

private:
    int attack;
};
