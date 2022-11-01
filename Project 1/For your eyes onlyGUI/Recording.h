#pragma once
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date();

	Date(const int day, const int month, const int year);

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	
	std::string printDate();
	void resetDate();
};

class Record
{
private:
	std::string title;
	std::string location;
	Date timeOfCreation;
	int timesAccessed;
	std::string footagePreview;

public:
	//default constructor
	Record();

	//constructor with parameters
	Record(const std::string& title, const std::string& location, Date timeOfCreation, const int timesAccessed, const std::string& footagePreview);

	//returns the Title of the Record
	std::string getTitle() const { return title; }

	//returns the Location of the Record
	std::string getLocation() const { return location; }

	//returns the Times Of Creation of the Record
	Date gettimeOfCreation() const { return timeOfCreation; }

	//returns the TimesAccessed of the Record
	int getTimesAccessed() const { return timesAccessed; }

	//returns the Footage Preview of the Record
	std::string getFootagePreview() const { return footagePreview; }

	void setTitle(string title);
	void setLocation(string location);
	void setTimesAccessed(int timesaccesesd);
	void setFootagePreview(string footagepreview);
	void setTimeOfCreation(Record& record,string timeOfCreation);

	bool operator==(const Record& record);

	//returns a string with the Record
	std::string printRecord();
	std::string printTimesOfCreation();

	vector<string>tokenize(const string& stringToCheck, char separator);
	void resetRecord();
	
	friend ostream& operator<<(ostream& os, const Record& record);
	friend istream& operator>>(istream& in, Record& record);

	std::string toHTML();
	
};