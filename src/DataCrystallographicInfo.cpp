// RepresentationType.cpp
#include <iostream>
#include "DataCrystallographicInfo.h"
#include "CrystalQualityData.h"
#include "Utility.h"
#include "MulchExceptions.h"
using namespace mulch;

DataCrystallographicInfo::DataCrystallographicInfo()
{
	_crystalQualityData = new CrystalQualityData(); 
}

std::string DataCrystallographicInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO DataCrystallographicInfo DEFAULT VALUES;";
	return query;
}

std::string DataCrystallographicInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE DataCrystallographicInfo SET file_name = ";
	query += "'";
	query += DataCrystallographicInfo::getFileName();
	query += "'";
	query += " WHERE data_crystallographic_info_id = ";		
	query += std::to_string(DataCrystallographicInfo::primaryId());
	return query;
}

std::string DataCrystallographicInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT data_crystallographic_info_id FROM DataCrystallographicInfo";
	query += ";";

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
	std::cout<< _fileData <<std::endl;
};



