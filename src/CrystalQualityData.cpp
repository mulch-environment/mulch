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

std::string CrystalQualityData::selectQuery()
{
	std::string query;
	query = "SELECT crystalqualitydata_id FROM CrystalQualityData";
	query += ";";

	return query;
}


