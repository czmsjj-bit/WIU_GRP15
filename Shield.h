#pragma once
#include "ScrollList.h"
#include <string>

class entity;
class gameobject;
class wall;

// A scroll that, when activated, shields the user from the next attack that
// would otherwise damage them. This class only turns the flag on -- the
// actual blocking happens in entity::TakeDamage(), which is the one place
// every attack (hero's or an enemy's) is supposed to route through.
class Shield : public ScrollList
{
public:
    Shield(std::string name, std::string description, int value);

    bool Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
};

