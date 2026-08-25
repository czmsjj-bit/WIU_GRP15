#include "maphandler.h"

maphandler::maphandler()
{
	currentmap = 0;
	maplist = new map * [mapcount];

	// map 0 — the layout you already had working in main.cpp
	maplist[0] = new map(1404, 1305, 2, 2, 0, "0", "0", "510_01", "529_01", "130_01", "140_01", "150_01", "160_01");

	// maps 1–8 — REPLACE these with your real level data
	
	maplist[1] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[2] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[3] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[4] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[5] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[6] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[7] = new map(1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");
	
}

maphandler::~maphandler()
{
	for (int i = 0; i < mapcount; i++) {
		delete maplist[i];
	}
	delete[] maplist;
}

int maphandler::getcurrentmap()
{
	return currentmap;
}

void maphandler::setcurrentmap(int mapnum)
{
	if (mapnum >= 0 && mapnum < mapcount) { // bounds check
		currentmap = mapnum;
	}
}

void maphandler::printcurrentmap()
{
	if (maplist[currentmap] != nullptr) {
		maplist[currentmap]->print();
	}
}

map* maphandler::getcurrentmapptr()
{
	return maplist[currentmap];
}