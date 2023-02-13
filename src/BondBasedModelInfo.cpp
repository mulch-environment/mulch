// RepresentationType.cpp

#include "BondBasedModelInfo.h"
using namespace mulch;

BondBasedModelInfo::BondBasedModelInfo()
{

}

std::string BondBasedModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO BondBasedModelInfo DEFAULT VALUES;";
	return query;
}

std::string BondBasedModelInfo::updateQuery()
{
	return "";
}

std::string BondBasedModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT bondbased_model_id FROM BondBasedModelInfo";
	query += ";";

	return query;
}

