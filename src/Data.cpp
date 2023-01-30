// RepresentationType.cpp

#include "Data.h"
#include "DataNMRInfo.h"
#include "DataCrystallographicInfo.h"
#include "DataCryoEMInfo.h"
using namespace mulch;

Data::Data()
{
	_dataNMRInfo = new DataNMRInfo();
	_dataCrystallographicDataInfo = new DataCrystallographicInfo();
	_dataCryoEMInfo = new DataCryoEMInfo();
}

std::string Data::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data (data_nmr_info_id, data_crystallographic_info_id) VALUES";
	query += "(";
	query += std::to_string(_dataNMRInfo->primaryId());
	query += ",";
	query += std::to_string(_dataCrystallographicDataInfo->primaryId());
	query += ");";

	return query;
}

std::string Data::updateQuery()
{
	std::string query;
	query = "UPDATE Data SET comments = 'blahblah' WHERE Data_ID = 5";
	query += std::to_string(primaryId());
	query += ";";
	return query;
}

void Data::updateDependencies(Database *db)
{
	// send that representationType to the database
	_dataNMRInfo->updateDatabase(db);
	_dataCrystallographicDataInfo->updateDatabase(db);
	_dataCryoEMInfo->updateDatabase(db);
}


Data Data::dataFromResult(const Result &res)
{
	Data exportedDataInfo;
	int pid = atoi(res.at("DataInfo_id").c_str());
	exportedDataInfo.setPrimaryId(pid);
	return exportedDataInfo;
}
