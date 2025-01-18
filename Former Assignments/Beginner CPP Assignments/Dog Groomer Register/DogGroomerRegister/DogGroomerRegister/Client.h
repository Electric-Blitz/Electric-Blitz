#ifndef _CLIENT_H_  // If _CLIENT_H_ is not defined
#define _CLIENT_H_  // define _CLIENT_H_ to "include guard"

#include <fstream>
#include <string>
using std::string;
using std::istream;

const int MAX_CLIENTS = 10; // Maximum number of clients
const int MAX_PETS = 10;    // Maximum number of pets for a
                            // single client
struct Pet
{
    string species, breed, name;
    char gender;
    int age;
};

struct Client
{
    int clientID;
    string name, address;
    float acctBal;
    int howMany;
    Pet pets[MAX_PETS];
};


//Take all clients info and stores them in. INPUT clients info
/* Function getClients: read the client information from
 *     the file "groomerDB.dat" and stores them in the array
 *     clients[] and updates the count and nextClientId
 * Inputs: clients[] -- an array of Client structs
 *         count -- a reference to an integer count
 *         nextClientId -- a reference to the integer for the next client
 *                         id number
 */
void getClients(Client clients[], int& count, int& nextClientId);

/* Function readOne: used by getClients to read a single client from the
 *      file and returns a Client struct that has been "filled in"
 * Inputs: ifstream & -- the file_object to read from
 * Return: Client variable containing appropriate information
 */
Client readOne(istream&);

//To find WHERE in the array the client is
/* Function findClient: used by printBill, deleteClient, and printPet
 *         to find where the specified Client is in the clients[]
 * Inputs: const Client clients[] -- array of Clients to search in,
 *         int count -- number of clients in the array,
 *         int clientId -- client to search for
 * Returns: returns the integer index of the Client in the clients[]
 *          or a -1 if the client is not found
 */
int findClient(const Client clients[], int count, int clientId);

/* Function printBill: finds a clientId and prints out a bill
 *                     for the client
 * Inputs: const Client clients[] -- array of Clients to search in,
 *         int count -- number of clients in the array,
 *         int clientId -- client to search for and print
 * Output: Bill for the client to stdout (cout)
 */
void printBill(const Client clients[], int clientId, int count);

/* Function printPet: finds a client based on the id, then asks for
 *                    the name of the pet. Looks for and prints
 *                    the appropriate pet information
 * Inputs: const Client clients[] -- array of Clients to search in,
 *         int count -- number of clients in the array,
 *         int clientId -- client to search for and print
 * Output: Pet information for a given pet and client to stdout (cout)
 */
void printPet(const Client clients[], int clientId, int count);

/* Function addClient: if the maximum number of clients is not reached
 *                     it will ask for all client information to be added
 *                     and add that client to the clients[]
 * Inputs: Client clients[] -- array of Clients to add to,
 *         int &count -- current number of clients in the array to be incremented
 *                       after adding,
 *         int &nextClientId -- to be incremented
 * Output: Message if the client list is already at max capacity
 */
void addClient(Client clients[], int& count, int& nextClientId);

/* Function removeClient: removes a Client if it exists, uses
 *                        findClient to find the client first
 *                        and shifts the clients in the array down
 *                        updating the count of clients
 * Inputs: Client clients[] -- array of Clients to remove from,
 *         int &count -- current number of clients in the array to be
 *                       decremented after removal,
 *         int clientId -- to be find
 * Output: Message if the client could not be removed (it didn't exist)
 */
void removeClient(Client clients[], int clientId, int& count);

/* Function printAllClients: prints all clients and their pets
 *                           in the database for a given array
 *                           of clients and a count for how many
 *                           are in the array.
 * Inputs: const Client clients[] -- array of clients,
 *         int count -- how many clients to print
 * Outputs: Prints all information to stdout (cout)
 */
void printAllClients(const Client clients[], int count);

/* Function saveDatabase: will write the count, then the nextClientId, then all the
 *                        client info in the same format that was in the original
 *                        groomerDB.dat file. This data will be written to the file
 *                        groomerDB.dat - i.e., the orginal database file will be
 *                        overwritten.  Don't forget to close it after reading then
 *                        reopen it here for writing.
 * Inputs: Client clients[] -- array of clients to write out to database,
 *         int count -- number of clients currently in the array,
 *         int nextClientId -- the id of the next client
 * Outputs: Message for save and quit
 */
void saveDatabase(Client clients[], int count, int nextClientId);


#endif // End of _CLIENT_H_ include guard