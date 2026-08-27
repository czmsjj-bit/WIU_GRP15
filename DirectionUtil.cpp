#include "DirectionUtil.h"
#include <conio.h>
#include <iostream>

bool ReadDirectionInput(int& dx, int& dy)
{
    std::cout << "Choose a direction (WASD): ";
    char input = _getch();
    std::cout << std::endl;

    switch (input)
    {
    case 'w': case 'W': dx = 0;  dy = -1; return true;
    case 's': case 'S': dx = 0;  dy = 1;  return true;
    case 'a': case 'A': dx = -1; dy = 0;  return true;
    case 'd': case 'D': dx = 1;  dy = 0;  return true;
    default:
        std::cout << "That's not a direction.\n";
        return false;
    }
}