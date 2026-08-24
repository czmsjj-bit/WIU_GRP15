#pragma once


#include <iostream>
#include "Coordinates.h"

class gameobject
{
protected:
    char icon;
    gameobject** gameobjectlist;
    Coordinates coordinates;
public:



    char geticon();

    Coordinates getxy();

    int getx();

    int gety();

    void setxy(int y, int x);

    void setx(int x);

    void sety(int y);
    void seticon(char a);

    virtual ~gameobject() {}
};

