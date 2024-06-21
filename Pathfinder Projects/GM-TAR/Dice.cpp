#include <string>
#include "Dice.h"

using namespace std;

bool Dice::FormatChecker()
{
	if (diceToRoll.find('D') != -1 && isupper(diceToRoll.at(diceToRoll.find('D'))))
	{
		diceToRoll.at(diceToRoll.find('D')) = tolower(diceToRoll.at(diceToRoll.find('D')));
	}

	formatCheck = true;
	formatSplit = diceToRoll.find('d');

	formatSplit == -1 ? formatCheck = false : formatCheck = true;

	formatCheck = isdigit(diceToRoll.at(0)) && isdigit(diceToRoll.at(diceToRoll.size() - 1)) && formatCheck != false;

	return formatCheck;
}

int Dice::DiceRoller(int size = 20)
{
	return (rand() % size + 1);
}

int Dice::RollDice(string input)
{
	diceToRoll = input;
	int diceSize = 0;
	list<int> diceTotal;
	
	if (FormatChecker() != true)
	{
		cout << "ERROR. Format was incorrect. Given input was: " << diceToRoll << endl;
	}
	else
	{
		diceSize = stoi(diceToRoll.substr(formatSplit + 1));

		for (int i = 0; i < stoi(diceToRoll); i++)
		{
			result += DiceRoller(diceSize);
			
		}
	}

	return result;
}
