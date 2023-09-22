// StructureTechniqueInfo.cpp

#include "CrystallographicInfo.h"
#include "DebugLog.h"
using namespace mulch;


CrystallographicInfo::CrystallographicInfo()
{

}

std::string CrystallographicInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CrystallographicInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string CrystallographicInfo::updateQuery()
{
	std::string query;
	query =	"UPDATE CrystallographicInfo SET comments = '";
	query += _comments;
	query += "' WHERE crystallographic_info_id = (";
	query += std::to_string(primaryId());
	query += ");";
	return query;
}



std::string CrystallographicInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CrystallographicInfo WHERE crystallographic_info_id =";
	query += std::to_string(primaryId());
	query += ";";
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
CrystallographicInfo* CrystallographicInfo::crystallographicInfoByPrimaryId(int id, Database *db)
{
    return Cache<CrystallographicInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}





