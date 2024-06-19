#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <list>
#include "Disease.h"
#include "FileReceiver.h"

using namespace std;

void Disease::AddPlayer(string name)
{
	Player player = Player(name);
	players.push_back(player);
}

void Disease::RemovePlayer(string name)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i).name == name)
		{
			players.erase(players.begin() + i);
			break;
		}
	}
}

void Disease::DisplayPlayers()
{
	if (players.empty())
	{
		cout << "There are currently no Players." << endl << endl;
	}
	else
	{
		for (int i = 0; i < players.size(); i++)
		{
			cout << "Player #" << i + 1 << " is " << players.at(i).name << endl;
		}
	}
}

void Disease::SetDayCount(int daysGiven)
{
	days = daysGiven;
}

void Disease::SetPercentChance(int percentGiven)
{
	percentChance = percentGiven;
}

void Disease::GenerateDisease()
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < days; j++)
		{
			int result = 0;

			result = rand() % 100 + 1;

			if (result < percentChance)
			{
				players.at(i).daysSick.push_back(j + 1);
				players.at(i).percentAmount.push_back(result);
			}
		}
	}
}

list<string> Disease::GetResults()
{
	list<string> results;
	string statement;

	for (int i = 0; i < players.size(); i++)
	{
		if (!players.at(i).daysSick.empty())
		{
			statement = "\n" + players.at(i).name + " may get sick on the following days:";
			results.push_back(statement);

			for (int j = 0; j < players.at(i).daysSick.size(); j++)
			{
				statement = "Day " + to_string(players.at(i).daysSick.at(j)) + " at " + to_string(players.at(i).percentAmount.at(j)) + "%";
				results.push_back(statement);
			}
		}
	}

	return results;
}
