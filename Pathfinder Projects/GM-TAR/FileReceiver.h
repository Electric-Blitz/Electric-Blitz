#ifndef _FILERECEIVER_H_
#define _FILERECEIVER_H_
#pragma once

using namespace std;

enum FileResult {Both, MonsterOnly, PlayerOnly, None};

class FileReceiver
{
private:
	FileResult result = None;
	ifstream monsterFile, playerFile;
	string monsterName, playerName;
	const string FILEBASE = "../Resources/";

public:
	bool LoadMonsterFile(string);
	bool LoadPlayerFile(string);
	string CheckActiveFiles();
	void MonsterTable();
	vector<string> PlayerTable();
	FileResult InitialStartup();
	FileResult GetResult();
};

#endif