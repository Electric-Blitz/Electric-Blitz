#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include "Maker.h"

using namespace std;

ofstream output("temp.txt", ofstream::out);

bool Make::setSeason(int s)
{
	bool flag = false;

	switch (s)
	{
	case 1:
		currSea = "Spring";
		season = spring;
		flag = true;
		break;
	case 2:
		currSea = "Summer";
		season = summer;
		flag = true;
		break;
	case 3:
		currSea = "Fall";
		season = fall;
		flag = true;
		break;
	case 4:
		currSea = "Winter";
		season = winter;
		flag = true;
		break;
	default:
		flag = false;
		break;
	}

	return flag;
}

bool Make::setClimate(int c)
{
	bool flag = false;

	switch (c)
	{
	case 1:
		currCli = "Cold";
		climate = cold;
		baseTemp[0] = 30;
		baseTemp[1] = 40;
		baseTemp[2] = 30;
		baseTemp[3] = 30;
		flag = true;
		break;
	case 2:
		currCli = "Temperate";
		climate = temperate;
		baseTemp[0] = 60;
		baseTemp[1] = 80;
		baseTemp[2] = 60;
		baseTemp[3] = 30;
		flag = true;
		break;
	case 3:
		currCli = "Tropical";
		climate = tropical;
		baseTemp[0] = 75;
		baseTemp[1] = 95;
		baseTemp[2] = 75;
		baseTemp[3] = 50;
		flag = true;
		break;
	default:
		break;
	}

	return flag;
}

bool Make::setDate(int d, int m)
{
	bool flag = true;

	if (d >= 1 && d <= 30)
	{
		day = d;
		startD = day;

		if (m >= 1 && m <= 12)
		{
			month = m;
			startM = month;
		}

		switch (month)
		{
		case 12:
			if (day < 7)
				goto FALL;
		case 2:
				if (month == 2 && day >= 16)
					goto SPRING;
		case 1:
			setSeason(4);
			break;
		SPRING:
		case 3:
		case 4:
		case 5:
			setSeason(1);
			break;
		case 6:
			if (day < 26)
				goto SPRING;
		case 7:
		case 8:
			if (month == 8 && day >= 23)
				goto FALL;
			else
				setSeason(2);
			break;
		FALL:
		case 9:
		case 10:
		case 11:
			setSeason(3);
			break;
		default:
			cout << "Beyond scope of the 12 months, somehow." << endl;
			flag = false;
			break;
		}
	}
	else
		flag = false;

	return flag;
}

void Make::setValues(int c, int d, int m)
{
	srand(time(0));

	while (!setDate(d, m))
	{
		cout << "\033[2J\033[1;1H";
		cout << "Your date was not accepted. Try again." << endl << endl;

		cout << "Provide the day number within 1-30: ";
		cin >> d;
		cout << endl;

		cout << "Provide the month number within 1-12: ";
		cin >> m;
	}

	while (!setClimate(c))
	{
		cout << "\033[2J\033[1;1H";
		cout << "Your climate was not accepted. Try again." << endl << endl;

		cout << "Provide the current climate: (1)Cold (2)Temperate (3)Tropical" << endl;
		cin >> c;
	}

	weatherSetup();
}

void Make::weatherSetup()
{
	switch (season)
	{
	case spring:
		if (climate == cold)
		{
			intense = light;
			freq = rare;
			temp = 30;
		}
		else if (climate == temperate)
		{
			intense = medium;
			freq = intermittent;
			temp = 60;
		}
		else
		{
			intense = heavy;
			freq = constant;
			temp = 75;
		}
		break;
	case summer:
		if (climate == cold)
		{
			intense = light;
			freq = intermittent;
			temp = 40;
		}
		else if (climate == temperate)
		{
			intense = medium;
			freq = common;
			temp = 80;
		}
		else
		{
			intense = heavy;
			freq = common;
			temp = 95;
		}
		break;
	case fall:
		if (climate == cold)
		{
			intense = light;
			freq = rare;
			temp = 30;
		}
		else if (climate == temperate)
		{
			intense = medium;
			freq = intermittent;
			temp = 60;
		}
		else
		{
			intense = heavy;
			freq = constant;
			temp = 75;
		}
		break;
	case winter:
		if (climate == cold)
		{
			intense = light;
			freq = drought;
			temp = 20;
		}
		else if (climate == temperate)
		{
			intense = medium;
			freq = rare;
			temp = 30;
		}
		else
		{
			intense = heavy;
			freq = intermittent;
			temp = 50;
		}
		break;
	}
}

void Make::percipTable(int intensity)
{
	int percent = rand() % 100 + 1;
	bool froze = (temp < 32);

	switch (intensity)
	{
	case 0:		// Light Chart
	{
		if (!froze)		// Unfrozen
		{
			if (percent >= 91)										//1 hour
			{
				durHour = 1;

				if (temp < 40)
				{
					weatherType = "sleet";
					setter = sleet;
				}
				else
				{
					weatherType = "Light rain";
					setter = lghtRain;
				}
			}
			else if (percent >= 76)
			{
				weatherType = "light rain";
				setter = lghtRain;
				durHour = rand() % 4 + 1;
			}
			else if (percent >= 51) 
			{
				durHour = rand() % 24 + 1;
				weatherType = "drizzle";
				setter = drizzle;
			}
			else if (percent >= 41) 
			{
				weatherType = "drizzle";
				durHour = rand() % 4 + 1;
				setter = drizzle;
			}
			else if (percent >= 21) 
			{
				weatherType = "medium fog";
				durHour = rand() % 6 + 1;
				setter = medFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "light fog";
				durHour = rand() % 8 + 1;
				setter = lghtFog;
			}
		}
		else if (froze)	// Frozen
		{
			if (percent >= 76) 
			{ 
				weatherType = "light snow";
				durHour = rand() % 24 + 1;
				setter = lghtSnow;
			}
			else if (percent >= 61) 
			{ 
				weatherType = "light snow";
				durHour = rand() % 4 + 1;
				setter = lghtSnow;
			}
			else if (percent >= 51) 
			{ 
				durHour = 1;
				weatherType = "light snow";
				setter = lghtSnow;
			}
			else if (percent >= 41)
			{ 
				weatherType = "medium fog";
				durHour = rand() % 4 + 1;
				setter = medFog;
			}
			else if (percent >= 21) 
			{
				weatherType = "light fog";
				durHour = rand() % 8 + 1;
				setter = lghtFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "light fog";
				durHour = rand() % 6 + 1;
				setter = lghtFog;
			}
		}
		break;
	}
	case 1:		// Medium Chart
	{
		if (!froze)		// Unfrozen
		{
			if (percent >= 91)
			{
				if (temp < 40)
				{
					weatherType = "sleet";
					setter = sleet;
				}
				else
				{
					weatherType = "rain";
					setter = medRain;
				}

				durHour = rand() % 4 + 1;
			}
			else if (percent >= 71) 
			{
				weatherType = "rain";
				durHour = rand() % 24 + 1;
				setter = medRain;
			}
			else if (percent >= 36) 
			{
				weatherType = "rain"; 
				durHour = rand() % 8 + 1;
				setter = medRain;
			}
			else if (percent >= 31) 
			{
				weatherType = "rain";
				durHour = rand() % 4 + 1;
				setter = medRain;
			}
			else if (percent >= 21) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 4 + 1;
				setter = hvyFog;
			}
			else if (percent >= 11) 
			{
				weatherType = "medium fog";
				durHour = rand() % 12 + 1;
				setter = medFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "medium fog";
				durHour = rand() % 8 + 1;
				setter = medFog;
			}
		}
		else if (froze)	// Frozen
		{
			if (percent >= 91)		{ 
				weatherType = "medium snow";
				durHour = rand() % 24 + 1;
				setter = medSnow;
			}
			else if (percent >= 51) 
			{
				weatherType = "medium snow";
				durHour = rand() % 8 + 1;
				setter = medSnow;
			}
			else if (percent >= 31) 
			{
				weatherType = "medium snow";
				durHour = rand() % 4 + 1;
				setter = medSnow;
			}
			else if (percent >= 21) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 4 + 1;
				setter = hvyFog;
			}
			else if (percent >= 11) 
			{
				weatherType = "medium fog";
				durHour = rand() % 8 + 1;
				setter = medFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "medium fog";
				durHour = rand() % 6 + 1;
				setter = medFog;
			}
		}
		break;
	}
	case 2:		// Heavy Chart
	{
		if (!froze)		// Unfrozen
		{
			if (percent >= 91) 
			{
				weatherType = "thunderstorm";
				durHour = rand() % 3 + 1;
				setter = thunder;
			}
			else if (percent >= 86) 
			{
				durHour = 1;
				weatherType = "thunderstorm";
				setter = thunder;
			}
			else if (percent >= 71)
			{
				if (temp < 40)
				{
					weatherType = "sleet";
					setter = sleet;
				}
				else
				{
					weatherType = "heavy rain";
					setter = hvyRain;
				}

				durHour = rand() % 8 + 1;
			}
			else if (percent >= 51) 
			{
				weatherType = "heavy rain";
				durHour = rand() % 24 + 1;
				setter = hvyRain;
			}
			else if (percent >= 21) 
			{
				weatherType = "heavy rain";
				durHour = rand() % 12 + 1;
				setter = hvyRain;
			}
			else if (percent >= 11) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 12 + 1;
				setter = hvyFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 8 + 1;
				setter = hvyFog;
			}
		}
		else if (froze)	// Frozen
		{
			if (percent >= 91) 
			{
				weatherType = "heavy snow";
				durHour = rand() % 6 + 1;
				setter = hvySnow;
			}
			else if (percent >= 61) 
			{
				weatherType = "medium snow";
				durHour = rand() % 8 + 1;
				setter = medSnow;
			}
			else if (percent >= 21) 
			{
				weatherType = "light snow";
				durHour = rand() % 24 + 1;
				setter = lghtSnow;
			}
			else if (percent >= 11) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 12 + 1;
				setter = hvyFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "medium fog";
				durHour = rand() % 8 + 1;
				setter = medFog;
			}
		}
		break;
	}
	case 3:		// Torrential Chart
	{
		if (!froze)		// Unfrozen
		{
			if (percent >= 96) 
			{
				weatherType = "thunderstorm";
				durHour = rand() % 6 + 1;
				setter = thunder;
			}
			else if (percent >= 81) 
			{
				weatherType = "thunderstorm";
				durHour = rand() % 3 + 1;
				setter = thunder;
			}
			else if (percent >= 61)
			{
				if (temp < 40)
				{
					weatherType = "sleet";
					setter = sleet;
				}
				else
				{
					weatherType = "heavy rain";
					setter = hvyRain;
				}

				durHour = rand() % 12 + 1;
			}
			else if (percent >= 31) 
			{
				weatherType = "heavy rain";
				durHour = rand() % 24 + 1;
				setter = hvyRain;
			}
			else if (percent >= 11) 
			{
				weatherType = "heavy rain";
				durHour = rand() % 12 + 1;
				setter = hvyRain;
			}
			else if (percent >= 6) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 12 + 1;
				setter = hvyFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 8 + 1;
				setter = hvyFog;
			}
		}
		else if (froze)	// Frozen
		{
			if (percent >= 91) 
			{
				weatherType = "heavy snow";
				durHour = rand() % 24 + 1;
				setter = hvySnow;
			}
			else if (percent >= 51) 
			{
				weatherType = "heavy snow";
				durHour = rand() % 8 + 1;
				setter = hvySnow;
			}
			else if (percent >= 11) 
			{
				weatherType = "heavy snow";
				durHour = rand() % 4 + 1;
				setter = hvySnow;
			}
			else if (percent >= 6) 
			{
				weatherType = "heavy fog";
				durHour = rand() % 12 + 1;
				setter = hvyFog;
			}
			else if (percent >= 1) 
			{
				weatherType = "medium fog";
				durHour = rand() % 8 + 1;
				setter = medFog;
			}
		}
		break;
	}
	}
}

void Make::determineTemp()
{
	int percent = rand() % 100 + 1;

	if (season == spring)
		temp = baseTemp[0];
	else if (season == summer)
		temp = baseTemp[1];
	else if (season == fall)
		temp = baseTemp[2];
	else if (season == winter)
		temp = baseTemp[3];

	switch (climate)
	{
	case cold:
	{
		if (percent == 100)
		{
			temp += (rand() % 30 + 1);
			durDay = (rand() % 2 + 1);
		}
		else if (percent >= 96)
		{
			temp += (rand() % 20 + 1);
			durDay = (rand() % 4 + 1);
		}
		else if (percent >= 81)
		{
			temp += (rand() % 10 + 1);
			durDay = (rand() % 7 + 1);
		}
		else if (percent >= 61)
		{
			temp = temp;
			durDay = (rand() % 8 + 1);
		}
		else if (percent >= 41)
		{
			temp -= (rand() % 10 + 1);
			durDay = (rand() % 8 + 1);
		}
		else if (percent >= 21)
		{
			temp -= (rand() % 20 + 1);
			durDay = (rand() % 7 + 1);
		}
		else if (percent >= 1)
		{
			temp -= (rand() % 30 + 1);
			durDay = (rand() % 4 + 1);
		}
		break;
	}
	case temperate:
	{
		if (percent >= 96)
		{
			temp += (rand() % 30 + 1);
			durDay = (rand() % 2 + 1);
		}
		else if (percent >= 86)
		{
			temp += (rand() % 20 + 1);
			durDay = (rand() % 4 + 1);
		}
		else if (percent >= 66)
		{
			temp += (rand() % 10 + 1);
			durDay = (rand() % 5 + 1);
		}
		else if (percent >= 36)
		{
			temp = temp;
			durDay = (rand() % 7 + 1);
		}
		else if (percent >= 16)
		{
			temp -= (rand() % 10 + 1);
			durDay = (rand() % 5 + 1);
		}
		else if (percent >= 6)
		{
			temp -= (rand() % 20 + 1);
			durDay = (rand() % 4 + 1);
		}
		else if (percent >= 1)
		{
			temp -= (rand() % 30 + 1);
			durDay = (rand() % 2 + 1);
		}
		break;
	}
	case tropical:
	{
		if (percent >= 86)
		{
			temp += (rand() % 20 + 1);
			durDay = (rand() % 2 + 1);
		}
		else if (percent >= 56)
		{
			temp += (rand() % 10 + 1);
			durDay = (rand() % 4 + 1);
		}
		else if (percent >= 26)
		{
			temp = temp;
			durDay = (rand() % 4 + 1);
		}
		else if (percent >= 11)
		{
			temp -= (rand() % 10 + 1);
			durDay = (rand() % 2 + 1);
		}
		else if (percent >= 1)
		{
			temp -= (rand() % 20 + 1);
			durDay = (rand() % 2 + 1);
		}
		break;
	}
	}
}

void Make::nextDay()
{
	int tempTemp;

	day++;
	if (day > 30)
	{
		day = 1;
		month++;
		if (month > 12)
			month = 1;
	}

	if (month == 2 && day == 16)
	{
		tempTemp = temp;
		setSeason(1);
		weatherSetup();
		temp = tempTemp;
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 6 && day == 26)
	{
		tempTemp = temp;
		setSeason(2);
		weatherSetup();
		temp = tempTemp;
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 8 && day == 23)
	{
		tempTemp = temp;
		setSeason(3);
		weatherSetup();
		temp = tempTemp;
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 12 && day == 7)
	{
		tempTemp = temp;
		setSeason(4);
		weatherSetup();
		temp = tempTemp;
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
}

// Light = 0 | Med = 1 | Heavy = 2 | Torrent = 3
void Make::determinePer()
{
	int percent;
	percent = rand() % 100 + 1;	

	switch (freq)
	{
	case drought:
	{
		if (percent >= 96 && intense == torrential)
			percipTable(1); // Making intensity 'medium'
		else if (percent >= 96)
			percipTable(0); // Making intensity 'light'
		else
			weatherType = "no percipitation";
		break;
	}
	case rare:
	{
		if (percent >= 86)
			percipTable(intense);
		else
			weatherType = "no percipitation";
		break;
	}
	case intermittent:
	{
		if (percent >= 71)
			percipTable(intense);
		else
			weatherType = "no percipitation";
		break;
	}
	case common:
	{
		if (percent >= 41)
			percipTable(intense);
		else
			weatherType = "no percipitation";
		break;
	}
	case constant:
	{
		if (percent >= 6)
			percipTable(intense);
		else
			weatherType = "no percipitation";
		break;
	}
	default:
		cout << "Something went wrong..." << endl;
		break;
	}
}

void Make::displayWeather()
{
	cout << "\033[2J\033[1;1H";

	cout << "We start in the " << currSea << " season in a " << currCli << " climate." << endl;

	for (int i = 0; i < daysPass; i++)
	{
		cout << "Current date (MM/DD): " << month << "/" << day << endl;
		output << month << " " << day << endl;

		if (durDay == 0)
			determineTemp();
		else
			durDay--;

		durHour = 0;
		determinePer();

		cout << "The temperature is " << temp << '\370' << "F" << endl;
		output << temp << endl;

		if (weatherType == "no percipitation")
		{
			cout << "The weather's clear all day long." << endl << endl << endl;
			output << "Clear -" << endl;
		}
		else
		{
			output << weatherType << " " << durHour << endl;
			cout << "The weather calls for " << weatherType << " for " << durHour << " hours." << endl;
		}

		if (weatherType != "no percipitation")
		{
			switch (setter)
			{
			case drizzle:
				cout << "Drizzle: Reduce visibility to 3/4 range, -2 on perception checks. All tiny unprotected flames are extinguished." << endl;
				break;
			case lghtRain:
				cout << "Light Rain: Reduce visibility to 1/2, -2 on Perception & ranged attacks. All tiny unprotected flames are extinguished." << endl;
				break;
			case medRain:
				cout << "Rain: Reduce visibility to 1/2, -4 on Perception & ranged attacks. All unprotected flames are extinguished." << endl;
				break;
			case hvyRain:
				cout << "Rain: Reduce visibility to 1/4, -6 on Perception & ranged attacks. All unprotected flames are extinguished." << endl;
				break;
			case sleet:
				cout << "Sleet: Reduce visibility to 3/4 range, -2 on perception checks & ranged attacks. 75% chance to extinguish unprotected" << endl <<
					"flames." << endl;
				break;
			case lghtFog:
				cout << "Light Fog: Reduce visibility to 3/4 range, -2 on perception checks & ranged attacks." << endl;
				break;
			case medFog:
				cout << "Medium Fog: Reduce visibility to 1/2, -4 on Perception & ranged attacks." << endl;
				break;
			case hvyFog:
				cout << "Heavy Fog: All vision reduced to 5ft, including darkvision. Creatures 5ft away have concealment." << endl;
				break;
			case lghtSnow:
				cout << "Light Snow: Reduce visibility to 3/4 range, -2 on perception checks & ranged attacks. 75% chance to extinguish" << endl <<
					"unprotected flames. Every 2 hrs of snow is 1in on the ground. If 2in, 2 move/block. If 1ft, 3 move/block." << endl;
				break;
			case medSnow:
				cout << "Medium Snow: Reduce visibility to 1/2, -4 on Perception & ranged attacks. All unprotected flames are extinguished." << endl <<
					"Every hr of snow is 1in on the ground. if 2in, 2 move/block. If 1ft, 3 move/block." << endl;
				break;
			case hvySnow:
				cout << "Heavy Snow: Reduce visibility to 1/4, -6 on Perception & ranged attacks. All unprotected flames are extinguished." << endl <<
					"Moving into space with heavy snow is 2 move/block. Every hr leaves 1d4 in of snow on the ground. if 2in, 2 move/block." << endl <<
					"If 1ft, 3 move / block." << endl;
				break;
			case thunder:
				cout << "Thunderstorm: Refer to book (for now)." << endl;
				break;
			default:
				break;
			}
		}

		cout << endl << endl;
		output << endl;
		nextDay();
	}
}

void Make::setTime(int t)
{
	daysPass = t;
}
