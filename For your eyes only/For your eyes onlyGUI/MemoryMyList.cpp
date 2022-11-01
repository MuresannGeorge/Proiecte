#include "MemoryMyList.h"

void MemoryMyList::add(const Record& record)
{
	for (auto savedRecord : records)
	{
		if (savedRecord == record)
			throw RepositoryException("Record already saved!\n");
	}

	records.push_back(record);
}

vector<Record> MemoryMyList::getAll()
{
	return records;
}
