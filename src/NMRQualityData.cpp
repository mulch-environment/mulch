// NMRQualityData.cpp

#include "NMRQualityData.h"
#include "DebugLog.h"
using namespace mulch;

NMRQualityData::NMRQualityData()
{

}

std::string NMRQualityData::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRQualityData DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string NMRQualityData::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

std::string NMRQualityData::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM NMRQualityData WHERE nmrqualitydata_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
NMRQualityData* NMRQualityData::nmrQualityDataByPrimaryId(int id, Database *db)
{
    return Cache<NMRQualityData>::cacheByPrimaryId(id, db); // Use the template function from the cache
}














