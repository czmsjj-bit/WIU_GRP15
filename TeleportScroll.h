#pragma once
#include "ScrollList.h"
#include <string>

class entity;
class gameobject;
class wall;

// Teleports the user 5 tiles in a direction chosen at the moment of
// activation. Same "step one tile at a time, stop at the first thing in the
// way" shape as DashScroll -- just parameterized by direction instead of
// always going down.
class TeleportScroll : public ScrollList
{
public:
    TeleportScroll(std::string name, std::string description, int value);

    bool Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
};
