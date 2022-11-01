#pragma once
#include "Recording.h"
#include <vector>
#include <string>

class Repository
{
private:
	vector<Record> records;
	vector<Record>::iterator iterator;

public:


	//Return the Vector that contains the Records
	virtual vector<Record> getRecords() = 0;

	/*
	Adds an element to Repository
	input - Record recording, the new recording that will be added
	output -
*/
	virtual void addRecord(const Record& recording) = 0;

	/*
	Delete and Record from Repository
	input - string title, the Id of the Record
	output -
*/
	virtual void deleteRecord(const std::string title) = 0;

	/*
	Update an existing Record from Repository
	input - Record recording, the new recording that will be replaced
	output -
*/
	virtual void updateRecord(const Record& record) = 0;

	virtual Record getRecord() = 0;
	virtual bool titleExist(const Record record, const std::string& title) = 0;

	virtual Record getRecordPosition(int position) = 0;
	virtual int getPositionRecord(const Record& record) = 0;
	virtual void next() = 0;

	virtual void setFileLocation(std::string& path) = 0;
};

