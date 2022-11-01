#include "Records.h"
#include "Validator.h"

void Records::add(const Record& record)
{
	vector<Record> records = this->loadFile();

	for (auto savedRecord : records)
	{
		if (savedRecord == record)
			throw RepositoryException("Record already saved!\n");
	}

	records.push_back(record);

	this->saveFile(records);
}

vector<Record> Records::getAll()
{
	vector<Record> records = this->loadFile();
	return records;
}

void Records::setLocation(std::string fileLocation)
{
	this->fileLocation = fileLocation;
}

std::vector<Record> CSVsave::loadFile()
{
	std::vector<Record> records;
	Record record;

	ifstream file{ this->fileLocation };
	while (file >> record)
		records.push_back(record);

	file.close();
	return records;
}

void CSVsave::openFile()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", this->fileLocation.c_str(), NULL, SW_SHOWNORMAL);
}

void CSVsave::saveFile(std::vector<Record> records)
{
	ofstream file{ this->fileLocation };
	for (const auto& record : records)
		file << record;
	file.close();
}

void HTMLsave::saveFile(std::vector<Record> records)
{
	ofstream file{ this->fileLocation };

	file << "<!DOCTYPE html>\n<html>\n<head>\n";          
	file << "<title>Records</title>\n";         
	file << "</head>\n<body>\n<table border=\"1\"\n";     

	file << "<tr>\n<td>Title</td>\n<td>Location</td>\n<td>Time Of Creation</td>\n<td>Times Accessed</td>\n<td>Footage Preview</td>\n</tr>\n";

	for (auto record : records)
		file << record.toHTML()<<endl;

	file << "</table>\n</body>\n</html>";

	file.close();
}

std::vector<Record> HTMLsave::loadFile()
{
	std::vector<Record> records;

	ifstream file{ this->fileLocation };
	string line, header;
	string title, location, timeofcreation, timesaccessed, footagepreview;

	for (int i = 0; i <= 13; i++)
		getline(file, line);

	getline(file, line);
	while (line == "<tr>")
	{
		getline(file, line);
		title = line.substr(4, line.size() - 9);

		getline(file, line);
		location = line.substr(4, line.size() - 9);

		getline(file, line);
		timeofcreation = line.substr(4, line.size() - 9);

		std::string month = timeofcreation.substr(0, timeofcreation.find("-"));
		timeofcreation = timeofcreation.erase(0, month.length() + 1);

		std::string day = timeofcreation.substr(0, timeofcreation.find("-"));
		timeofcreation = timeofcreation.erase(0, day.length() + 1);

		std::string year = timeofcreation.substr(0, timeofcreation.find("-"));
		timeofcreation = timeofcreation.erase(0, year.length() + 1);

		getline(file, line);
		timesaccessed = line.substr(4, line.size() - 9);

		getline(file, line);
		footagepreview = line.substr(4, line.size() - 9);

		Date date{ stoi(month),stoi(day),stoi(year)};
		Record record{ title,location,date,stoi(timesaccessed),footagepreview };
		records.push_back(record);

		getline(file, line);

		getline(file, line);

	}

	file.close();
	return records;
}

void HTMLsave::openFile()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->fileLocation.c_str(), NULL, SW_SHOWMAXIMIZED);
}