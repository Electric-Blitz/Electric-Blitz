#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Player.h"

using namespace std;

// Setter for HP
void Hero::setHP(int newHP)
{
	hp = newHP;
}

// Setter for MAX HP
void Hero::setMaxHP(int newHP)
{
	hp = newHP;
	maxHP = hp;
}

// Setter for Name
void Hero::setName(string n)
{
	name = n;
}

// Setter for Def
void Hero::setDef(int newDef)
{
	def = newDef;
}

// Setter for Atk
void Hero::setAtk(int newAtk)
{
	atk = newAtk;
}

// Display for the player's current stats
void Hero::Display()
{
	cout << name << " the " << type << ":" << endl <<
		"HP = " << hp << endl <<
		"Def = " << def << endl <<
		"Atk = " << atk << endl;
}

// This function sets the base stats depending on which
// 'job' you selected when setting up the game.
void Hero::Job(char x)
{
	char job = x;
	switch (job)
	{
		case 'D':
			hp = 5;
			maxHP = hp;
			def = 20;
			atk = 10;
			type = "Defender";
			break;

		case 'A':
			hp = 10;
			maxHP = hp;
			def = 5;
			atk = 15;
			type = "Attacker";
			break;

		case 'T':
			hp = 15;
			maxHP = hp;
			def = 10;
			atk = 5;
			type = "Tank";
			break;

		default:
			cout << "Something went wrong..." << endl;
			exit(1);
			break;
	}

}

// Getter for HP
int Hero::getHP()
{
	return hp;
}

// Getter for MAX HP
int Hero::getMax()
{
	return maxHP;
}

// Getter for Def
int Hero::getDef()
{
	return def;
}

// Getter for Atk
int Hero::getAtk()
{
	return atk;
}

// Getter for job type
string Hero::getJob()
{
	return type;
}

// Getter for Name
string Hero::getName()
{
	return name;
}