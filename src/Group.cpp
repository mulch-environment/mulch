// Group.cpp

#include "Group.h"
using namespace mulch;

Group::Group()
{

}

std::string Group::insertQuery()
{
	std::string query;
	query = "INSERT INTO Group DEFAULT VALUES;";
	return query;
}

std::string Group::updateQuery()
{
	std::string query;
	// query = "UPDATE Group SET fixed = 'blah' WHERE group_ID = 4;";

	return " ";
}

