#include "ScrollList.h"
#include <iostream>

ScrollList::ScrollList() : Item('$', "", "", 0)
{

}

ScrollList::ScrollList(std::string nameOfScroll, std::string description, int value)
	: Item('S', nameOfScroll, description, value)
{

}

ScrollList::~ScrollList()
{
}
