// RepresentationType.cpp

#include "DataCryoEMInfo.h"
using namespace mulch;

DataCryoEMInfo::DataCryoEMInfo()
{

}

std::string DataCryoEMInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataCryoEMInfo DEFAULT VALUES;";
	return query;
}

std::string DataCryoEMInfo::updateQuery()
{
	return "";
}

std::string DataCryoEMInfo::selectQuery()
{
	std::string query;
	query = "SELECT data_cryoem_info_id FROM DataCryoEMInfo";
	query += ";";

	return query;
}