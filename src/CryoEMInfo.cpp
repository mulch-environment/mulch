// StructureTechniqueInfo.cpp

#include "CryoEMInfo.h"
#include "DebugLog.h"
using namespace mulch;


CryoEMInfo::CryoEMInfo()
{

}

std::string CryoEMInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CryoEMInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}


std::string CryoEMInfo::selectPidQuery()
{
	std::string query;

	query = "SELECT * FROM CryoEMInfo ";
	query += ";";
	Utility::protectsql(query);
	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
CryoEMInfo* CryoEMInfo::cryoByPrimaryId(int id, Database *db)
{
    return Cache<CryoEMInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

