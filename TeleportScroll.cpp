#include "TeleportScroll.h"
#include "DirectionUtil.h"
#include "entity.h"
#include "gameobject.h"

TeleportScroll::TeleportScroll(std::string name, std::string description, int value)
    : ScrollList(name, description, value)
{
}

bool TeleportScroll::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    if (user == nullptr)
    {
        return false;
    }

    int dx = 0, dy = 0;
    if (!ReadDirectionInput(dx, dy))
    {
        return false; // no direction picked, nothing happened
    }

    bool moved = false;

    // NOTE: same caveat as DashScroll -- these loop bounds (4 / 3) match
    // what hero.cpp/DashScroll currently assume, not a real tracked size.
    // Once map exposes real list sizes (see the boulder.cpp bug discussion),
    // this should read from there instead of a fixed number.
    for (int i = 0; i < 5; i++)
    {
        int newX = user->getx() + dx;
        int newY = user->gety() + dy;
        bool blocked = false;

        for (int u = 0; u < 4 && !blocked; u++)
        {
            if (entitylist[u] != nullptr && entitylist[u] != user &&
                newX == entitylist[u]->getx() && newY == entitylist[u]->gety())
            {
                blocked = true;
            }
        }

        if (!blocked)
        {
            for (int u = 0; u < 3; u++)
            {
                if (gameobjectlist[u] != nullptr &&
                    newX == gameobjectlist[u]->getx() && newY == gameobjectlist[u]->gety())
                {
                    blocked = true;
                    break;
                }
            }
        }

        if (blocked)
        {
            break;
        }

        user->setx(newX);
        user->sety(newY);
        moved = true;
    }

    return moved;
}