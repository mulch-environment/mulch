// StructureTechniqueInfo.cpp

#include "Crystal.h"
#include "DataCrystallographicInfo.h"
using namespace mulch;

Crystal::Crystal()
{
	_dataCrystallographicInfo = new DataCrystallographicInfo();

}

std::string Crystal::insertQuery()
{
	std::string query;
	query = "INSERT INTO Crystal DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string Crystal::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string Crystal::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

std::string Crystal::selectPidQuery()
{
	std::string query;
	query = "SELECT Crystal_id FROM Crystal";
	query += ";";
	Utility::protectsql(query);
	return query;
}

void Crystal::updateDependenciesBefore(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_dataCrystallographicInfo->updateDatabase(db);
}


/// ------------------ RETRIEVING STUFF -----------------------
Crystal* Crystal::crystalByPrimaryId(int id, Database *db)
{
    return Cache<Crystal>::cacheByPrimaryId(id, db); // Use the template function from the cache
}
