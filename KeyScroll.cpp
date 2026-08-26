#include "KeyScroll.h"
#include "gameobject.h"

KeyScroll::KeyScroll(std::string name, std::string description, int value)
    : ScrollList(name, description, value)
{
}

bool KeyScroll::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    // NOTE: same fixed-bound caveat as the other scrolls -- this should
    // read from map's real gameobjectlist size once that's wired up.
    for (int u = 0; u < 10; u++)
    {
        if (gameobjectlist[u] != nullptr && gameobjectlist[u]->geticon() == 'U')
        {
            gameobjectlist[u]->seticon('N'); // locked -> unlocked
            return true;
        }
    }

    return false; // no locked door found, nothing happens
}