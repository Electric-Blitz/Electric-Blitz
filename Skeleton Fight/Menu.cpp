#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Skeleton.h"
#include "Player.h"
#include "Battlefield.h"
#include "GameSet.h"

using namespace std;

void main()
{
	// Apply the current time to random so it'll be different for each game.
	srand(time(0));

	// Set up a game and a char variable to help the player navigate through a menu. 
	char action = '-';
	Game play;

	// Change color of text to green.
	system("Color 0A");

	// Keep looping. The exit is within the while loop.
	// After the option is made, it resets the char variable
	// to '-' so that it won't loop on its own.
	while (true)
	{
		// Clear screen
		cout << "\033[2J\033[1;1H";

		// Intro message & prompt for user input (1 letter)
		cout << "Welcome, would-be adventurer, to Skeleton Fight!" << endl;
		cout << "Commands: (P)lay \t (Q)uit \t (H)elp" << endl;
		cout << "Type Command (Letter): ";
		cin >> action;

		// If not uppercase, make it uppercase.
		if (!isupper(action))
			action = toupper(action);

		// Switch statement for all options.
		switch (action)
		{
			// P plays the game, clearing the menu and taking
			// the player to 'a different screen.'
		case 'P':
			play.game();
			action = '-';
			break;

			// Q quits the game, giving an exit prompt and pausing
			// until the player hits enter or closes the window.
		case 'Q':
			cout << "\033[2J\033[1;1H";
			cout << "Thank you for playing. Goodbye." << endl;
			cin.get();
			cin.ignore();
			exit(1);
			break;

			// Help gives a display explaining the rules and how
			// the game works.
		case 'H':
			play.help();
			action = '-';
			break;

			// If H, Q, or P is not used, the default prompt tells
			// the player to try again and resets the screen.
		default:
			cout << endl << "You entered: " << action << ". " << action << " is not one of the options." << endl;
			cout << "Press enter to continue...";
			cin.get();
			cin.ignore();
			break;
		}
	}
}