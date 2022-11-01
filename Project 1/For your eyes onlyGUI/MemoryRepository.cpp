#include "MemoryRepository.h"

using namespace std;

void MemoryRepository::addRecord(const Record& recording)
{
	this->records.push_back(recording);
}

void MemoryRepository::deleteRecord(const std::string title)
{

	for (int index = 0; index < records.size(); index++)
	{
		if (records.at(index).getTitle() == title)
		{
			this->records.erase(records.begin() + index);
		}
	}
}

void MemoryRepository::updateRecord(const Record& record)
{
	int index;

	for (index = 0; index < records.size(); index++)
	{
		if (records.at(index).getTitle() == record.getTitle())
		{
			this->records.at(index) = record;
		}
	}
}

bool MemoryRepository::titleExist(const Record record, const std::string& title)
{
	if (record.getTitle() == title)
		return true;
	return false;
}


Record MemoryRepository::getRecordPosition(int position)
{
	return this->records[position];
}
int MemoryRepository::getPositionRecord(const Record& record)
{
	int index;

	for (index = 0; index < records.size(); index++)
	{
		if (records.at(index) == record)
		{
			return index;
		}
	}
	return -1;
}

Record MemoryRepository::getRecord()
{
	return this->records[this->index];
}
void MemoryRepository::next()
{
	this->index++;
	if (this->index == this->getRecords().size())
	{
		this->index = 0;
	}
}

void MemoryRepository::setFileLocation(std::string& path)
{
}
