#include "maphandler.h"

maphandler::maphandler()
{
	currentmap = 0;

	maplist = new map * [mapcount];
	originalmaplist = new map * [mapcount];

	for (int i = 0; i < mapcount; i++) {
		resetcount[i] = 2;
		maplist[i] = nullptr;
		originalmaplist[i] = nullptr;
	}

	// map 0 — the layout you already had working in main.cpp
	//maplist[0] = new map(1404, 1305, 2, 2, 0, "0", "0", "510_01", "529_01", "130_01", "140_01", "150_01", "160_01");
	//originalmaplist[0] = new map(1404, 1305, 2, 2, 0, "0", "0", "510_01", "529_01", "130_01", "140_01", "150_01", "160_01");

	// maps 1–8 — REPLACE these with your real level data

	maplist[0] = new map(1014, 910, 1414, 0, 0, 508, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[1] = new map(708, 904, 1409, 2, 2, 1202, "50107|ny", "71001-yn", "90113|ny", "91406-yn", "0", "0", "0", "0");

	maplist[2] = new map(500, 802, 1414, 2, 2, 106, "90201-yn", "90810|ny", "71101-yn", "0", "0", "0", "0", "0");

	
	maplist[3] = new map(207, 707, 1314, 2, 2, 1113, "50106|ny", "90702-yn", "91405-yn", "40809|ny", "0", "0", "0", "0");

	
	maplist[4] = new map(708, 307, 1411, 2, 2, 707, "40405|ny", "40411|ny", "31004-yn", "31004|ny", "21404-yn", "31012-yn", "31113|ny", "0");


	maplist[5] = new map(1004, 1203, 1408, 2, 2, 1001, "60609|ny", "11207|ny", "11211-yn", "31309|ny", "50401-yn", "51001-yn", "0", "0");


	maplist[6] = new map(204, 307, 1407, 2, 2, 202, "90106|ny", "90110|ny", "31006|ny", "71207-yn", "0", "0", "0", "0");

	
	maplist[7] = new map(101, 1012, 514, 2, 2, 402, "30209|ny", "40503-yn", "40510-yn", "50609|ny", "50505-yn", "50510-yn", "71106-yn", "41309|ny");

}
maphandler::~maphandler()
{
	for (int i = 0; i < mapcount; i++) {
		delete maplist[i];
		delete originalmaplist[i];
	}

	delete[] maplist;
	delete[] originalmaplist;
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

void maphandler::resetcurrentmap()
{
	if (resetcount[currentmap] > 0) {

		maplist[currentmap]->reset(originalmaplist[currentmap]);

		resetcount[currentmap]--;

		maplist[currentmap]->print();

	}
}