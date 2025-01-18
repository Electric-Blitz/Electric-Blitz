/* Author: Zachary Kent
 * Dog Groomer Register
 *
 * Course: Compute Science I (2170-005)
 *
 * Purpose: To read in a set of data containing a list
 *          of clients, their information and their pets, 
 *          which can then have clients added and removed
 *          during the program.
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
#include "Client.h"

using namespace std;

int main()
{
    Client clients[MAX_CLIENTS]; // Array of Clients
    int nextClientId;            // next id to use if/when adding a client
    int clientId;                // hold's the client id when asked for
                                 // by the user
    int choice = 0;              // hold's the choice entered by the user
    int count;                   //index of array clients.

    cout << "Please input the count of the groomerDB.dat file (default is '5'):";

    cin >> count;

    cout << endl << "Next, please input the 'ClientID' of the groomerDB.dat file (default is '111'):";
    cin >> nextClientId;
    cout << endl << endl;

    getClients(clients, count, nextClientId); // Get the clients from the database

    while (choice != 6)
    {
        cout << "What would you like to do? ";
        cout << "\n 1.  Print out a bill for a client\n";
        cout << " 2.  Print out the information on a pet for a client\n";
        cout << " 3.  Add a client\n";
        cout << " 4.  Delete a client\n";
        cout << " 5.  Print the database of clients\n";
        cout << " 6.  Quit and write out the database\n";

        cin >> choice;

        switch (choice)
        {
        case 1: cout << "What is the client's ID ";
            cin >> clientId;
            printBill(clients, clientId, count);
            break;

        case 2: cout << "What is the client's ID ";
            cin >> clientId;
            printPet(clients, clientId, count);
            break;

        case 3: addClient(clients, count, nextClientId);
            break;

        case 4: cout << "What is the client's ID ";
            cin >> clientId;
            removeClient(clients, clientId, count);
            break;

        case 5: printAllClients(clients, count);
            break;

        case 6: saveDatabase(clients, count, nextClientId);
            break;

        default:cout << "invalid input\n";
        }

        cout << endl << endl;
    }
    return 0;
}

