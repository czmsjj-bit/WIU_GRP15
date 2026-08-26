#pragma once
#include "ScrollList.h"
#include <string>

class entity;
class gameobject;
class wall;

class QuickBlock : public ScrollList
{
public:
    QuickBlock(std::string name, std::string description, int value);

    bool Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist) override;
};
