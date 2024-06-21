#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <list>
#include "Dice.h"

using namespace std;

bool Dice::FormatChecker()
{
	if (input.find('D') != -1 && isupper(input.at(input.find('D'))))
	{
		input.at(input.find('D')) = tolower(input.at(input.find('D')));
	}

	formatCheck = true;
	formatSplit = input.find('d');

	formatSplit == -1 ? formatCheck = false : formatCheck = true;

	formatCheck = isdigit(input.at(0)) && isdigit(input.at(input.size() - 1)) && formatCheck != false;

	return formatCheck;
}

void Dice::DiceRoller(int size = 20)
{
	result = rand() % size + 1;
}

void Dice::RollDice()
{
	input = "@@@";
	int diceSize = 0;
	list<int> diceTotal;

	cout << "Rolling Dice" << endl << endl;
	cout << "In the format of Roll20 (##d##), how many dice and what kind do you want to roll?" << endl;
	cout << "Type in Command: ";

	cin >> input;

	if (input == "1d20")
	{
		DiceRoller();
		diceTotal.push_back(result);
	}
	else
	{
		while (FormatChecker() != true)
		{
			cout << "ERROR. Format was incorrect. Please use the following format: ##d##" << endl
				<< "Type in Command: ";

			cin >> input;
		}

		diceSize = stoi(input.substr(formatSplit + 1));

		for (int i = 0; i < stoi(input); i++)
		{
			DiceRoller(diceSize);
			diceTotal.push_back(result);
		}
	}

	cout << "Here is what you rolled (in order):" << endl;

	while (!diceTotal.empty())
	{
		cout << diceTotal.front() << endl;

		diceTotal.pop_front();
	}

	cout << endl;
}

void Dice::RollD20()
{
	DiceRoller();
	cout << "You rolled a " << result << endl;
}
