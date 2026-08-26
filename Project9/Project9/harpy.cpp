#include "harpy.h"
#include <iostream>

int harpy::harpycount = 0;

harpy::harpy(int hp, int atk, int xpos, int ypos, char a) {
    harpycount++;
    health = hp;
    attack = atk;
    coordinates.Placex(xpos);
    coordinates.Placey(ypos);
    icon = a;
}

void harpy::Damage(entity* victim) {
    victim->sethealth(victim->gethealth() - getattack());
}

void harpy::move() {
    int num = rand() % 4;
    switch (num) {
    case 0: sety(gety() - 1); break;
    case 1: setx(getx() - 1); break;
    case 2: setx(getx() + 1); break;
    case 3: sety(gety() + 1); break;
    default: break;
    }
}

harpy::~harpy() {
    harpycount--;
}

int harpy::getHarpyCount() {
    return harpycount;
}

int harpy::getattack() {
    return attack;
}

void harpy::movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist) {
    if (entitylist[0] == nullptr) {
        return;
    }
    int dx = std::abs(getx() - entitylist[0]->getx());
    int dy = std::abs(gety() - entitylist[0]->gety());

    if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1)) {
        Damage(entitylist[0]);
        if (entitylist[0]->gethealth() <= 0) {
            delete entitylist[0];
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
                        gety() == entitylist[u]->gety()) {
                        validMove = false;
                    }
                }
            }
            for (int u = 0; u < 3; u++) {
                if (gameobjectlist[u] != nullptr) {
                    if (getx() == gameobjectlist[u]->getx() &&
                        gety() == gameobjectlist[u]->gety()) {
                        validMove = false;
                    }
                }
            }
                for (int u = 0; u < 99; u++) {
                    if (walllist[u] != nullptr) {
                        if (getx() == walllist[u]->getx() &&
                            gety() == walllist[u]->gety()) {
                            validMove = false;
                        }
                    }
                }
            attempts++;
        }
    }
}
