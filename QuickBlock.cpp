#include "QuickBlock.h"
#include "DirectionUtil.h"
#include "entity.h"
#include "gameobject.h"
#include "wall.h"

QuickBlock::QuickBlock(std::string name, std::string description, int value)
    : ScrollList(name, description, value)
{
}

//bool QuickBlock::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
//{
//    if (user == nullptr)
//    {
//        return false;
//    }
//
//    int dx = 0, dy = 0;
//    if (!ReadDirectionInput(dx, dy))
//    {
//        return false;
//    }
//
//    int newX = user->getx() + dy;
//    int newY = user->gety() + dx;
//
//    // Stay on the 15x15 board.
//    if (newX == -1 || newX == 15 || newY == -1 || newY == 15)
//    {
//        return false;
//    }
//
//    bool occupied = false;
//
//    // NOTE: same fixed-bound caveat as the other scrolls -- these loop
//    // counts should come from map's real list sizes once that's wired up
//    // (see the boulder.cpp bug discussion), not a guessed number.
//    for (int u = 0; u < 4 && !occupied; u++)
//    {
//        if (entitylist[u] != nullptr &&
//            newX == entitylist[u]->getx() && newY == entitylist[u]->gety())
//        {
//            occupied = true;
//        }
//    }
//
//    for (int u = 0; u < 3 && !occupied; u++)
//    {
//        if (gameobjectlist[u] != nullptr &&
//            newX == gameobjectlist[u]->getx() && newY == gameobjectlist[u]->gety())
//        {
//            occupied = true;
//        }
//    }
//
//    for (int u = 0; u < 10 && !occupied; u++)
//    {
//        if (walllist[u] != nullptr &&
//            newX == walllist[u]->getx() && newY == walllist[u]->gety())
//        {
//            occupied = true;
//        }
//    }
//
//    if (occupied)
//    {
//        return false;
//    }
//
//    // Find a free (nullptr) slot in walllist to hold the new wall.
//    for (int u = 0; u < 10; u++)
//    {
//        if (walllist[u] == nullptr)
//        {
//            walllist[u] = new wall(newX, newY, 'T'); // 'T' matches the existing wall-icon convention
//            return true;
//        }
//    }
//
//    return false; // walllist is full, nowhere to put it
//}

bool QuickBlock::Use(entity* user, entity** entitylist,
    gameobject** gameobjectlist, wall** walllist)
{
    if (user == nullptr)
    {
        return false;
    }

    int dx = 0;
    int dy = 0;

    if (!ReadDirectionInput(dx, dy))
    {
        return false;
    }

    int newX = user->getx() + dx;
    int newY = user->gety() + dy;

    // Stay inside the 15x15 board.
    if (newX < 0 || newX >= 15 ||
        newY < 0 || newY >= 15)
    {
        return false;
    }

    // Check entities.
    for (int u = 0; u < 10; u++)
    {
        if (entitylist[u] != nullptr &&
            entitylist[u]->getx() == newX &&
            entitylist[u]->gety() == newY)
        {
            return false;
        }
    }

    // Check game objects.
    for (int u = 0; u < 10; u++)
    {
        if (gameobjectlist[u] != nullptr &&
            gameobjectlist[u]->getx() == newX &&
            gameobjectlist[u]->gety() == newY)
        {
            return false;
        }
    }

    // Check existing walls.
    for (int u = 0; u < 100; u++)
    {
        if (walllist[u] != nullptr &&
            walllist[u]->getx() == newX &&
            walllist[u]->gety() == newY)
        {
            return false;
        }
    }

    // Find an empty wall slot.
    for (int u = 0; u < 100; u++)
    {
        if (walllist[u] == nullptr)
        {
            walllist[u] = new wall(newY, newX, 'T');
            return true;
        }
    }

    return false;
}