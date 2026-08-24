#pragma once
#include <iostream>
#include "Inventory.h"
#include "Dialogue.h"

class Menu {
private:
    Inventory inventory;
    Dialogue persephoneDialogue;

public:
    Menu();

    void printTitle();
    void showTitleScreen();
    void showControls();
    void showGameScreen();
    
};

