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
	return query;
}

std::string TLSParametersInfo::updateQuery()
{
	return "";
}

std::string TLSParametersInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM TLSParametersInfo";
	query += ";";

	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<TLSParametersInfo*, int> TLSParametersInfo::tlsByPrimaryId(int id, Database *db)
{
    return Cache<TLSParametersInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}






























