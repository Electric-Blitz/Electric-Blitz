#ifndef _DICE_H_
#define _DICE_H_
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <list>

using namespace std;

class Dice
{
private:
	int formatSplit;
	bool FormatChecker(string);
	int DiceRoller(int);

public:
	int RollDice(string);
};

#endif