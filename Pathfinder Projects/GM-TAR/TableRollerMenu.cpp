#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <list>
#include "Disease.h"
#include "Encounter.h"
#include "FileReceiver.h"

using namespace std;

Disease disease;
Encounter encounter;
FileReceiver files;

string fileStartup;
char choice;

void DiseaseMenu()
{
	bool active = true;
	string name;

	if (files.GetResult() == Both || files.GetResult() == PlayerOnly)
	{
		vector<string> players = files.PlayerTable();

		for (int i = 0; i < players.size(); i++)
		{
			disease.AddPlayer(players.at(i));
		}
	}

	while (active)
	{
		system("CLS");
		choice = '-';

		cout << "Disease Chart for PCs." << endl
			<< "The current players are:" << endl;
		disease.DisplayPlayers();

		cout << endl << "Currently, " << disease.GetDays() << " Day(s) will be generated with a " << endl
			<< disease.GetPercent() << "% chance for disease each day. What would you like to do?" << endl
			<< "(A)dd Player" << endl
			<< "(R)emove Player" << endl
			<< "Change (D)ay Count" << endl
			<< "Change (P)ercent Chance" << endl
			<< "(G)enerate Disease" << endl
			<< "Return to (M)ain Menu" << endl << endl
			<< "Select Here: ";
		cin >> choice;

		cout << endl << endl;

		// If not uppercase, make it uppercase.
		if (!isupper(choice))
			choice = toupper(choice);

		switch (choice)
		{
		case 'A':	//Add Player
		{
			cout << "Type 'CANCEL' if you chose this option by mistake." << endl
				<< "What is the name of the new Player: ";
			cin >> name;
			if (name != "CANCEL")
			{
				disease.AddPlayer(name);
			}
			cin.get();
			break;
		}
		case 'R':	//Remove Player
		{
			cout << "Type 'CANCEL' if you chose this by mistake." << endl
				<< "Name the Player to be removed: ";
			cin >> name;
			if (name != "CANCEL")
			{
				disease.RemovePlayer(name);
			}
			cin.get();
			cin.ignore();
			break;
		}
		case 'D':	//Set Day Count
		{
			int days;
			cout << "Please provide how many days would you like to simulate: ";
			cin >> days;
			disease.SetDayCount(days);
			break;
		}
		case 'G':	//Generate Disease Chart
		{
			disease.GenerateDisease();
			list<string> results = disease.GetResults();
			while (!results.empty())
			{
				cout << results.front() << endl;
				results.pop_front();
			}
			cin.get(); 
			cin.ignore();
			break;
		}
		case 'M':	//Return to Main Menu
			active = false;
			break;
		case 'P':	//Set Percent Amount
		{
			int percent;
			cout << "Please provide the new percent chance for disease: ";
			cin >> percent;
			disease.SetPercentChance(percent);
			break;
		}
		default:
			cout << "You typed in " << choice << " which is not an option. Please select one of the options" << endl
				<< "that is within the ( )s." << endl << endl;
			cin.get();
			break;
		}
	}
}

void EncounterMenu()
{
	bool active = true;

	if (files.GetResult() == Both || files.GetResult() == MonsterOnly)
	{
		vector<string> monsters = files.MonsterTable();
		
		encounter.AddMonsters(monsters);
	}

	while (active)
	{
		system("CLS");
		choice = '-';

		cout << "Encounter Chart for Wandering Monsters." << endl;
		
		cout << endl << "Currently, " << encounter.GetDays() << " Day(s) will be generated with a " << encounter.GetPercent() << "% chance for" << endl
			<< "an encounter during each time of each day. What would you like to do?" << endl
			<< "Change (D)ay Count" << endl
			<< "Change (P)ercent Chance" << endl
			<< "(G)enerate Encounter" << endl
			<< "Return to (M)ain Menu" << endl
			<< "Select Here: ";
		cin >> choice;

		cout << endl << endl;

		// If not uppercase, make it uppercase.
		if (!isupper(choice))
			choice = toupper(choice);

		switch (choice)
		{
		case 'D':	//Set Day Count
		{
			int days;
			cout << "How many days would you like to simulate: ";
			cin >> days;
			encounter.SetDayCount(days);
			break;
		}
		case 'P':	//Set Percent Amount
		{
			int percent;
			cout << "Please provide the new percent chance for encounters: ";
			cin >> percent;
			encounter.SetPercentChance(percent);
			break;
		}
		case 'G':	//Generate Encounter Chart
		{
			encounter.GenerateEncounter();
			list<string> results = encounter.GetResults();
			if (!results.empty())
			{
				while (!results.empty())
				{
					cout << results.front() << endl;
					results.pop_front();
				}
			}
			else
				cout << "There are no encounters simulated." << endl;
			cin.get();
			cin.ignore();
			break;
		}
		case 'M':	//Return to Main Menu
		{
			active = false;
			break;
		}
		default:
			cout << "You typed in " << choice << " which is not an option. Select one of the options" << endl
				<< "that is within the ( )s." << endl << endl;
			cin.get();
			break;
		}
	}
}

void Quit()
{
	exit(1);
}

int main()
{
	// Change color of text to green.
	system("Color 0A");
	srand(time(0));

	fileStartup = files.InitialStartup();

	while (true)
	{
		cout << "This program is to help for percentile prep for Serpent's Skull. Please select an option:" << endl
			<< "(D)isease Chart" << endl
			<< "(W)andering Monsters" << endl
			<< "(C)lear screen" << endl
			<< "(Q)uit Program." << endl
			<< "Select Here: ";
		cin >> choice;

		cout << endl << endl;

		// If not uppercase, make it uppercase.
		if (!isupper(choice))
			choice = toupper(choice);

		switch (choice)
		{
		case 'D':
			DiseaseMenu();
			break;
		case 'W':
			EncounterMenu();
			break;
		case 'C':
			system("CLS");
			break;
		case 'Q':
			Quit();
			break;
		default:
			cout << "You typed in " << choice << " which is not an option. Please select one of the options" << endl
				<< "that is within the ( )s." << endl << endl;
			cin.ignore();
			break;
		}
	}
}