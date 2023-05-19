// StructureTechniqueInfo.cpp

#include "CrystallographicInfo.h"
using namespace mulch;

CrystallographicInfo::CrystallographicInfo()
{

}

std::string CrystallographicInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystallographicInfo DEFAULT VALUES;";
	return query;
}

std::string CrystallographicInfo::updateQuery()
{
	return "";
}

std::string CrystallographicInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CrystallographicInfo WHERE crystallographic_info_id =";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
CrystallographicInfo* CrystallographicInfo::crystallographicInfoByPrimaryId(int id, Database *db)
{
    return Cache<CrystallographicInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}





