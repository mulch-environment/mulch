// RepresentationType.cpp

#include "CryoEMDataInfo.h"
#include "DebugLog.h"
using namespace mulch;


CryoEMDataInfo::CryoEMDataInfo()
{

}

std::string CryoEMDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMDataInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CryoEMDataInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
CryoEMDataInfo* CryoEMDataInfo::cryoEMDataInfoByPrimaryId(int id, Database *db)
{
    return Cache<CryoEMDataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

