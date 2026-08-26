#pragma once
//all movement in entity
#include "Coordinates.h"
#include "wall.h"

class gameobject;
class entity
{
protected:
    Coordinates coordinates;
    int range;
    char icon;
    int health;
    entity** entitylist;
    bool shielded = false;

public:

    entity();
    virtual ~entity();

    void sethealth(int Health);

    virtual void movementcheck(entity** entitylist, gameobject** gameobjectlist, wall** walllist) = 0;




    void setattack(int atack);



    int getrange();

    char geticon();

    void seticon(char a);

    Coordinates getxy();

    int getx();

    int gety();

    int gethealth();

    bool IsShielded() const;
    void SetShielded(bool s);
    
        virtual void TakeDamage(int amount);

    void setxy(int y, int x);

    void setx(int x);

    void sety(int y);
};

