#pragma once
#include "Item.h"
class Inventory
{
private:
    static const int MAX_SLOTS = 5;
    Item* items[MAX_SLOTS];
    Item* equippedItem;

public:
    Inventory();
    ~Inventory();

    void AddItem(Item* item);

    void EquipItem(int slot);
    void UnequipItem();

    Item* GetEquippedItem();

    void DisplayInventory();
    void RunInventory();
    void HandleInput();
    void DemolishItem(int slot);
};


