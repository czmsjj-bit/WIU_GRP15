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
    grabstatus = 1; //not colliding
}



void boulder::setgrabstatus(bool a)
{
    grabstatus = a;
}




bool boulder::getgrabstatus()
{
    return grabstatus;
}

//push boulder set x
//also checks if x is invalid
bool boulder::validmovecheck(char input, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    //save the previous location
    int prevx = coordinates.Returnx();
    int prevy = coordinates.Returny();

    //then moves it based off the player wasd
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
    case 's':
        sety(gety() + 1);
        break;
    default:
        std::cout << "invalid input";
        return true; // nothing moved, nothing to check
    }

    //runs thru the item list
    for (int u = 0; u < 4; u++) {
     
        if (entitylist[u] != nullptr) {
            if (getx() == entitylist[u]->getx() &&
                gety() == entitylist[u]->gety())
            {
                setx(prevx);
                sety(prevy);
                return grabstatus = 0;
            }
        }
    }

    //remeber its called a destructor
    for (int u = 0; u < 10; u++) {
        if (gameobjectlist[u] != nullptr || gameobjectlist[u] == this) {

            if (getx() == gameobjectlist[u]->getx() &&
                gety() == gameobjectlist[u]->gety())
            {
                //uh if you set your icon for your wall to be T it becomes a wall now
                if (gameobjectlist[u]->geticon() == '_') {
                    setx(prevx);
                    sety(prevy);
                    return grabstatus = 0;

                }

                //i am a boulder pushing
             
            }
        }
    }

    //check wall collisions too, since walllist is now passed in
    for (int u = 0; u < 100; u++) {   // match this to walllistsize
        if (walllist[u] != nullptr) {
            if (getx() == walllist[u]->getx() &&
                gety() == walllist[u]->gety())
            {
                setx(prevx);
                sety(prevy);
                return grabstatus = 0;
            }
        }
    }

    return grabstatus = 1; // moved successfully, no collision
}  
boulder::~boulder()
{
}