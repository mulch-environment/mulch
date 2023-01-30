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
	return "";
}

