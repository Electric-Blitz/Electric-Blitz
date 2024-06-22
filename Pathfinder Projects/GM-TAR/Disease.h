#ifndef _DISEASE_H_
#define _DISEASE_H_
#pragma once

#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

struct Player
{
	string name;
	vector<int> daysSick;
	vector<int> percentAmount;

	Player(string nm)
	{
		name = nm;
	}
};

class Disease
{
private:
	vector<Player> players;
	int days = 1;
	int percentChance = 25;

public:
	int GetDays();
	int GetPercentChance();
	void AddPlayer(string);
	void RemovePlayer(string);
	void DisplayPlayers();
	void SetDayCount(int);
	void SetPercentChance(int);
	void GenerateDisease();
	list<string> GetResults();
	void ResetTable();
};

#endif