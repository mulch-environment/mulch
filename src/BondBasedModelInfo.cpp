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
	Utility::protectsql(query);
	return query;

}

std::string BondBasedModelInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string BondBasedModelInfo::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

std::string BondBasedModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM BondBasedModelInfo";
	query += ";";
	Utility::protectsql(query);
	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
BondBasedModelInfo* BondBasedModelInfo::bondModelByPrimaryId(int id, Database *db)
{
    return Cache<BondBasedModelInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}













