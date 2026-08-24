#pragma once
#include "Item.h"
#include <string>
class ScrollList : public Item
{
public:
    ScrollList();
    ScrollList(std::string nameOfScroll, std::string description, int value);
    ~ScrollList();
};