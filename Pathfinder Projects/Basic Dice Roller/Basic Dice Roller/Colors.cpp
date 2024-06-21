#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Colors.h"

using namespace std;

void Colors::SetColor(ColorOptions color)
{
	switch (color)
	{
	case Pink:
		system("Color 0D");
		break;
	case Red:
		system("Color 04");
		break;
	case Purple:
		system("Color 05");
		break;
	case LgtBlue:
		system("Color 09");
		break;
	case Yellow:
		system("Color 0E");
		break;
	case Orange:
		system("Color 06");
		break;
	case DrkBlue:
		system("Color 01");
		break;
	case Green:
		system("Color 0A");
		break;
	case Default:
		system("Color 07");
		break;
	default:
		cout << "No valid option was given. Color will not be changed." << endl;
		break;
	}
}

void Colors::ColorChange()
{
	int choice = 0;
	enum ColorOptions color;

	cout << "Changing Colors" << endl << endl;

	cout << "Write the number that corresponds to the color you want the text to be in." << endl
		<< "Currently, we have:" << endl
		<< "Pink(1), Red(2), Purple(3), LgtBlue(4), Yellow(5), Orange(6)," << endl
		<< "DrkBlue(7), Green(8), Default(9)" << endl;

	cout << "Type the Color you Want: ";
	cin >> choice;

	color = static_cast<ColorOptions>(choice);

	SetColor(color);
}