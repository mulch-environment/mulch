// RepresentationType.cpp

#include "CrystallographicDataInfo.h"
#include "DebugLog.h"
using namespace mulch;

CrystallographicDataInfo::CrystallographicDataInfo()
{

}

std::string CrystallographicDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystallographicDataInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CrystallographicDataInfo::updateQuery()
{
	std::string query;
	query = ""
	Utility::protectsql(query);
	return query;
}



/// ------------------ RETRIEVING STUFF -----------------------
CrystallographicDataInfo* CrystallographicDataInfo::crystallographicDataInfoByPrimaryId(int id, Database *db)
{
    return Cache<CrystallographicDataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}





