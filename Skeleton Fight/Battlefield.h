#ifndef _BATTLEFIELD_H_
#define _BATTLEFIELD_H_
#pragma once

#include "Skeleton.h"
#include "Player.h"
#include <string>

using namespace std;

class Battle
{
public:
	Battle(Skel x, Hero y);
	void Victory(bool who);
	int Fight(int lvl);
	int Attack(int hp, int atk, int def, int lvl);
	int HHeal(int hp, int max);
	void TurnEnd(int Sk, int He);
private:
	Skel badGuy;
	Hero goodGuy;
};

#endif // !BATTLEFIELD_H