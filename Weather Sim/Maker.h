#ifndef _MAKER_H_
#define _MAKER_H_
#pragma once

#include <string>
#include <fstream>

using namespace std;

class Make
{
private:
	enum Seasons {spring, summer, fall, winter};
	enum Climates {cold, temperate, tropical};
	enum WindStr {lightW, moderateW, strongW, severeW, windstorm};
	enum CloudCov {none, lightC, mediumC, overcast};
	enum Levels {light, medium, heavy, torrential};
	enum Conditions {drizzle, lghtFog, medFog, hvyFog, lghtRain, medRain, hvyRain, lghtSnow, medSnow, hvySnow, sleet, thunder};
	enum Severes {blizzard, haboob, hurricane, sandstorm, thunderstorm, tornado, wildfire};
	enum Frequency {drought, rare, intermittent, common, constant};
	Seasons season;
	Climates climate;
	WindStr winds;
	CloudCov clouds;
	Levels intense;
	Severes severe;
	Frequency freq;
	Conditions setter;
	string currSea;
	string currCli;
	string weatherType;
	string condition;
	int day = 1, month = 1;
	int startD = 1, startM = 1;
	int temp = 0;
	int baseTemp[4];
	int durDay = 0;
	int durHour = 0;
	int daysPass = 1;

	bool setSeason(int s);
	bool setClimate(int c);
	bool setDate(int d, int m);
	void determineTemp();
	void nextDay();
	void determinePer();
	void percipTable(int intensity);
	void weatherSetup();
	void outputWeather();

public:
	void setValues(int c, int d, int m);
	void setTime(int t);
	void displayWeather();
};

#endif
