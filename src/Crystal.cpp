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
	return query;
}

std::string Crystal::updateQuery()
{
	std::string query;
	query = "UPDATE Crystal SET comments = 'blah' WHERE crystal_ID = 4";
	query += ";";
	// query += "UPDATE AtomicModelInfo SET tlsparameters_id = 2 WHERE atomic_model_id = 2";
	// query += ";";
	return query;
}

std::string Crystal::selectPidQuery()
{
	std::string query;
	query = "SELECT Crystal_id FROM Crystal";
	query += ";";

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
std::pair<Crystal*, int> Crystal::crystalByPrimaryId(int id, Database *db)
{
    return Cache<Crystal>::cacheByPrimaryId(id, db); // Use the template function from the cache
}
