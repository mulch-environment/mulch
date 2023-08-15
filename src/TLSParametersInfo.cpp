// TLSParametersInfo.cpp

#include "TLSParametersInfo.h"
#include "DebugLog.h"
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

std::string TLSParametersInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM TLSParametersInfo WHERE tlsparameters_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
TLSParametersInfo* TLSParametersInfo::tlsByPrimaryId(int id, Database *db)
{
    return Cache<TLSParametersInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}






























