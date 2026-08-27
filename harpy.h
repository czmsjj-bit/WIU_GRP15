#pragma once
#include "entity.h"
#include "gameobject.h"

class harpy : public entity
{
public:
    harpy(int hp, int atk, int xpos, int ypos, char a);
    void movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
    void Damage(entity* victim);
    void move();
    static int getHarpyCount();
    int getattack();
    ~harpy();

private:
    int attack;
    static int harpycount;
};

