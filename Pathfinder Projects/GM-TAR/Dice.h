#ifndef _DICE_H_
#define _DICE_H_
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <list>

class Dice
{
private:
	string diceToRoll;
	int formatSplit;
	int result = 0;
	bool formatCheck;
	bool FormatChecker();
	int DiceRoller(int);

public:
	int RollDice(string);
};

#endif