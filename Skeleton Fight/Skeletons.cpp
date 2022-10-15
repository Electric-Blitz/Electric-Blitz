#include <iostream>
#include <string>
#include <stdlib.h>
//#include <time.h>

#include <chrono>
#include <thread>

#include "Skeleton.h"

using namespace std;
using namespace this_thread;

// Constructor for Skeletons
Skel :: Skel()
{
	hp = 15;
	maxHP = hp;
	def = 10;
	atk = 5;
}

// To display the skeleton's stats.
void Skel::Display()
{
	cout << name << ":" << endl <<
		"HP = " << hp << endl <<
		"Def = " << def << endl <<
		"Atk = " << atk << endl;
}

// Setter for HP
void Skel::setHP(int newHP)
{
	hp = newHP;
}

// Getter for HP
int Skel::getHP()
{
	return hp;
}

// Getter for Def
int Skel::getDef()
{
	return def;
}

// Getter for Atk
int Skel::getAtk()
{
	return atk;
}

// Getter for Name
string Skel::getName()
{
	return name;
}

// Level up system for skeleton
void Skel::stronger()
{
	// Get a random number of 1, 2, or 3.
	int crazy;
	crazy = rand() % 3 + 1;

	// Depending on it either being 1, 2, or 3...
	switch (crazy)
	{
		// Level up HP and prompt player. Pause so they can't skip
		// it by accident.
	case 1:
		hp += 10;
		maxHP = hp;
		cout << "Beware! The skeletons now stand longer...";
		sleep_for(chrono::seconds(2));
		break;

		// Level up Atk and prompt player. Pause so they can't skip
		// it by accident.
	case 2:
		atk += 10;
		cout << "Watch out! The skeletons hit harder...";
		sleep_for(chrono::seconds(2));
		break;

		// Level up Def and prompt player. Pause so they can't skip
		// it by accident.
	case 3:
		def += 10;
		cout << "On guard! The skeletons will be sturdier...";
		sleep_for(chrono::seconds(2));
		break;
	}
	// After time runs out, make an image of a skull appear for 1 second.
	//Then clear the screen.
	cout << R"(
                  ______
               .-"      "-.
              /            \
             |              |
             |,  .-.  .-.  ,|
             | )(__/  \__)( |
             |/     /\     \|
             (_     ^^     _)
              \__|IIIIII|__/
               | \IIIIII/ |
               \          /
                `--------`)" << endl;
	sleep_for(chrono::seconds(1));

	cout << "\033[2J\033[1;1H";
}

// If the game is restarted, rest Skeleton stats to the base.
void Skel::reset()
{
	hp = 15;
	maxHP = hp;
	def = 10;
	atk = 5;
}