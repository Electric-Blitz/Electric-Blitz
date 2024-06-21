#ifndef _DICE_H_
#define _DICE_H_
#pragma once

#include <string>

class Dice
{
private:
	std::string input;
	int formatSplit;
	int result;
	bool formatCheck;
	bool FormatChecker();
	void DiceRoller(int);

public:
	void RollDice();
	void RollD20();
};

#endif