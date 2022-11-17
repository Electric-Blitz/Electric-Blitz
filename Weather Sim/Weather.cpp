#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "Maker.h"

using namespace std;

void main()
{
	Make weather;

	string tryer = "1";

	system("Color 0A");

	int inputC, inputD, inputM;

	while (tryer != "0" && tryer != "N" && tryer != "n")
	{
		cout << "\033[2J\033[1;1H";
		cout << "Provide the current climate: (1)Cold (2)Temperate (3)Tropical" << endl;
		cin >> inputC;
		cout << endl;

		cout << "Provide the day number within 1-30: ";
		cin >> inputD;
		cout << endl;

		cout << "Provide the month number within 1-12: ";
		cin >> inputM;
		cout << endl;

		weather.setValues(inputC, inputD, inputM);

		weather.displayWeather();

		cout << "Would you like to go again?" << endl;
		cin >> tryer;
	}

}
