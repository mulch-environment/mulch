// TLSParametersInfo.cpp

#include "TLSParametersInfo.h"
using namespace mulch;

TLSParametersInfo::TLSParametersInfo()
{

}

std::string TLSParametersInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO TLSParametersInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string TLSParametersInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string TLSParametersInfo::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

std::string TLSParametersInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM TLSParametersInfo";
	query += ";";
	Utility::protectsql(query);
	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
TLSParametersInfo* TLSParametersInfo::tlsByPrimaryId(int id, Database *db)
{
    return Cache<TLSParametersInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}






























