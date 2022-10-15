#ifndef _SKELETON_H_
#define _SKELETON_H_
#pragma once

#include <string>

using namespace std;

class Skel
{
public:
	Skel();
	void Display();
	void setHP(int hp);
	int getHP();
	int getDef();
	int getAtk();
	string getName();
	void stronger();
	void reset();
private:
	int maxHP;
	int hp;
	int def;
	int atk;
	string name = "Skelly";
};

#endif
