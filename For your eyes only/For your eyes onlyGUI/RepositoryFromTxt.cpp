#include "RepositoryFromTxt.h"
#include "Validator.h"

vector<Record>FileRepository::loadRecords()
{
	ifstream file{ this->path };
	vector<Record> records;
	Record record;
	while (file >> record)
	{
		records.push_back(record);
	}
	file.close();

	return records;
}

void FileRepository::saveRecords(vector<Record> records)
{
	ofstream file{ this->path };
	for (const auto& record : records)
		file << record;
	file.close();
}

void FileRepository::setFileLocation(std::string& path)
{
	this->path = path;
}

void FileRepository::addRecord(const Record& recording)
{
	vector<Record>records = this->loadRecords();
	int index = this->searchRecord(records, recording);

	records.push_back(recording);
	this->saveRecords(records);
}

void FileRepository::deleteRecord(const std::string title)
{
	vector<Record> records = this->loadRecords();
	Date date{ 0,0,0 };
	Record existingRecord{ title,"",date,0,"" };
	int index = this->searchRecord(records,existingRecord);
	if (index == -1)
	{
		throw RepositoryException("No record avaliable\n");
	}
	records.erase(records.begin() + index);

	this->saveRecords(records);
}

void FileRepository::updateRecord(const Record& record)
{
	vector<Record> records = this->loadRecords();
	int index = this->searchRecord(records,record);
	if (index == -1)
	{
		throw RepositoryException("No record avaliable\n");
	}
	records[index] = record;
	this->saveRecords(records);
}

vector<Record> FileRepository::getRecords()
{
	vector<Record> records = this->loadRecords();
	return records;
}

bool FileRepository::titleExist(const Record record, const std::string& title)
{
	if (record.getTitle() == title)
		return true;
	return false;
}

Record FileRepository::getRecordPosition(int position)
{
	vector<Record> records = this->loadRecords();
	return records[position];
}

int FileRepository::getPositionRecord(const Record& record)
{
	std::vector<Record> records = this->loadRecords();
	std::vector<Record>::iterator iteratorRecord;
	iteratorRecord = std::find(records.begin(), records.end(), record);

	if (iteratorRecord == records.end())
		return -1;

	int index = std::distance(records.begin(), iteratorRecord);
	return index;
}

Record FileRepository::getRecord()
{
	std::vector<Record> records = this->loadRecords();
	return records[this->iteratorIndex];
}
void FileRepository::next()
{
	this->iteratorIndex++;

	if (this->iteratorIndex == this->getRecords().size())
		this->iteratorIndex = 0;
}

int FileRepository::searchRecord(vector<Record> records, const Record& record)
{
	std::vector<Record>::iterator iteratorForRecord;
	iteratorForRecord = std::find(records.begin(), records.end(), record);

	if (iteratorForRecord == records.end())
	{
		return -1;
	}

	auto index = std::distance(records.begin(), iteratorForRecord);
	return index;
}