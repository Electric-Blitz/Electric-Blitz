#include "Dice.h"

bool Dice::FormatChecker(string input)
{
	if (input.find('D') != -1 && isupper(input.at(input.find('D'))))
	{
		input.at(input.find('D')) = tolower(input.at(input.find('D')));
	}

	formatSplit = input.find('d');

	if (formatSplit == -1) return false;

	bool formatCheck = isdigit(input.at(0)) && isdigit(input.at(input.size() - 1));

	return formatCheck;
}

int Dice::DiceRoller(int size = 20)
{
	return (rand() % size + 1);
}

int Dice::RollDice(string input)
{
	if (input == "1d2")
	{
		return DiceRoller(2);
	}
	else if (input == "1d3")
	{
		return DiceRoller(3);
	}
	else if (input == "1d4")
	{
		return DiceRoller(4);
	}
	else if (input == "1d6")
	{
		return DiceRoller(6);
	}
	else if (input == "1d8")
	{
		return DiceRoller(8);
	}
	else if (input == "1d10")
	{
		return DiceRoller(10);
	}

	if (!FormatChecker(input))
	{
		return stoi(input);
	}
	else
	{
		int total = 0;
		int diceSize = stoi(input.substr(formatSplit + 1));

		for (int i = 0; i < stoi(input); i++)
		{
			total += DiceRoller(diceSize);
		}

		return total;
	}
}
