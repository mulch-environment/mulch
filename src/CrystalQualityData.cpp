// CrystalQualityData.cpp

#include "CrystalQualityData.h"
using namespace mulch;

CrystalQualityData::CrystalQualityData()
{
 
}

std::string CrystalQualityData::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystalQualityData DEFAULT VALUES;";
	return query;
}

std::string CrystalQualityData::updateQuery()
{
	std::string query;
	query = "";

	return query;
}

std::string CrystalQualityData::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CrystalQualityData";
	query += ";";

	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
CrystalQualityData* CrystalQualityData::crystQualDataByPrimaryId(int id, Database *db)
{
    return Cache<CrystalQualityData>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

 

