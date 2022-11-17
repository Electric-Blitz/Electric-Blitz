#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Maker.h"

using namespace std;

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
		setSeason(1);
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 6 && day == 26)
	{
		setSeason(2);
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 8 && day == 23)
	{
		setSeason(3);
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
	else if (month == 12 && day == 7)
	{
		setSeason(4);
		cout << "----------We're now in the " << currSea << " season!----------" << endl;
	}
}

void Make::displayWeather()
{
	cout << "\033[2J\033[1;1H";

	cout << "We start in the " << currSea << " season in a " << currCli << " climate." << endl;

	for (int i = 0; i < 360; i++)
	{
		cout << "Current date (MM/DD): " << month << "/" << day << endl;

		if (durDay == 0)
			determineTemp();
		else
			durDay--;

		cout << "The temperature is " << temp << '\370' << "F" << endl << endl << endl;

		nextDay();
	}
}
