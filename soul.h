#pragma once
#include "gameobject.h"
class soul : public gameobject
{
public:
	//creates the class and the icon 

	soul(int x, int y, char icon);

	~soul(); // called when class is destroyed 

	// soulcount is static (one shared count across every soul), so this
	// stays correct across room transitions even though a new hero object
	// gets created for every room -- nothing about picking up souls needs
	// to depend on which hero instance is currently alive.
	static int GetSoulCount();

	// Spends one soul if at least one is available. Returns true if a soul
	// was actually spent, false if there were none to spend (caller should
	// refuse whatever the soul was going to pay for in that case).
	static bool SpendSoul();
	static int UsedSoulCount();
	int GetUsedSC();
	static int Usoulcount;

private:
	static int soulcount;

};