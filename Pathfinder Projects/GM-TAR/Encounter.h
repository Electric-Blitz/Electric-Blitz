#ifndef _ENCOUNTER_H_
#define _ENCOUNTER_H_
#pragma once

#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum Time {Dawn, Noon, Dusk, Night, Last};

inline std::ostream& operator<<(ostream& out, const Time value) {
	return out << invoke([value] {
#define PROCESS_VAL(p) case(p): return #p;
		switch (value) {
			PROCESS_VAL(Dawn);
			PROCESS_VAL(Noon);
			PROCESS_VAL(Dusk);
			PROCESS_VAL(Night);
		}
#undef PROCESS_VAL
	});
}

struct Monster
{
	int lowerChance, upperChance;
	string name;
	int amount;

	Monster(int lower, int upper, string nm, int amnt)
	{
		upperChance = lower;
		lowerChance = upper;
		name = nm;
		amount = amnt;
	}
};

struct Result
{
	int percentResult = 0;
	int dayOccured = 0;
	int monsterOccured = 0;
	Time whenOccured;

	Result(int percent, int day, int monster, Time when)
	{
		percentResult = percent;
		dayOccured = day;
		monsterOccured = monster;
		whenOccured = when;
	}
};

class Encounter
{
private:
	vector<Result> encounters;
	vector<Monster> monsters;
	int days = 1;
	int percentChance = 15;
	Time time = Dawn;

	string EnumToString(Time time);

public:
	void GenerateEncounter();
	void SetDayCount(int);
	void SetPercentChance(int);
	list<string> GetResults();
};

#endif