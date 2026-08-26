#include "Inventory.h"
#include <iostream>
#include <conio.h>

Inventory::Inventory()
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        items[i] = nullptr;
    }
    equippedItem = nullptr;
}

Inventory::~Inventory()
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        delete items[i];
    }
}

Inventory& Inventory::GetInstance()
{
    static Inventory instance; // constructed once, on first use; lives for the whole program
    return instance;
}

void Inventory::AddItem(Item* item)
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (items[i] == nullptr)
        {
            items[i] = item;
            return;
        }
    }
    // Inventory full � handle however you like (drop, message, etc.)
    std::cout << "Inventory is full!\n";
}

void Inventory::EquipItem(int slot)
{
    if (slot < 0 || slot >= MAX_SLOTS)
    {
        return;
    }

    if (items[slot] != nullptr)
    {
        equippedItem = items[slot];
    }
}

void Inventory::UnequipItem()
{
    equippedItem = nullptr;
}

Item* Inventory::GetEquippedItem()
{
    return equippedItem;
}
void Inventory::DemolishItem(int slot)
{
    if (slot < 0 || slot >= MAX_SLOTS)
    {
        return;
    }

    if (items[slot] == nullptr)
    {
        return;
    }

    if (items[slot] == equippedItem)
    {
        equippedItem = nullptr;
    }

    delete items[slot];
    items[slot] = nullptr;
}



void Inventory::DisplayInventory()
{
    std::cout << "================================================\n";
    std::cout << "                   INVENTORY\n";
    std::cout << "================================================\n";

    for (int i = 0; i < MAX_SLOTS; i++)
    {
        Item* item = items[i];

        if (item == nullptr)
        {
            std::cout << " [" << (i + 1) << "] Empty\n";
            continue;
        }

        std::cout << " [" << (i + 1) << "] [" << item->GetSymbol() << "] " << item->GetName();

        if (item == equippedItem)
        {
            std::cout << "              <EQUIPPED>";
        }
        std::cout << "\n";

        std::cout << "         " << item->GetDescription() << "\n";
    }

    std::cout << "------------------------------------------------\n";

    if (equippedItem != nullptr)
    {
        std::cout << " Equipped: [" << equippedItem->GetSymbol() << "] " << equippedItem->GetName() << "\n";
    }
    else
    {
        std::cout << " Equipped: None\n";
    }
    std::cout << " [/] Remove Item(Choose 1-5)\n";
    std::cout << " [1-5] Equip    [T] Unequip    [I] Close\n";
    std::cout << "================================================\n";
}

void Inventory::RunInventory()
{
    bool open = true;
    while (open)
    {
        system("cls");
        DisplayInventory();

        char input = _getch();

        if (input == 'i' || input == 'I')
        {
            open = false;
        }
        else if (input == 't' || input == 'T')
        {
            UnequipItem();
        }
        else if (input >= '1' && input <= '5')
        {
            EquipItem(input - '1');
        }
        else if (input == '/')
        {
            std::cout << "Enter item slot to delete: ";

            char slotInput = _getch();

            if (slotInput >= '1' && slotInput <= '5')
            {
                DemolishItem(slotInput - '1');
            }
        }
    }
}

void Inventory::HandleInput()
{
    char input = _getch();

    if (input >= '1' && input <= '5')
    {
        int slot = input - '1';
        EquipItem(slot);
    }
    else if (input == 'u' || input == 'U')
    {
        UnequipItem();
    }
}
void Inventory::UseEquippedItem()
{
    if (equippedItem == nullptr)
    {
        return;
    }

    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (items[i] == equippedItem)
        {
            delete items[i];
            items[i] = nullptr;
            equippedItem = nullptr;
            return;
        }
    }
}


