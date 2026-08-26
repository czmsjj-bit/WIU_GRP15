#include "maphandler.h"

maphandler::maphandler()
{
	currentmap = 0;
	maplist = new map * [mapcount];

	//place ment range 1-15 gameobjects

	//walls follow array 0-16
	//90201-ny

	
//jayden.com 

//first number is amount 

//next number is location for y

//next number is location for x 

//ny is down 

//yn is up
	

	maplist[0] = new map(910, 1015, 1515, 0, 0, 0, "0", "0", "0", "0", "0", "0", "0", "0");

	maplist[1] = new map(708,904, 1509, 2, 2, 0, "50107|ny", "71001-yn", "90113|ny", "91406-yn", "0", "0", "0", "0");

	maplist[2] = new map(501,802, 1415, 2, 2, 0, "90201-yn", "90810|ny", "71101-yn", "0", "0", "0", "0", "0");

	maplist[3] = new map(910,1404, 1305, 2, 2, 0, "50106|ny", "90702-yn", "91405-yn", "40809|ny", "0", "0", "0", "0");

	maplist[4] = new map(307,708, 1511, 2, 2, 0, "40405|ny", "40411|ny", "31004-yn", "31004|ny", "21404-yn", "31012-yn", "31113|ny", "0");

	maplist[5] = new map(1203,1004, 1508, 2, 2, 0, "60609|ny", "11207|ny", "11211-yn", "31309|ny", "50415-yn", "51015-yn", "0", "0");

	maplist[6] = new map(602,1010, 1570, 2, 2, 0, "90206|ny", "90210|ny", "31106|ny", "71107-yn", "0", "0", "0", "0");

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