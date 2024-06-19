
#include <fstream>
#include <string>
#include <list>
#include "FileReceiver.h"

bool FileReceiver::LoadMonsterFile(string name)
{
	if (monsterFile)
	{
		monsterFile.close();
	}

	monsterName = name;
	monsterFile.open(monsterName);

	return monsterFile.is_open();
}

bool FileReceiver::LoadPlayerFile(string name)
{
	if (playerFile)
	{
		playerFile.close();
	}

	playerName = name;
	playerFile.open(playerName);

	return playerFile.is_open();
}

string FileReceiver::CheckActiveFiles()
{

	return string();
}

void FileReceiver::MonsterTable()
{
	//
}

list<string> FileReceiver::PlayerTable()
{
	list<string> players;

	//From playerFile, fill list<string> with each line containing a name.
	//return list<string>

	return players;
}

string FileReceiver::InitialStartup()
{
	monsterFile.open(FILEBASE + "monsterTable.txt");
	playerFile.open(FILEBASE + "playerList.txt");

	if (monsterFile && playerFile)
	{
		monsterName = FILEBASE + "monsterTable.txt";
		playerName = FILEBASE + "playerList.txt";
		return "Both the monster encounter table and the player list has been set up.";
	}
	else if (monsterFile)
	{
		monsterName = FILEBASE + "monsterTable.txt";
		return "The monster encounter table has been set up.";
	}
	else if (playerFile)
	{
		playerName = FILEBASE + "playerList.txt";
		return "The player list has been set up.";
	}
	else
	{
		return "Neither the monster encounter table or the player list were found.";
	}
}