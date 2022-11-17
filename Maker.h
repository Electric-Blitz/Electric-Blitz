#ifndef _MAKER_H_
#define _MAKER_H_
#pragma once

#include <string>

using namespace std;

class Make
{
private:
	enum Seasons {spring, summer, fall, winter};
	enum Climates {cold, temperate, tropical};
	enum WindStr {lightW, moderateW, strongW, severeW, windstorm};
	enum CloudCov {none, lightC, mediumC, overcast};
	enum Levels {light, medium, heavy, torrential};
	enum Types {drizzle, fog, rain, snow, sleet};
	enum Severes {blizzard, haboob, hurricane, sandstorm, thunderstorm, tornado, wildfire};
	enum Frequency {drought, rare, intermittent, common, constant};
	Seasons season;
	Climates climate;
	WindStr winds;
	CloudCov clouds;
	Levels intense;
	Types type;
	Severes severe;
	Frequency freq;
	string currSea;
	string currCli;
	int day = 1, month = 1;
	int startD = 1, startM = 1;
	int temp = 0;
	int baseTemp[4];
	int durDay = 0;
	int durHour = 0;

	bool setSeason(int s);
	bool setClimate(int c);
	bool setDate(int d, int m);
	void determineTemp();
	void nextDay();

public:
	void setValues(int c, int d, int m);
	void weatherSetup();
	void displayWeather();
};

#endif