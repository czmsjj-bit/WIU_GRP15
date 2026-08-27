#include "Coordinates.h"



Coordinates::Coordinates() {
    x = 0;
    y = 0;
}

int Coordinates::Returnx()
{
    return x;
}


int Coordinates::Returny() {
    return y;
}

void Coordinates::Placex(int a)
{
    x = a;
}


void Coordinates::Placey(int b) {
    y = b;
}
