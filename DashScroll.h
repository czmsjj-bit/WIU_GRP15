#pragma once
#include "ScrollList.h"
#include <string>

class entity;
class gameobject;
class wall;

// A scroll that, when activated, dashes the user down 3 tiles (stopping early
// if something blocks the way). This is the whole reason the polymorphic
// Item::Use() hook exists: to add another scroll effect, write a class like
// this one and point Encounter's factory at it -- hero.cpp never changes.
class DashScroll : public ScrollList
{
public:
    DashScroll(std::string name, std::string description, int value);

    bool Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
};
