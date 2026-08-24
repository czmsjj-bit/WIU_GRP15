#pragma once
#include "gameobject.h"
#include "entity.h"
#include "wall.h"
class boulder : public gameobject
{
private:
    bool grabstatus;


public:
    boulder(int xpos, int ypos, char sym);

    bool getgrabstatus();

    void setgrabstatus(bool a);


    bool validmovecheck(int input, entity** entitylist, gameobject** gameobjectlist, wall** walllist);

    ~boulder();




};