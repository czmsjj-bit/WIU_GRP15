#include "boulder.h"
#include "entity.h"
#include "gameobject.h"
#include "wall.h"
#include "hero.h"
#include "map.h"
#include <iostream>

boulder::boulder(int xpos, int ypos, char sym)
{
    coordinates.Placex(xpos);
    coordinates.Placey(ypos);
    icon = sym;
    grabstatus = 0; //false hampter
}

void boulder::setgrabstatus(bool a)
{
    if(geticon() == '0'){
        seticon('O');

    
    }
    else if (geticon() == 'O') {
        seticon('0');

    }
}

bool boulder::getgrabstatus()
{
    return grabstatus;
}

//push boulder set x
//also checks if x is invalid
bool boulder::validmovecheck(int input, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    //save the previous location
    int prevx = coordinates.Returnx();
    int prevy = coordinates.Returny();

    //then moves it based off the player wasd
    switch (input) {
    case 'w':
       coordinates.placey(gety() - 1);
        break;
    case 'a':
        setx(getx() - 1);
        break;
    case 'd':
        setx(getx() + 1);
        break;
    case 's':
        sety(gety() + 1);
        break;
    default:
        std::cout << "invalid input";
        return true; // nothing moved, nothing to check
    }

    //runs thru the item list
    for (int u = 0; u < 4; u++) {
        if (u == 0) { // checking for itself
            continue;
        }
        if (entitylist[u] != nullptr) {
            if (getx() == entitylist[u]->getx() &&
                gety() == entitylist[u]->gety())
            {
                setx(prevx);
                sety(prevy);
                return false;
            }
        }
    }

    //remeber its called a destructor
    for (int u = 0; u < 3; u++) {
        if (gameobjectlist[u] != nullptr) {
            if (getx() == gameobjectlist[u]->getx() &&
                gety() == gameobjectlist[u]->gety())
            {
                //uh if you set your icon for your wall to be T it becomes a wall now
                if (gameobjectlist[u]->geticon() == '_') {
                    setx(prevx);
                    sety(prevy);
                    return false;
                }

                //i am a boulder pushing
                if (gameobjectlist[u]->geticon() == 'O' || gameobjectlist[u]->geticon() == '0') {
                    std::cout << "boulder push";
                    setx(prevx);
                    sety(prevy);
                    return false;
                }
            }
        }
    }

    //check wall collisions too, since walllist is now passed in
    for (int u = 0; u < 8; u++) {   // match this to walllistsize
        if (walllist[u] != nullptr) {
            if (getx() == walllist[u]->getx() &&
                gety() == walllist[u]->gety())
            {
                setx(prevx);
                sety(prevy);
                return false;
            }
        }
    }

    return true; // moved successfully, no collision
}   // <-- this closing brace was missing before

boulder::~boulder()
{
}