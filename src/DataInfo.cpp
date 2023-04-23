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

std::string Model::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Data (nmrdatainfo_ID, crystallographic_data_info_ID) VALUES";
	query += "(";
	query += std::to_string(_representationType->primaryId());
	query += ",";
	query += std::to_string(_structureTechniqueInfo->primaryId());
	query += ");";

	return query;
}

std::string Data::insertQuery()
{
	std::string query;
	query = "INSERT INTO Data DEFAULT VALUES;";
	return query;
}

std::string Data::updateQuery()
{
	query = "UPDATE Data SET comments = 'blahblah' WHERE Data_ID = 5";
	query += std::to_string(primaryId());
	query += ";";
	return "";
}

void Data::updateDependencies(Database *db)
{
	// send that representationType to the database
	_nmrDataInfo->updateDatabase(db);
	_crystallographicDataInfo->updateDatabase(db);
	_cryoEMDataInfo->updateDatabase(db);
}


DataInfo Data::dataInfoFromResult(const Result &res)
{
	Model exportedDataInfo;
	int pid = atoi(res.at("dataInfo_id").c_str());
	exportedDataInfo.setPrimaryId(pid);
	return exportedDataInfo;
}
