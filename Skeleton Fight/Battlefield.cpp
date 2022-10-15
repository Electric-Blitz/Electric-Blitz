#include <iostream>
#include <iomanip>
#include <string>

#include "Skeleton.h"
#include "Player.h"
#include "Battlefield.h"

using namespace std;

int result;

// Constructor for setting up skeleton & player
Battle::Battle(Skel x, Hero y)
{
	badGuy = x;
	goodGuy = y;
}

// Simulate skeleton & player attacking one another
// with the current level affecting damage to make
// later levels go by faster.
int Battle::Fight(int level)
{
	// Clear screen and show displays of both characters.
	cout << "\033[2J\033[1;1H";
	badGuy.Display();
	cout << endl;
	goodGuy.Display();
	cout << endl << endl;

	// Set up variables for calculating damage and remaining HP
	int lvl = level + 5;
	int Skhp = badGuy.getHP();
	int Hehp = goodGuy.getHP();
	int curr;
	int heroDef = goodGuy.getDef();
	int OGDef = goodGuy.getDef();
	int tempDef;
	char action;
	char check;
	int defCount = 0;

	// While both characters still have HP
	while (Skhp > 0 && Hehp > 0)
	{
		// If Player took defensive action and there's turns
		// of defense boost left.
		if (defCount > 0)
		{
			//Increase def and decrement the counter.
			heroDef = heroDef * 1.5;
			defCount--;

			//Give prompt saying there is still defense.
			cout << "Defence increased to " << heroDef << " for " << defCount << " more rounds." << endl << endl;
		}

		//Give list of commands for player to choose and prompt for choice.
		cout << "Commands: (A)ttack" << setw(16) << "(H)eal" << setw(18) << "(D)efend" << setw(21) << "(Q)uit Game" << endl;
		cout << "NOTE: Heal: avoid damage and heal 5 points." << endl;
		cout << "NOTE: Defend: lasts for 2 additional rounds." << endl << endl;
		cout << "Type Command (Letter): ";
		cin >> action;
		cout << endl;

		// If not uppercase, make it uppercase.
		if (!isupper(action))
			action = toupper(action);

		// Make extra line for formatting.
		cout << endl;

		// Which action did the user decide?
		switch (action)
		{
			//If they attacked:
			case 'A':
			{
				// State player attacking.
				curr = Skhp;
				cout << goodGuy.getName() << " attacks! You deal ";

				// Record damage to Skeleton
				Skhp = Attack(Skhp, goodGuy.getAtk(), badGuy.getDef(), lvl);
				curr -= Skhp;

				// State damage dealt
				cout << curr << " points of damage!" << endl;

				// If Skeleton HP is 0 or less show victory
				// screen and go to the end
				if (Skhp <= 0)
				{
					Victory(true);
					goto end;
				}

				// Save player's HP and state skeleton attacking
				curr = Hehp;
				cout << badGuy.getName() << " attacks! You take ";

				// Record damage to hero
				Hehp = Attack(Hehp, badGuy.getAtk(), goodGuy.getDef(), lvl);
				curr -= Hehp;

				cout << curr << " points of damage!" << endl;

				// If player's health is 0 or less, show lose
				// screen
				if (Hehp <= 0)
				{
					Victory(false);
					goto end;
				}

				cout << endl << "Press enter to continue...";
				cin.get();
				cin.ignore();
				break;
			}

			// If player healed their character
			case 'H':
			{
				// Show text stating player is healing
				cout << badGuy.getName() << " attacks! But you retreat and treat your wounds." << endl;

				// Increase HP if not already at max
				Hehp = HHeal(Hehp, goodGuy.getMax());

				cout << "Press enter to continue...";
				cin.get();
				cin.ignore();
				break;
			}

			// If player defended
			case 'D':
			{
				// Set the defense counter to 2 & change def before skeleton attacks.
				defCount = 2;
				tempDef = heroDef * 2;
				cout << "You prepare yourself, taking a defensive stance. (Defence is increased)" << endl;

				// Record Player HP & show skeleton attacking
				curr = Hehp;
				cout << badGuy.getName() << " attacks! You take ";

				// Change player HP by damage taken
				Hehp = Attack(Hehp, badGuy.getAtk(), tempDef, lvl);
				curr -= Hehp;
				cout << curr << " points of damage!" << endl;

				// If player HP falls at or below 0, show
				// lose screen.
				if (Hehp <= 0)
				{
					Victory(false);
					goto end;
				}

				cout << endl << "Press enter to continue...";
				cin.get();
				cin.ignore();
				break;
			}

			// If player selects quit
			case 'Q':
			{
				// Ask if the player is sure they would like to quit.
				cout << "Are you sure you would like to quit? (Y)es or (N)o?" << endl <<
					"Type command (Letter): ";
				cin >> check;

				// If not uppercase, make it uppercase.
				if (!isupper(check))
					check = toupper(check);

				// If yes, quit the game.
				if (check == 'Y')
					return 0;

				break;
			}
		}

		// Reset defense at the end of the round to base defense.
		heroDef = OGDef;

		// Apply HP changes to skeleton and player
		TurnEnd(Skhp, Hehp);
		end : 0;
	}

	return result;
}

// Calculate damage dealt to the target by the attacker
int Battle::Attack(int hp, int atk, int def, int lvl)
{
	return hp -= (((((2*lvl)/7)+1) * 60 * atk / def) / 50) + 1;
}

// Calculate new HP total to the player. If the player
// reaches Max HP, return the Max HP total instead.
int Battle::HHeal(int hp, int max)
{
	cout << "You heal ";

	if (hp + 5 <= max)
	{
		cout << "5 HP." << endl;
		return hp + 5;
	}
	else
	{
		cout << "back to full HP!" << endl;
		return max;
	}
}

// Display an end result screen that is either a victory screen or
// a defeat screen depending on the boolean passed.
void Battle::Victory(bool who)
{
	if (who == true)
	{
		cout << goodGuy.getName() << " wins! WOOOOO!" << endl << endl;
		result = 1;
	}
	else
	{
		cout << badGuy.getName() << " wins. YOU. LOSE." << endl << endl;
		result = 2;
	}

	cout << "Press enter to continue.";
	cin.get();
	cin.ignore();
}

// At the end of a turn, apply the HP to the skeleton & player
// clear the screen, and redisplay the updated stats of the
// characters.
void Battle::TurnEnd(int Sk, int He)
{
	badGuy.setHP(Sk);
	goodGuy.setHP(He);

	cout << "\033[2J\033[1;1H";

	badGuy.Display();
	cout << endl;
	goodGuy.Display();
	cout << endl << endl;
}