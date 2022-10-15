#ifndef _PLAYER_H_
#define _PLAYER_H_
#pragma once

#include <string>

using namespace std;

class Hero
{
public:
	void setHP(int hp);
	void setMaxHP(int hp);
	void setName(string x);
	void setDef(int def);
	void setAtk(int atk);
	void Display();
	void Job(char job);
	int getHP();
	int getMax();
	int getDef();
	int getAtk();
	string getJob();
	string getName();
private:
	int maxHP = 0;
	int hp = 0;
	int def = 0;
	int atk = 0;
	string name;
	string type;

};

#endif // !PLAYER_H