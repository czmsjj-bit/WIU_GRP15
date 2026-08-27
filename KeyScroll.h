#pragma once
#include "ScrollList.h"
#include <string>

class entity;
class gameobject;
class wall;

// Instantly unlocks the first locked door it finds ('U' -> 'N', the same
// transition the button/boulder puzzle normally causes), letting the player
// skip that puzzle entirely.
class KeyScroll : public ScrollList
{
public:
    KeyScroll(std::string name, std::string description, int value);

    bool Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
};
