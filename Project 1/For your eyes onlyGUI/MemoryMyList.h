#pragma once
#include "Recording.h"
#include "MyList.h"
#include "Validator.h"
class MemoryMyList : public MyList
{
private:
	vector<Record> records;
public:
	void add(const Record& record);
	vector<Record> getAll();
	void openFile() {};
	void setLocation(std::string fileLocation) {};
};