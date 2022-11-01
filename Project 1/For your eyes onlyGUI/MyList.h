#pragma once
#include "Recording.h"

class MyList
{
public:
	virtual void add(const Record& record)=0;
	virtual void openFile() = 0;
	virtual void setLocation(std::string fileLocation)=0;
	virtual vector<Record> getAll()=0;
};