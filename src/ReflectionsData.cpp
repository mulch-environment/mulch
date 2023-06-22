// StructureTechniqueInfo.cpp

#include "ReflectionsData.h"
#include "DataCrystallographicInfo.h"
using namespace mulch;

ReflectionsData::ReflectionsData()
{
	_dataCrystallographicInfo = new DataCrystallographicInfo();

}

std::string ReflectionsData::insertQuery()
{
	std::string query;
	query = "INSERT INTO ReflectionsData DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string ReflectionsData::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string ReflectionsData::updateQueryTest(Database *db)
{
    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

std::string ReflectionsData::selectPidQuery()
{
	std::string query;
	query = "SELECT reflectionsdata_id FROM ReflectionsData";
	query += ";";
	Utility::protectsql(query);
	return query;
}

void ReflectionsData::updateDependenciesBefore(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_dataCrystallographicInfo->updateDatabase(db);
}


/// ------------------ RETRIEVING STUFF -----------------------
ReflectionsData* ReflectionsData::reflectDataByPrimaryId(int id, Database *db)
{
    return Cache<ReflectionsData>::cacheByPrimaryId(id, db); // Use the template function from the cache
}






















