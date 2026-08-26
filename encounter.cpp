#include "Encounter.h"
#include "Inventory.h"
#include "ScrollList.h"
#include "DashScroll.h"
#include "Shield.h"
#include "TeleportScroll.h"
#include "QuickBlock.h"

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <array>
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

// Builds any scroll subclass that takes (name, description, value) — which is
// all of them. Passing makeScroll<DashScroll> instead of makeScroll<ScrollList>
// is the entire difference between a plain scroll and one with an effect.
template <typename T>
static Item* makeScroll(const std::string& name, const std::string& description, int value)
{
    return new T(name, description, value);
}

// makeScroll<T> has no captures, so it decays to a plain function pointer --
// no need for std::function's type erasure/possible heap allocation here.
using ScrollFactory = Item * (*)(const std::string&, const std::string&, int);

void Encounter::GenerateEncounter()        // New Shit
{
    clearItems();

    struct ScrollTemplate
    {
        std::string name;
        std::string description;
        int value;
        // Builds the actual Item subclass for this scroll. Every scroll class
        // (ScrollList, DashScroll, ...) has the same (name, description, value)
        // constructor, so makeScroll<T> below covers all of them -- this is
        // the only spot that still needs to know "Dash Scroll" maps to
        // DashScroll. Everything downstream (hero.cpp, Inventory) just calls
        // Use() polymorphically and never checks the type or name.
        ScrollFactory factory;
    };
    std::array<ScrollTemplate, 7> pool = { {
        { "Teleport Scroll", "Teleports 5 tiles with chosen direction", 1, makeScroll<TeleportScroll> },
        { "Key", "Skips a room", 1, makeScroll<ScrollList> },
        { "Dash Scroll",  "Dash 3 tiles down.", 1, makeScroll<DashScroll> },
        {"Quick Block Scroll", "Creation of 3 walls", 1, makeScroll<QuickBlock>},
        { "Scroll of Shield", "Grants a temporary Shield for a attack",    1, makeScroll<Shield> },
        {"Quick Block Scroll", "Creation of 3 walls", 1, makeScroll<QuickBlock>},
        {"Quick Block Scroll", "Creation of 3 walls", 1, makeScroll<QuickBlock>}
    } };

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(pool.begin(), pool.end(), rng);

    for (int i = 0; i < NUM_SCROLL_CHOICES && i < (int)pool.size(); i++)
    {
        encounterItems.push_back(
            pool[i].factory(pool[i].name, pool[i].description, pool[i].value));
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

void Encounter::scrollPick()
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

                Inventory::GetInstance().AddItem(picked);
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
    Inventory::GetInstance().RunInventory();
}
