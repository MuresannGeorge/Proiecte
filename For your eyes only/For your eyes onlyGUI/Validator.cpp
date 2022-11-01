#include "Validator.h"
#include <string>

using namespace std;

void RecordValidation::validate(const Record& record)
{
	string errors = "";
	if (record.getTimesAccessed() < 0)
		errors += string("times accessed is a negative number\n");

	if (errors.size() > 0)
		throw Validator(errors);
}

std::string Validator::showException() const
{
	string msgException;
	msgException += string("Error!: \n");
	msgException += this->messageException;

	return msgException;
}

std::string RepositoryException::showException() const
{
	string msgException;
	msgException += string("Error!: \n");
	msgException += this->messageException;

	return msgException;
}

std::string BusinessException::showException() const
{
	string msgException;
	msgException += string("Error!: \n");
	msgException += this->messageException;

	return msgException;
}

std::string UIException::showException() const
{
	string msgException;
	msgException += string("Error!: \n");
	msgException += this->messageException;

	return msgException;
}