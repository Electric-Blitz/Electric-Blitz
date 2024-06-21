#include <stdio.h>
#include "Encounter.h"
#include "FileReceiver.h"
#include "Dice.h"

using namespace std;

void Encounter::AddMonsters(vector<string> entries)
{
	for (int i = 0; i < entries.size(); i++)
	{
		istringstream iss(entries.at(i));
		int tempLow, tempUp;
		string tempName, tempAmnt;

		iss >> tempLow >> tempUp >> tempName >> tempAmnt;

		monsters.push_back(Monster(tempLow, tempUp, tempName, tempAmnt));
	}
}

void Encounter::GenerateEncounter()
{
	int chance = 0;
	int whichMonster = 0;
	Time timeOfDay = Dawn;

	for (int i = 0; i < days; i++)
	{
		//Dawn -> Noon -> Dusk -> Night
		for (int j = Dawn; j != Last; j++)
		{
			chance = rand() % 100 + 1;

			if (chance <= 15)
			{
				whichMonster = rand() % 100 + 1;

				encounters.push_back(Result(chance, i + 1, Monster(), static_cast<Time>(j)));
			}
		}
	}
}

void Encounter::SetDayCount(int daysGiven)
{
	days = daysGiven;
}

void Encounter::SetPercentChance(int percentGiven)
{
	percentChance = percentGiven;
}

list<string> Encounter::GetResults()
{
	list<string> results;
	string statement;

	for (int i = 0; i < encounters.size(); i++)
	{
		statement = "On Day " + to_string(encounters.at(i).dayOccured) + " at "
			+ EnumToString(encounters.at(i).whenOccured) + " there is an encounter at percent "
			+ to_string(encounters.at(i).percentResult) + ". Apply monster from " + 
			encounters.at(i).monsterOccured.name + "%";

		results.push_back(statement);
	}

	return results;
}

string Encounter::EnumToString(Time time)
{
	switch (time) {
		case Dawn: return "Dawn";
		case Noon: return "Noon";
		case Dusk: return "Dusk";
		case Night: return "Night";
		default: return "Unknown";
	}
}