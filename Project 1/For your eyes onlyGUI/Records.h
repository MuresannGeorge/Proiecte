#pragma once
#include "Recording.h"
#include "MyList.h"


class Records : public MyList 
{
protected:
	std::string fileLocation;

public:
	void add(const Record& record);

	vector<Record> getAll();
	
	void setLocation(std::string fileLocation);

	virtual void saveFile(std::vector<Record> records) = 0;

	virtual std::vector<Record> loadFile() = 0;

	virtual void openFile() = 0;

	virtual ~Records() {};
};

class CSVsave : public Records
{
public:

	void saveFile(std::vector<Record> records) override;

	std::vector<Record> loadFile() override;

	void openFile() override;

	~CSVsave() {};
};

class HTMLsave : public Records
{
public:
	void saveFile(std::vector<Record> records) override;

	std::vector<Record> loadFile() override;

	void openFile() override;

	~HTMLsave() {};
};