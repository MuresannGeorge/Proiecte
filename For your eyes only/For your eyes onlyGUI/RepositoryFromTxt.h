#pragma once
#include "Recording.h"
#include "Repository.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FileRepository : public Repository
{
private:
	std::string path;
	vector<Record> records;
	vector<Record>::iterator iterator;
	vector<Record> loadRecords();
	int iteratorIndex = 0;
	void saveRecords(vector<Record>records);

public:
	void addRecord(const Record& recording);
	void deleteRecord(const std::string title);
	void updateRecord(const Record& record);
	void setFileLocation(std::string& path);

	vector<Record> getRecords();
	Record getRecord();
	bool titleExist(const Record record, const std::string& title);

	Record getRecordPosition(int position);
	int getPositionRecord(const Record& record);
	void next();

	int searchRecord(vector<Record> records, const Record& record);
};