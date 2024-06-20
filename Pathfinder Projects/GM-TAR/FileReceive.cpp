
#include <fstream>
#include <string>
#include <vector>
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

vector<string> FileReceiver::PlayerTable()
{
	vector<string> players;
	string name;

	while (getline(playerFile, name))
	{
		players.push_back(name);
	}

	playerFile.seekg(playerFile.beg);

	return players;
}

FileResult FileReceiver::InitialStartup()
{
	monsterFile.open(FILEBASE + "monsterTable.txt");
	playerFile.open(FILEBASE + "playerList.txt");

	if (monsterFile && playerFile)
	{
		monsterName = FILEBASE + "monsterTable.txt";
		playerName = FILEBASE + "playerList.txt";
		result = Both;
		return result;
	}
	else if (monsterFile)
	{
		monsterName = FILEBASE + "monsterTable.txt";
		result = MonsterOnly;
		return result;
	}
	else if (playerFile)
	{
		playerName = FILEBASE + "playerList.txt";
		result = PlayerOnly;
		return result;
	}
	else
	{
		return result;
	}
}

FileResult FileReceiver::GetResult()
{
	return result;
}
