// RepresentationType.cpp

#include "DataNMRInfo.h"
#include "NMRQualityData.h"
#include "DebugLog.h"
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
	Utility::protectsql(query);
	return query;
}

std::string DataNMRInfo::updateQuery()
{
	std::string query;
	query = "UPDATE DataNMRInfo SET nmrqualitydata_id =";
	query += _nmrQualityData->primaryId();
	query += "WHERE data_nmr_info_id = ";
	query += std::to_string(primaryId());;
	query += ";";
	Utility::protectsql(query);
	return query;
}

// -----------------------------------------------------------------------------------------

void DataNMRInfo::updateDependenciesBefore(Database *db)
{
	_nmrQualityData->updateDatabase(db);
}

std::string DataNMRInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM DataNMRInfo WHERE data_nmr_info_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
DataNMRInfo* DataNMRInfo::dataNMRInfoByPrimaryId(int id, Database *db)
{
    return Cache<DataNMRInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void DataNMRInfo::retrieveDependencies(Result &res, Database *db)
{

	delete _nmrQualityData;
	_nmrQualityData = nullptr;
	
	std::string nmrQual_id = NMRQualityData::staticSqlIDName();
	std::cout << "res[nmrQual_id] = " + res[nmrQual_id] << std::endl;
	_nmrQualityData = NMRQualityData::nmrQualityDataByPrimaryId(std::stoi(res[nmrQual_id]), db);
}


void DataNMRInfo::fillInFromResults(const Result &res) 
{
	_comments = res.at("comments");
    // _nmrQualityData->getPidFromResults(res);
}

















