#include "Item.h"

Item::Item()
{
	symbolItem = ' ';
	name = "";
	description = "";
	value = 0;
}

Item::Item(char symbolItemN, std::string nameN, std::string descriptionN, int valueN)
{
	symbolItem = symbolItemN;
	name = nameN;
	description = descriptionN;
	value = valueN;
}

Item::~Item()
{
}

void Item::SetSymbol(char symbolItemN)
{
	symbolItem = symbolItemN;
}


void Item::SetName(std::string newName)
{
	name = newName;
}

void Item::SetDescription(std::string newDescription)
{
	description = newDescription;
}

void Item::SetValue(int newValue)
{
	value = newValue;
}

std::string Item::GetName()
{
	return name;
}

std::string Item::GetDescription()
{
	return description;
}

int Item::GetValue()
{
	return value;
}

char Item::GetSymbol()
{
	return symbolItem;
}

bool Item::Use(entity* user, entity** entitylist, gameobject** gameobjectlist, wall** walllist)
{
	// Base items don't do anything when activated. Subclasses that represent
	// a usable effect (e.g. DashScroll) override this instead.
	return false;
}
