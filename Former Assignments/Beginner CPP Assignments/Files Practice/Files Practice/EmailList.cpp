/* Author: Zachary Kent
 * File Input/Output Practice
 *
 * Course: Compute Science I (2170-005)
 *
 * Purpose: To read in a file, take all email addresses,
 *			remove any commas at the end, and pass them
 *			into the output file.
 *
 * [Like with all assignments from college courses, some
 *			code may be adjusted so as to prevent
 *			information unrelated to code itself or to
 *			prevent being used in similar assignments by
 *			others.]
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string email;				//String to hold each word passed through the input.
	ifstream input;				//mail.dat
	ofstream output;			//email_list.dat
	int size = 0;				//size of the string passed through
	int finder = -1;			//Used to locate if and where a '@' symbol appears for emails
	//and the ',' at the end if it is there.

	input.open("mail.dat");
	if (!input)					//Opens the mail.dat file and checks if it opened.
	{
		cout << "Input file failed to open. Please try again. Terminating program...";
		exit(1);
	}

	output.open("email_list.dat");
	//Opens the output file

	input >> email;				//Prime read

	while (input)				//While the file has an input
	{
		finder = email.find('@', 0);
		//Searches for an '@' to find an email

		if (finder == -1)		//If no email, next string.
			input >> email;
		else
		{						//If there IS an email

			finder = -1;
			size = email.size();
			finder = email.find(',', size - 1);
			//Reset finder, set size, then search for comma
			//at end of string w/ finder & size.

			if (finder != -1)	//If there is a comma at the end
			{
				email.erase(finder, 1);
				finder = -1;	//erase the comma, reset finder
			}

			output << email << endl;
			input >> email;		//Output email & read the next string.
		}
	}

	cout << "email_list.dat has been created." << endl;
	input.close();
	output.close();

	return 0;					//End program
}