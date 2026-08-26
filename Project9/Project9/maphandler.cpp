#include "maphandler.h"

maphandler::maphandler()
{
	currentmap = 0;
	maplist = new map * [mapcount];

	//place ment range 1-15

	maplist[0] = new map(910,1015, 1515, 0, 0, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[1] = new map(708,904, 1509, 2, 2, 0, "510_10", "0", "0", "0", "0", "0", "0", "0");

	maplist[2] = new map(501,802, 1415, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[3] = new map(910,1404, 1305, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[4] = new map(307,708, 1511, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[5] = new map(1203,1004, 1508, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[6] = new map(602,1010, 1570, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[7] = new map(1302 ,1307, 615, 2, 2, 0, "0", "0", "0", "0", "0", "0", "0", "0");
	
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
	if (mapnum >= 0 && mapnum < mapcount) {
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