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

	void resetcurrentmap();

private:
	static const int mapcount = 8;

	int currentmap;

	map** maplist;
	map** originalmaplist;

	int resetcount[mapcount];
};

