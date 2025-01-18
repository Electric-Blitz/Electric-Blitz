#include <iostream> // for cin, cout
#include <fstream>  // for ifstream, ofstream
#include <string>   // for any string stuff
#include "Client.h" // for Client and Pet structs
                    // and function prototypes
using namespace std;

void getClients(Client clients[], int& count, int& nextClientId)
{
    ifstream inFile;
    inFile.open("groomerDB.dat");

    if (!inFile)
    {
        cout << "ERROR. File failed to open. Terminating...";
        exit(1);
    }

    inFile >> count;
    inFile >> nextClientId;

    for (int i = 0; i < count; i++)
    {
        clients[i] = readOne(inFile);
    }

    inFile.close();
}

Client readOne(istream& inFile)
{
    string trash;

    Client focus;
    inFile >> focus.clientID;
    getline(inFile, trash);
    getline(inFile, focus.name);
    getline(inFile, focus.address);
    inFile >> focus.acctBal;
    inFile >> focus.howMany;

    for (int p = 0; p < focus.howMany; p++)
    {
        inFile >> focus.pets[p].species;
        getline(inFile, trash);
        getline(inFile, focus.pets[p].breed);
        getline(inFile, focus.pets[p].name);
        inFile >> focus.pets[p].gender;
        inFile >> focus.pets[p].age;
    }

    return focus;
}

int findClient(const Client clients[], int count, int clientId)
{
    int index = -1;

    for (int i = 0; i < count; i++)
    {
        if (clientId == clients[i].clientID)
            index = i;
    }

    return index;
}

void printBill(const Client clients[], int clientId, int count)
{
    int index;
    
    index = findClient(clients, count, clientId);

    if (index == -1)
        cout << "There is no client with that ID." << endl;
    else
    {
        cout << "Bill for " << clients[index].name << endl;
        cout << "Total owed is $" << clients[index].acctBal << endl;
    }
    cout << endl << endl;
}

void printPet(const Client clients[], int clientId, int count)
{
    int index, peti;
    string givenName;
    string trash;
    peti = -1;

    index = findClient(clients, count, clientId);

    if (index == -1)
        cout << "There is no client with that ID." << endl;
    else
    {
        Client doggo = clients[index];
        cout << "Please give the name of the pet." << endl;
        cout << "NOTE: Capitalize the name." << endl;
        cin >> givenName;
        getline(cin, trash);

        cout << endl;

        for (int i = 0; i < count; i++)
        {
            if (givenName == doggo.pets[i].name)
                peti = i;
        }

        if (peti == -1)
            cout << "The pet isn't in the database." << endl;
        else
        {
            cout << "Information for " << doggo.pets[peti].name << endl;
            cout << "Species: " << doggo.pets[peti].species << endl;
            cout << "Breed: " << doggo.pets[peti].breed << endl;
            cout << "Gender: " << doggo.pets[peti].gender << endl;
            cout << "Age: " << doggo.pets[peti].age << endl;
        }
    }
    cout << endl << endl;
}

void addClient(Client clients[], int& count, int& nextClientId)
{
    Client newClient = clients[count];
    string trash;

    if (count == 10)
        cout << "The client list is full. We cannot add another client." << endl;
    else
    {
        getline(cin, trash);

        newClient.clientID = nextClientId;
        cout << "Please input Client Information:" << endl;
        cout << "Name: ";
        getline(cin, newClient.name);

        cout << "Address: ";
        getline(cin, newClient.address);

        cout << "Number of Pets: ";
        cin >> newClient.howMany;

        getline(cin, trash);

        for (int i = 0; i < newClient.howMany; i++)
        {
            cout << "Pet " << i + 1 << " species: :";
            cin >> newClient.pets[i].species;
            getline(cin, trash);
            cout << "Pet " << i + 1 << " breed: ";
            getline(cin, newClient.pets[i].breed);
            cout << "Pet " << i + 1 << " name: ";
            getline(cin, newClient.pets[i].name);
            cout << "Pet " << i + 1 << " gender: ";
            cin >> newClient.pets[i].gender;
            cout << "Pet " << i + 1 << " age: ";
            cin >> newClient.pets[i].age;
            getline(cin, trash);
        }

        clients[count] = newClient;
        count++;
        nextClientId++;
        cout << endl << endl;
    }
}

void removeClient(Client clients[], int clientId, int& count)
{
    int index;

    index = findClient(clients, count, clientId);

    if (index == -1)
        cout << "There is no client with that ID." << endl;
    else
    {
        for (int i = (index); i < count; i++)
        {
            clients[i] = clients[i+1];
        }
        count--;
        cout << "Client has been deleted..." << endl;
    }
    cout << endl << endl;
}

void printAllClients(const Client clients[], int count)
{
    cout << "Client List:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << clients[i].name << endl;
        cout << clients[i].clientID << endl;
        cout << clients[i].address << endl;
        cout << clients[i].acctBal << endl;
        cout << "Pets:" << endl;
        for (int p = 0; p < clients[i].howMany; p++)
        {
            cout << "\t" << clients[i].pets[p].name << "  " << clients[i].pets[p].species;
            cout << "  " << clients[i].pets[p].breed << "  " << clients[i].pets[p].gender;
            cout << "  " << clients[i].pets[p].age << endl;
        }
    }
    cout << endl << endl;
}

void saveDatabase(Client clients[], int count, int nextClientId)
{
    ofstream outFile;
    outFile.open("groomerDB.dat");

    if (!outFile)
        cout << "ERROR. File failed to open. Data was not saved.";
    else
    {
        outFile << count << endl;
        outFile << nextClientId << endl;

        for (int i = 0; i < count; i++)
        {
            outFile << endl;
            outFile << clients[i].clientID << endl;
            outFile << clients[i].name << endl;
            outFile << clients[i].address << endl;
            outFile << clients[i].acctBal << endl;
            outFile << clients[i].howMany << endl;
            for (int p = 0; p < clients[i].howMany; p++)
            {
                outFile << clients[i].pets[p].species << endl;
                outFile << clients[i].pets[p].breed << endl;
                outFile << clients[i].pets[p].name << endl;
                outFile << clients[i].pets[p].gender << endl;
                outFile << clients[i].pets[p].age << endl;
            }
        }
        outFile.close();
        cout << "Your database has been updated. Have a great day!" << endl;
    }
}