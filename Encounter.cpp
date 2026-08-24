#include "Encounter.h"
#include "Inventory.h"
#include "ScrollList.h" 

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
//Learn
#include <algorithm>
#include <random>           
#include <ctime>
Encounter::Encounter() : scrollAmount(3)
{
}

Encounter::~Encounter()
{
    clearItems();
}

void Encounter::addItem(Item* item)
{
    encounterItems.push_back(item);
}

void Encounter::clearItems()
{
    for (Item* item : encounterItems)
    {
        delete item;
    }
    encounterItems.clear();
}

bool Encounter::isEmpty() const
{
    return encounterItems.empty();
}

void Encounter::GenerateEncounter()        // New Shit
{
    clearItems();

    struct ScrollTemplate { std::string name; std::string description; int value; };

    std::vector<ScrollTemplate> pool = {
        { "Phase Scroll",     "Deals fire damage to a target.",       1 },
        { "Key",      "Skips a room",           1 },
        { "Dash Scroll",  "Restores a portion of health.",        1 },
        { "Shield", "Teleports the user a short distance.", 1 },
        { "Scroll of Shield",   "Grants a temporary damage shield.",    45 }
    };

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(pool.begin(), pool.end(), rng);

    for (int i = 0; i < NUM_SCROLL_CHOICES && i < (int)pool.size(); i++)
    {
        encounterItems.push_back(
            new ScrollList(pool[i].name, pool[i].description, pool[i].value));
    }
}

std::string Encounter::centerText(const std::string& text, int width) const
{
    if ((int)text.length() >= width) {
        return text.substr(0, width);
    }
    int totalPad = width - (int)text.length();
    int leftPad = totalPad / 2;
    int rightPad = totalPad - leftPad;
    return std::string(leftPad, ' ') + text + std::string(rightPad, ' ');
}

void Encounter::printDivider(int numColumns) const
{
    std::cout << "+";
    for (int i = 0; i < numColumns; i++) {
        std::cout << std::string(COLUMN_WIDTH, '-') << "+";
    }
    std::cout << std::endl;
}

void Encounter::printTitle(const std::string& title, int numColumns) const
{
    int fullWidth = (COLUMN_WIDTH + 1) * numColumns - 1;
    std::cout << "+" << std::string(fullWidth, '-') << "+" << std::endl;
    std::cout << "|" << centerText(title, fullWidth) << "|" << std::endl;
}

void Encounter::printRow(const std::vector<std::string>& row) const
{
    std::cout << "|";
    for (const auto& cell : row) {
        std::cout << centerText(cell, COLUMN_WIDTH) << "|";
    }
    std::cout << std::endl;
}

void Encounter::encounterDisplay()
{
    if (encounterItems.empty())
    {
        std::cout << "There is nothing left here.\n";
        return;
    }
    int numColumns = (int)encounterItems.size();

    std::vector<std::string> slots;
    std::vector<std::string> descriptions;

    for (int i = 0; i < numColumns; i++)
    {
        slots.push_back("[" + std::to_string(i + 1) + "] " + encounterItems[i]->GetName());
        descriptions.push_back(encounterItems[i]->GetDescription());
    }

    printTitle("ENCOUNTER", numColumns);
    printDivider(numColumns);
    printRow(slots);
    printRow(descriptions);
    printDivider(numColumns);

    std::cout << "Press 1-" << numColumns << " to pick up an item, [Q] to leave.\n";
}

void Encounter::scrollPick(Inventory& inventory)
{
    if (encounterItems.empty())
    {
        std::cout << "There is nothing to pick up.\n";
        return;
    }

    bool picking = true;

    while (picking)
    {
        system("cls");
        encounterDisplay();

        char input = _getch();

        if (input == 'q' || input == 'Q')
        {
            picking = false;
        }
        else if (input >= '1' && input <= '9')
        {
            int slot = input - '1';

            if (slot >= 0 && slot < (int)encounterItems.size())
            {
                Item* picked = encounterItems[slot];

                inventory.AddItem(picked);
                encounterItems.erase(encounterItems.begin() + slot);

                std::cout << "\nYou picked up: " << picked->GetName() << "\n";
                system("pause");

                // Only one item per encounter — discard the rest.
                clearItems();
                picking = false;
            }
        }
    }

    // Show the inventory so it's clear the item landed there.
    inventory.RunInventory();
}