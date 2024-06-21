#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <list>
#include "Colors.h"
#include "Dice.h"

using namespace std;

char inputCommand = '@';
Colors color;
Dice roller;

void Quit()
{
	cout << "Alright, we're done here. Bye Zeke." << endl;
	exit(1);
}

void main()
{
	srand(time(0));
	bool appActive = true;

	while (appActive)
	{
		system("CLS");

		cout << "Here's the current text color, demonstrated here." << endl << endl;
		cout << "Here are your command options:" << endl;
		cout << "(Q)uit Program ||| (C)hange Color ||| (R)oll Dice ||| (D)20" << endl;
		cout << "Type in Input Command: ";

		cin >> inputCommand;
		if (islower(inputCommand))
		{
			inputCommand = toupper(inputCommand);
		}

		cout << endl;

		switch (inputCommand)
		{
		case 'Q':
			Quit();
			break;
		case 'C':
			color.ColorChange();
			cout << "Task Complete.";
			break;
		case 'R':
			roller.RollDice();
			cout << "Task Complete.";
			break;
		case 'D':
			roller.RollD20();
			cout << "Task Complete.";
			break;
		default:
			cout << "No valid task was given. Ignoring input.";
			break;
		}

		cin.get();
		cin.ignore();
	}
}