/* Author: Zachary Kent
 * Array Practice
 *
 * Course: Compute Science I (2170-005)
 *
 * Purpose: To read in a list of grades from grades.txt,
 *          calculate the # of grades, total points,
 *			max possible points, and the % each grade is
 *          worth.
 *
 * [Like with all assignments from college courses, some
 *			code may be adjusted so as to prevent
 *			information unrelated to code itself or to
 *			prevent being used in similar assignments by
 *			others.]
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	double grades[30];			//Array that will contain grades
	int count = 0;				//counts how many grades there are
	int total = 0;				//Adds the total points of all grades together.
	int maxPoints = 0;			//Holds number of maximum points possible.
	float percentage[30];		//How much a particular grade is worth.
	float final = 0.0;			//The final percent from given grades
	ifstream inFile;			//Input file of grades

	inFile.open("grades.txt");	//Opens the input file

	if (!inFile)
	{							//If file did not open, exit program
		cout << "Input file failed to open. Please try again. Terminating program...";
		cin.get();
		cin.ignore();
		exit(1);
	}

	while (!inFile.eof())		//Goes through reading in the grades into the array
	{							//while also incrementing count.
		inFile >> grades[count];
		count++;
	}

	maxPoints = count * 100;	//Collects amount of max points possible

	for (int i = 0; i < count; i++)
	{							//adds the amount of points together
		total = total + grades[i];
	}

	for (int i = 0; i < count; i++)
	{							//Calculates % a single grade is worth
		percentage[i] = (grades[i] / maxPoints) * 100;
	}

	for (int i = 0; i < count; i++)
	{							//Calculates the final grade in % form
		final = final + percentage[i];
	}

	cout << "Number of Grades:" << setw(10) << right << count << endl;
	cout << "Total Points Earned:" << setw(7) << right << total << endl;
	cout << "Max Possible Points:" << setw(7) << right << maxPoints << endl << endl;
	//Outputs # of grades, total points, and max points.

	for (int i = 0; i < count; i++)
	{							//Outputs each grade given & its worth in total points.
		cout << fixed << setw(19) << setprecision(0) << grades[i] << setw(7) << right;
		cout << fixed << setprecision(1) << percentage[i] << "%" << endl;
	}

	cout << endl;
	cout << "Final Grades:" << setw(13) << right << fixed << setprecision(1) << final << "%";
	//Outputs the final grade in % form.

	return 0;
}