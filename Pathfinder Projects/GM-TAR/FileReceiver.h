#ifndef _FILERECEIVER_H_
#define _FILERECEIVER_H_
#pragma once

using namespace std;

class FileReceiver
{
private:
	fstream monsterFile, playerFile;
	string monsterName, playerName;
	const string FILEBASE = "../Resources/";

public:
	bool LoadMonsterFile(string);
	bool LoadPlayerFile(string);
	string CheckActiveFiles();
	void MonsterTable();
	list<string> PlayerTable();
	string InitialStartup();

};

#endif