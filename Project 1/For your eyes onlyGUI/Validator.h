#pragma once

#include <string>
#include "Recording.h"
#include "Records.h"
#include "Business.h"

class RecordValidation
{
public:
	static void validate(const Record& record);
};

class Exceptions
{
public:
	virtual std::string showException() const = 0;
};

class Validator :public Exceptions
{
private:
	std::string messageException;
public:
	Validator(std::string _messageException) { this->messageException = _messageException; }
	std::string showException() const;
};

class RepositoryException : public Exceptions
{
private:
	std::string messageException;
public:
	RepositoryException(std::string _messageException) { this->messageException = _messageException; }
	std::string showException() const;
};

class BusinessException : public Exceptions
{
private:
	std::string messageException;
public:
	BusinessException(std::string _messageException) { this->messageException = _messageException; }
	std::string showException() const;
};

class UIException : public Exceptions
{
private:
	std::string messageException;
public:
	UIException(std::string _messageException) { this->messageException = _messageException; }
	std::string showException() const;
};