// RepresentationType.cpp

#include "Data.h"'
// #include "NMRDataInfo.h"
// #include "CrystallographicDataInfo.h"
// #include "CryoEMDataInfo.h"
using namespace mulch;

DataInfo::DataInfo()
{
	_nmrDataInfo = new NMRDataInfo();
	_crystallographicDataInfo = CrystallographicDataInfo();
	_cryoEMDataInfo = CryoEMDataInfo();
}

std::string DataInfo::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data (nmrdatainfo_ID, crystallographic_data_info_ID) VALUES";
	query += "(";
	query += std::to_string(_representationType->primaryId());
	query += ",";
	query += std::to_string(_structureTechniqueInfo->primaryId());
	query += ");";
	Utility::protectsql(query);
	return query;
}

std::string DataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO Data DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string DataInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string DataInfo::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

void DataInfo::updateDependencies(Database *db)
{
	// send that representationType to the database
	_nmrDataInfo->updateDatabase(db);
	_crystallographicDataInfo->updateDatabase(db);
	_cryoEMDataInfo->updateDatabase(db);
}


DataInfo DataInfo::dataInfoFromResult(const Result &res)
{
	Model exportedDataInfo;
	int pid = atoi(res.at("dataInfo_id").c_str());
	exportedDataInfo.setPrimaryId(pid);
	return exportedDataInfo;
}


/// ------------------ RETRIEVING STUFF -----------------------
DataInfo* DataInfo::dataInfoByPrimaryId(int id, Database *db)
{
    return Cache<DataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}











