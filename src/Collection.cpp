// Collection.cpp

#include "Collection.h"
using namespace mulch;

Collection::Collection()
{

}

std::string Collection::insertQuery()
{
	std::string query;
	query = "INSERT INTO Collection DEFAULT VALUES;";
	return query;
}

std::string Collection::updateQuery()
{
	std::string query;
	query = "UPDATE Collection SET fixed = 'blah' WHERE Collection_ID = 4;";

	return query;
}

std::string Collection::selectQuery()
{
	std::string query;
	query = "SELECT collection_id FROM Collection";
	query += ";";

	return query;
}

