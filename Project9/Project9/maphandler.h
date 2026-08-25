// game.h
#pragma once
#include "map.h"

class maphandler
{
public:
	maphandler();
	int getcurrentmap();
	void setcurrentmap(int mapnum);
	~maphandler();
	void printcurrentmap();

	map* getcurrentmapptr();

private:
	int currentmap;

	map** maplist;
	static const int mapcount = 9; 
};

