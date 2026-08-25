#pragma once
#include <string>
#include <vector>
#include "Item.h"

// Forward declared instead of #included to avoid a circular include with
// Inventory.h (Inventory doesn't need to know about Encounter).
class Inventory;
class Encounter
{
private:
    int scrollAmount;

    // The items currently sitting in this encounter, waiting to be picked up.
    std::vector<Item*> encounterItems;

    static const int COLUMN_WIDTH = 38;

    std::string centerText(const std::string& text, int width) const;
    void printDivider(int numColumns) const;
    void printTitle(const std::string& title, int numColumns) const;
    void printRow(const std::vector<std::string>& row) const;

public:
    Encounter();
    ~Encounter();

    void addItem(Item* item);
    void clearItems();
    bool isEmpty() const;

    static const int NUM_SCROLL_CHOICES = 3;
    void GenerateEncounter();
    void encounterDisplay();
    // Lets the player pick a slot (1-9) to move that item into their
    // inventory. Removes the item from the encounter once picked up.
    void scrollPick(Inventory& inventory);
};