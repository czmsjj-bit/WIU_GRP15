#include "DashScroll.h"
#include "entity.h"
#include "gameobject.h"

DashScroll::DashScroll(std::string name, std::string description, int value)
    : ScrollList(name, description, value)
{
}

bool DashScroll::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    if (user == nullptr)
    {
        return false;
    }

    int oldY = user->gety();
    bool blocked = false;

    // Try moving down 3 spaces, one at a time, stopping if something's in the way.
    for (int i = 0; i < 3; i++)
    {
        int newY = user->gety() + 1;

        // Check entities
        for (int u = 0; u < 4 && !blocked; u++)
        {
            if (entitylist[u] != nullptr && entitylist[u] != user &&
                user->getx() == entitylist[u]->getx() &&
                newY == entitylist[u]->gety())
            {
                blocked = true;
            }
        }

        // Check game objects
        if (!blocked)
        {
            for (int u = 0; u < 3; u++)
            {
                if (gameobjectlist[u] != nullptr &&
                    user->getx() == gameobjectlist[u]->getx() &&
                    newY == gameobjectlist[u]->gety())
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

        user->sety(newY);
    }

    return user->gety() != oldY;
}