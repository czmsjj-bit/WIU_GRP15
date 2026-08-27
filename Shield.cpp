#include "Shield.h"
#include "entity.h"

Shield::Shield(std::string name, std::string description, int value)
    : ScrollList(name, description, value)
{
}

bool Shield::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
    if (user == nullptr)
    {
        return false;
    }

    if (user->IsShielded())
    {
        // Already shielded -- nothing new happens, so don't consume the scroll.
        return false;
    }

    user->SetShielded(true);
    return true;
}