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

    static Inventory& GetInstance();

    // A singleton must not be copyable -- copying it would create a second
    // "the" inventory, defeating the whole point.
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    void AddItem(Item* item);

    void EquipItem(int slot);
    void UnequipItem();

    Item* GetEquippedItem();

    void DisplayInventory();
    void RunInventory();
    void HandleInput();
    void DemolishItem(int slot);

    //New
    void UseEquippedItem();
};


