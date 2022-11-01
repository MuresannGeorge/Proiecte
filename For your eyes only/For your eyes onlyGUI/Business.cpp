#include "Business.h"
#include "Validator.h"
#include <iostream>

using namespace std;

vector<Record> Business::getAllListOfRecords() const
{
	return this->repository.getRecords();
}

int Business::isExisting(const std::string& title)
{
	vector<Record> records = this->getAllListOfRecords();
	int index;

	for (const auto& record: records)
	{
		if (record.getTitle() == title)
			return 1;}
	return 0;
}

Date Business::getDate(int month, int day, int year)
{
	Date timesOfCreation{ month,day,year };
	return timesOfCreation;
}

int Business::addNewRecording(const std::string& title, const std::string location, int month, int day, int year, int timesAccessed, const std::string footagePreview)
{
	Date timeOfCreation{ month,day,year };
	Record record{ title, location, timeOfCreation,timesAccessed,footagePreview };
	if (!this->isExisting(title))
	{
		this->repository.addRecord(record);
		return 1;
	}
	return 0;
}

int Business::deleteExistingRecording(const std::string title)
{
	if (this->isExisting(title))
	{
		this->repository.deleteRecord(title);
		return 1;
	}
	return 0;
}

int Business::updateExistingRecording(const std::string& ExistingTitle, const std::string location, int month, int day, int year, int timesAccessed, const std::string footagePreview)
{
	Date timeOfCreation{ month,day,year };
	Record record{ ExistingTitle,location,timeOfCreation,timesAccessed,footagePreview };

	if (this->isExisting(ExistingTitle) == 1)
	{
		this->repository.updateRecord(record);
		return 1;
	}
	return 0;
}

vector<Record> Business::getFilteredRecords(const std::string& location, int timesAccessed)
{
	vector<Record> filteredRecords;
	vector<Record> records = this->repository.getRecords();

	for (const auto& record:records)
	{
		if (record.getLocation() == location && record.getTimesAccessed() < timesAccessed)
		{
			filteredRecords.push_back(record);
		}
	}
	if (filteredRecords.size() == 0)
	{
		//throw BusinessException("No records avaliable!\n");
	}
	return filteredRecords;
}

Record Business::next()
{
	Record record = this->repository.getRecord();
	this->repository.next();
	return record;
}

void Business::save(std::string title)
{
	Date date{0,0,0};
	Record record{ title,"",date,0,"" };
	int position = this->repository.getPositionRecord(record);

	if (position == -1)
	{
		throw BusinessException("No record to save\n");
	}

	this->savedRecords->add(this->repository.getRecords()[position]);
}
vector<Record> Business::getAllSavedRecords()
{
	return this->savedRecords->getAll();
}

void Business::fileLocation(std::string path)
{
	this->repository.setFileLocation(path);
}

void Business::mylistFileLocation(std::string mylistFileLocation)
{
	if (mylistFileLocation == "memory")
	{
		this->savedRecords = new MemoryMyList{};
		return;
	}
	string extension = mylistFileLocation.substr(mylistFileLocation.size() - 4);

	if (extension == ".csv")
	{
		this->savedRecords = new CSVsave{};
	}
	if (extension == "html")
	{
		this->savedRecords = new HTMLsave{};
	}

	this->savedRecords->setLocation(mylistFileLocation);
}

void Business::openFile()
{
	this->savedRecords->openFile();
}