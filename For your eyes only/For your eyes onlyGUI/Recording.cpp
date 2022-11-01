#include "Recording.h"

Date::Date() : month(), day(), year() {}

Date::Date(const int month,const int day,const int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

void Date::setDay(int day)
{
	this->day = day;
}
void Date::setMonth(int month)
{
	this->month = month;
}
void Date::setYear(int year)
{
	this->year = year;
}

std::string Date::printDate()
{
	return std::to_string(this->getMonth()) + "-" + std::to_string(this->getDay()) + "-" + std::to_string(this->getYear());
}
void Date::resetDate()
{
	this->month = 0;
	this->day = 0;
	this->year = 0;
}

Record::Record() : title(""), location(""), timeOfCreation(), timesAccessed(), footagePreview(""){}

Record::Record(const std::string& title, const std::string& location, const Date timeOfCreation, const int timesAccessed, const std::string& footagePreview)
{
	this->title = title;
	this->location = location;
	this->timeOfCreation = timeOfCreation;
	this->timesAccessed = timesAccessed;
	this->footagePreview = footagePreview;
}
void Record::setTitle(string title)
{
	this->title = title;
}

void Record::setLocation(string location)
{ 
	this->location = location; 
}

void Record::setTimesAccessed(int timesaccesesd)
{ 
	this->timesAccessed = timesaccesesd; 
}

void Record::setFootagePreview(string footagepreview)
{ 
	this->footagePreview = footagepreview; 
}
void Record::setTimeOfCreation(Record& record,string timeOfCreation)
{
	vector<string> tokens = record.tokenize(timeOfCreation, '-');
	record.timeOfCreation.setMonth(stoi(tokens.at(0)));
	record.timeOfCreation.setDay(stoi(tokens.at(1)));
	record.timeOfCreation.setYear(stoi(tokens.at(2)));
}
void Record::resetRecord()
{
	this->title = "";
	this->location = "";
	this->timeOfCreation.resetDate();
	this->timesAccessed = 0;
	this->footagePreview = "";
}

bool Record::operator==(const Record& record)
{
	return this->title == record.title;
}

std::string Record::printRecord()
{
	return "Title: " + this->getTitle() + " Location:" + this->getLocation() + " Time of Creation: " + this->timeOfCreation.printDate() + " Times accessed: " + std::to_string(this->getTimesAccessed()) + " Footage Preview:" + this->getFootagePreview();
}

std::string Record::printTimesOfCreation()
{
	return std::string();
}

vector<string>Record::tokenize(const string& stringToCheck, char separator)
{
	vector<string> result;
	stringstream secondString(stringToCheck);
	string token;
	while (getline(secondString, token, separator))
		result.push_back(token);
	return result;
}


ostream& operator<<(ostream& os, const Record& record)
{
	os << record.getTitle() << "," << record.getLocation() << ","<< record.timeOfCreation.getMonth()<< "-" << record.timeOfCreation.getDay() << "-" <<record.timeOfCreation.getYear() << "," << record.getTimesAccessed() << "," << record.getFootagePreview() << "\n";
	return os;
}

istream& operator>>(istream& in, Record& record)
{
	record.resetRecord();
	string line;
	getline(in, line);
	vector<string> tokens = record.tokenize(line, ',');
	if (tokens.size() != 5)
		return in;
	record.setTitle(tokens.at(0));
	record.setLocation(tokens.at(1));
	record.setTimeOfCreation(record,tokens.at(2));
	record.setTimesAccessed(stoi(tokens.at(3)));
	record.setFootagePreview(tokens.at(4));

	return in;
}


std::string Record::toHTML()
{
	string convertHtml;
	convertHtml = "<tr>\n<td>" + this->title + "</td>\n<td>" + this->location + "</td>\n<td>" + this->timeOfCreation.printDate() + "</td>\n<td>" + std::to_string(this->timesAccessed) + "</td>\n<td>" + this->footagePreview + "</td>\n</tr";
	return convertHtml;
}