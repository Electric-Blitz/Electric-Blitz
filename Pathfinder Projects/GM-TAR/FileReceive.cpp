
#include "FileReceiver.h"

bool FileReceiver::LoadMonsterFile(string name)
{
	if (monsterFile)
	{
		monsterFile.close();
	}

	monsterName = FILEBASE + name;
	monsterFile.open(monsterName);

	if (monsterFile.is_open())
	{
		if (result == PlayerOnly)
		{
			result = Both;
		}
		else if (result == None)
		{
			result = MonsterOnly;
		}

		return true;
	}

	return false;
}

bool FileReceiver::LoadPlayerFile(string name)
{
	if (playerFile)
	{
		playerFile.close();
	}

	playerName = FILEBASE + name;
	playerFile.open(playerName);

	if (monsterFile.is_open())
	{
		if (result == MonsterOnly)
		{
			result = Both;
		}
		else if (result == None)
		{
			result = PlayerOnly;
		}

		return true;
	}

	return false;
}

vector<string> FileReceiver::MonsterTable()
{
	vector<string> monsters;
	string line;
	
	while (getline(monsterFile, line))
	{
		monsters.push_back(line);
	}

	monsterFile.seekg(monsterFile.beg);

	return monsters;
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
