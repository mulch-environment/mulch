// RepresentationType.cpp

#include "DataNMRInfo.h"
#include "NMRQualityData.h"
using namespace mulch;

DataNMRInfo::DataNMRInfo()
{
	_nmrQualityData = new NMRQualityData();
}

std::string DataNMRInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataNMRInfo (nmrqualitydata_id) VALUES" ;
	query += "(";
	query += std::to_string(_nmrQualityData ->primaryId());
	query += ");";

	return query;
}

std::string DataNMRInfo::updateQuery()
{
	return "";
}

void DataNMRInfo::updateDependencies(Database *db)
{
	_nmrQualityData->updateDatabase(db);
}

std::string DataNMRInfo::selectQuery()
{
	std::string query;
	query = "SELECT data_nmr_info_id FROM DataNMRInfo";
	query += ";";

	return query;
}

