#pragma once
#include "Recording.h"
#include "Records.h"
#include <vector>
#include "RepositoryFromTxt.h"
#include "Repository.h"
#include "MemoryMyList.h"
#include "MyList.h"

class Business
{
private:
	Repository& repository;
	MyList* savedRecords;
	std::string myListLocation;

public:
	Business() = default;
	Business(Repository& newRepository) :repository{ newRepository }{}
	//Business(Repository& newRepository) :repository{ newRepository } {}
	//~Business() { };

	//Repository& getRepository() const { return repository; }

	//Get the list of record from repository
	vector<Record> getAllListOfRecords() const;

	/*
	Checks if the curent ID exist in repository
	input - string title
	output -
*/
	int isExisting(const std::string& title);

	/*
	Adds an new record
	input - Record recording, the new recording that will be added
	output - 1 if the title doesnt exist and the record goes to repository
		- 0 if the Record already exist and the program throws an exception
*/
	int addNewRecording(const std::string& title, const std::string location, int month,int day,int year, int timesAccessed, const std::string footagePreview);

	/*
	Delete an existing Record
	input - string title, the ID of the record to be deleted
	output - 1 if the title doesnt exist and the record goes to repository
		- 0 if the Record already exist and the program throws an exception
*/
	int deleteExistingRecording(const std::string title);

	/*
	Adds an new record
	input - string ExistingTitle, the ID of the Record that will be updated
		- string location
		-string timeOfCreation
		-int timesAccessed
		-string footagePreview
	output - 1 if the title doesnt exist and the record goes to repository
		- 0 if the Record already exist and the program throws an exception
*/
	int updateExistingRecording(const std::string& ExistingTitle, const std::string location, int month, int day, int year, int timesAccessed, const std::string footagePreview);

	Date getDate(int month, int day, int year);

	vector<Record> getFilteredRecords(const std::string& location, int timesAccessed);

	Record next();

	void save(std::string title);
	vector<Record> getAllSavedRecords();
	//int getSavedSize();

	void fileLocation(std::string path);
	void mylistFileLocation(std::string path);

	void openFile();

};