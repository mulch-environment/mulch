// RfactrosInfo.cpp

#include "RfactrosInfo.h"
#include "ModelDataPair.h"
using namespace mulch;

RfactrosInfo::RfactrosInfo()
{
	_modelDataPair = new ModelDataPair();

}

std::string RfactrosInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO RfactrosInfo DEFAULT VALUES;";
	return query;
}

std::string RfactrosInfo::updateQuery()
{
	std::string query;
	query = "UPDATE RfactrosInfo SET Rfree = 0.2 WHERE rfactors_id = 6";
	query += ";";
	return query;
}

void RfactrosInfo::updateDependencies(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_modelDataPair->updateDatabase(db);
}