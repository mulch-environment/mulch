// RepresentationType.cpp

#include "RepresentationType.h"
using namespace mulch;

RepresentationType::RepresentationType()
{

}

std::string RepresentationType::insertQuery()
{
	std::string query;
	query = "INSERT INTO RepresentationType DEFAULT VALUES;";
	return query;
}

std::string RepresentationType::updateQuery()
{
	return "";
}

