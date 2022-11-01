#pragma once
#include "Recording.h"
#include <vector>
#include <string>
#include "Repository.h"

class MemoryRepository : public Repository
{
private:
	vector<Record> records;
	int index = 0;

public:
	//Initializes an object of the type repository

	//Return the Vector that contains the Records
	vector<Record> getRecords() { return records; }

	/*
	Adds an element to Repository
	input - Record recording, the new recording that will be added
	output -
*/
	void addRecord(const Record& recording);

	/*
	Delete and Record from Repository
	input - string title, the Id of the Record
	output -
*/
	void deleteRecord(const std::string title);

	/*
	Update an existing Record from Repository
	input - Record recording, the new recording that will be replaced
	output -
*/
	void updateRecord(const Record& record);

	Record getRecord();
	bool titleExist(const Record record, const std::string& title);

	Record getRecordPosition(int position);
	int getPositionRecord(const Record& record);
	void next();
	void setFileLocation(std::string& path);
};

