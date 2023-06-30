// StructureTechniqueInfo.cpp

#include "CryoEMQualityData.h"
#include "DebugLog.h"
using namespace mulch;

CryoEMQualityData::CryoEMQualityData()
{

}

std::string CryoEMQualityData::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMQualityData DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CryoEMQualityData::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
CryoEMQualityData* CryoEMQualityData::cryoEMQualityDataByPrimaryId(int id, Database *db)
{
    return Cache<CryoEMQualityData>::cacheByPrimaryId(id, db); // Use the template function from the cache
}