// RepresentationType.cpp

#include "DataCryoEMInfo.h"
#include "DebugLog.h"
using namespace mulch;

DataCryoEMInfo::DataCryoEMInfo()
{

}

std::string DataCryoEMInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataCryoEMInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string DataCryoEMInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}



std::string DataCryoEMInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT data_cryoem_info_id FROM DataCryoEMInfo";
	query += ";";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
DataCryoEMInfo* DataCryoEMInfo::dataCryoEMInfoByPrimaryId(int id, Database *db)
{
    return Cache<DataCryoEMInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}








