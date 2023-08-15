// RepresentationType.cpp
#include <iostream>
#include "DataCrystallographicInfo.h"
#include "CrystalQualityData.h"
#include "Utility.h"
#include "MulchExceptions.h"
#include "DebugLog.h"
using namespace mulch;


DataCrystallographicInfo::DataCrystallographicInfo()
{
	_crystalQualityData = new CrystalQualityData(); 
}

std::string DataCrystallographicInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataCrystallographicInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string DataCrystallographicInfo::updateQuery()
{
	std::string query;
	std::string fileName = DataCrystallographicInfo::getFileName();
	Utility::protectParameter(fileName);
	query =	"UPDATE DataCrystallographicInfo SET file_name = '";
	query += fileName;
	query += "' WHERE data_crystallographic_info_id = ";		
	query += std::to_string(DataCrystallographicInfo::primaryId());
	
	return query;
}


std::string DataCrystallographicInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM DataCrystallographicInfo";
	query += ";";
	Utility::protectsql(query);
	return query;
}

void DataCrystallographicInfo::updateDependenciesBefore(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_crystalQualityData->updateDatabase(db);
}


void DataCrystallographicInfo::setFileName(std::string fileName)
{	
	MulchExceptions::FileNameIsNone(_fileData);
	_fileData = fileName;
	debugLog << _fileData;
};

/// ------------------ RETRIEVING STUFF -----------------------
DataCrystallographicInfo* DataCrystallographicInfo::dataCrystallographicInfoByPrimaryId(int id, Database *db)
{
    return Cache<DataCrystallographicInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void DataCrystallographicInfo::retrieveDependencies(Result &res, Database *db)
{

	delete _crystalQualityData;
	_crystalQualityData = nullptr;
	
	std::string crysQual_id = CrystalQualityData::staticSqlIDName();
	std::cout << "res[crysQual_id] = " + res[crysQual_id] << std::endl;
	CrystalQualityData* cryQual = CrystalQualityData::crystQualDataByPrimaryId(std::stoi(res[crysQual_id]), db);
	_crystalQualityData = cryQual;

}

void DataCrystallographicInfo::fillInFromResults(const Result &res) 
{
    _crystalQualityData->getPidFromResults(res);
}

