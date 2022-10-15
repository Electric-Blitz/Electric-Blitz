#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include "Skeleton.h"
#include "Player.h"
#include "Battlefield.h"
#include "GameSet.h"

using namespace std;

// Set up a Skeleton and Player object
Skel skelly;
Hero player;

void Game::game()
{
	// Set up variables needed to navigate the character creator.
	string name;
	char job;
	char again;
	int result;
	bool check = false;

	// Track how many levels into the game the player is.
	int level = 0;

	// While the flag is unchecked...
	while (check == false)
	{
		// Prompt for name
		cout << "\033[2J\033[1;1H";
		cout << "Ah! A new adventurer I see. Tell me, what is your name? " << endl;
		cout << "Please enter your name: ";
		cin >> name;

		// Confirm name
		cout << endl << "You put in " << name << ". Is this correct? (Y)es or (N)o?" << endl <<
			"Type command (letter): ";
		cin >> again;

		// If not uppercase, make it uppercase
		if (!isupper(again))
			again = toupper(again);

		// If Yes, check off flag.
		if (again == 'Y')
			check = true;
	}

	// Reset the flag
	check = false;

	// Set name for player
	player.setName(name);

	// While the flag is unchecked...
	while (check == false)
	{
		// Prompt for, and explain, Job
		cout << "\033[2J\033[1;1H";
		cout << "Now, please choose what type of hero " << name << " is. You have three options:" << endl << endl;
		cout << "The first is the Attacker. They deal a lot of damage, have alright HP, but bad defence." << endl;
		cout << "Next is the Defender. They have great defence, have okay attack, but bad HP." << endl;
		cout << "Finally, there's the Tank. They have amazing HP, decent defence, but terrible attack power." << endl << endl;

		cout << "Which job do you want: (A)ttacker\t(D)efender\t(T)ank?" << endl <<
			"Type command (letter): ";
		cin >> job;

		// If not uppercase, make it uppercase
		if (!isupper(job))
			job = toupper(job);

		// Spacing
		cout << endl;

		// If A, D, or T is used...
		if (job == 'A')
		{
			// Prompt for confirmation.
			cout << "You have selected Attacker! Is this correct? (Y)es or (N)o?" << endl <<
				"Type command (letter): ";
			cin >> again;

			// Make char uppercase if it isn't
			if (!isupper(again))
				again = toupper(again);

			// If Yes, check the flag.
			if (again == 'Y')
				check = true;
		}
		else if (job == 'D')
		{
			// Prompt for confirmation.
			cout << "You have selected Defender! Is this correct? (Y)es or (N)o?" << endl <<
				"Type command (letter): ";
			cin >> again;

			// Make char uppercase if it isn't
			if (!isupper(again))
				again = toupper(again);

			// If Yes, check the flag.
			if (again == 'Y')
				check = true;
		}

		else if (job == 'T')
		{
			// Prompt for confirmation.
			cout << "You have selected Tank! Is this correct? (Y)es or (N)o?" << endl <<
				"Type command (letter): ";
			cin >> again;

			// Make char uppercase if it isn't
			if (!isupper(again))
				again = toupper(again);

			// If Yes, check the flag.
			if (again == 'Y')
				check = true;
		}
		else
			check = false;	// If user's answer isn't A, D, or T, keep flag unchecked.
	}

	// Clear screen
	cout << "\033[2J\033[1;1H";

	// Set the chosen job
	player.Job(job);

	// Begin game text & prompt to continue.
	cout << "Very Well. " << name << " the " << player.getJob() << "! You are now ready to begin the SKELETON FIGHT!" << endl;
	cout << "Press enter to continue...";
	cin.get();
	cin.ignore();

	// Play again Prompt
	while (again == 'Y')
	{
		win:
			Battle first(skelly, player);
			result = first.Fight(level);

			if (result == 1)
			{
				level++;
				levelUp(level);
				goto win;
			}
			else if (result == 2)
			{
				level = 0;
				player.Job(job);
				skelly.reset();

			retry:
				cout << "\033[2J\033[1;1H";
				cout << "Would you like to play again? (Y)es or (N)o?" << endl;
				cout << "Type Command: ";
				cin >> again;

				if (!isupper(again))
					again = toupper(again);

				if (again != 'Y' && again != 'N')
				{
					cout << "\033[2J\033[1;1H";
					cout << "Type either 'Y' or 'N'" << endl << endl;
					goto retry;
				}
			}
			else if (result == 0)
				again = 'N';
	}
}

// This function clears the screen and then
// displays the instructions and explanation.
void Game::help()
{
	cout << "\033[2J\033[1;1H";
	cout << "Here's how the game works:" << endl << endl;

	cout << "When you begin, you will give your Hero a name and a 'job'. Your job" << endl <<
		"will determine your starting stats. You will then fight one skeleton" << endl <<
		"after another, trying to beat them all. On each victory, you get points to" << endl <<
		"place into your HP, Attack power, or defence to fight the next skeleton." << endl << endl;

	cout << "However, for every 3 skeletons you beat, the skeletons get points to" << endl <<
		"any stat of their own. This will go on until you lose to a skeleton and" << endl <<
		"your adventure ends." << endl << endl;

	cout << "As you level up, you may notice the damage you deal going up even if" << endl <<
		"you didn't put points into attack. That is because as your level increases" << endl <<
		"the damage for both sides will increase, making the fights more challenging." << endl << endl;

	cout << "Finally, every command you input, except for the name input," << endl <<
		"will only take the first letter of a command. Do not type an entire word." << endl <<
		"Also, don't worry about capitalization. I have you covered on that." << endl << endl;

	cout << "Now be ready! The Skeleton Fight has begun..." << endl << endl;

	// Prompt user to press enter.
	cout << "Press enter to return to the main menu.";
	cin.get();
	cin.ignore();
}

// After winning a fight, the levelUp function is called to increase the player's stats.
void Game::levelUp(int level)
{
	// Variables to navigate the level up function
	char choice;
	bool again = false;

	// While flag is unchecked
	while (again == false)
	{
		// Clear screen and prompt for level.
		cout << "\033[2J\033[1;1H";
		cout << "Level Up!" << endl << endl;
		cout << "Your level is: " << level+1 << ". Please select one ability to increase." << endl <<
			"(H)P\t(A)ttack\t(D)efence" << endl << endl;
		cout << "Type Command (Letter): ";
		cin >> choice;

		// If not uppercase, make it uppercase.
		if (!isupper(choice))
			choice = toupper(choice);

		// If H, A, or D, change stats accordingly.
		if (choice == 'H')
		{
			player.setMaxHP((player.getHP() + 1));
			again = true;
		}
		else if (choice == 'A')
		{
			player.setAtk((player.getAtk() + 3));
			again = true;
		}
		else if (choice == 'D')
		{
			player.setDef((player.getDef() + 3));
			again = true;
		}

		// If the user did not put H, A, or D, prompt them to try again.
		else
		{
			cout << "That is not an option. Press enter to try again.";
			cin.get();
			cin.ignore();
		}
	}

	// After every 3 levels, level up the skeleton Otherwise, prompt to continue.
	if(level % 3 == 0)
		skelly.stronger();
	else
	{
		cout << "Press enter to continue...";
		cin.get();
		cin.ignore();
	}
}