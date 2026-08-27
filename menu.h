#pragma once
#include <iostream>
#include "Dialogue.h"
#include "maphandler.h"
class maphandler;
class Menu {
private:
    Dialogue persephoneDialogue;
    Dialogue playerDialogue;
    maphandler* mapHandler;

public:
    Menu(maphandler* handler);

    void printTitle();
    void showTitleScreen();
    void showControls();

    void showCredits();

    bool handleGameInput(char input);
};
