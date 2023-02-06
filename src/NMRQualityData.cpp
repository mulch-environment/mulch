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

std::string NMRQualityData::selectQuery()
{
	std::string query;
	query = "SELECT nmrqualitydata_id FROM NMRQualityData";
	query += ";";

	return query;
}
