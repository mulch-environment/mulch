// RepresentationType.cpp

#include "DataCrystallographicInfo.h"
#include "CrystalQualityData.h"
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
	query = "";

	return "";
}

void DataCrystallographicInfo::updateDependencies(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_crystalQualityData->updateDatabase(db);
}



