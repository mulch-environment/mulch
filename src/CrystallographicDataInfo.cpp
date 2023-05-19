// RepresentationType.cpp

#include "CrystallographicDataInfo.h"
using namespace mulch;

CrystallographicDataInfo::CrystallographicDataInfo()
{

}

std::string CrystallographicDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystallographicDataInfo DEFAULT VALUES;";
	return query;
}

std::string CrystallographicDataInfo::updateQuery()
{
	return "";
}

/// ------------------ RETRIEVING STUFF -----------------------
CrystallographicDataInfo* CrystallographicDataInfo::crystallographicDataInfoByPrimaryId(int id, Database *db)
{
    return Cache<CrystallographicDataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}





