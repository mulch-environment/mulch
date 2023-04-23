// NMRQualityData.cpp

#include "NMRQualityData.h"
using namespace mulch;

NMRQualityData::NMRQualityData()
{

}

std::string NMRQualityData::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRQualityData DEFAULT VALUES;";
	return query;
}

std::string NMRQualityData::updateQuery()
{
	// std::string query;
	// query = "UPDATE RfactrosInfo SET Rfree = 0.2 WHERE rfactors_id = 6";
	// query += ";";
	return " ";
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
NMRQualityData* NMRQualityData::NMRQualDataByPrimaryId(int id, Database *db)
{
	NMRQualityData *nmrQualityData = new NMRQualityData();
	nmrQualityData->retrieveExisting(id, db);
	return nmrQualityData;
}
