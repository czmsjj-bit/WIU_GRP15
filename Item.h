#pragma once
#include <string>
class Item
{
private:
    std::string name;
    std::string description;
    int value;
    char symbolItem;
public:
    Item();
    Item(char symbolItem, std::string name, std::string description, int value);
    ~Item();

    void SetName(std::string name);
    void SetDescription(std::string description);
    void SetValue(int value);
    void SetSymbol(char symbolItem);

    std::string GetName();
    std::string GetDescription();
    int GetValue();
    char GetSymbol();
};

