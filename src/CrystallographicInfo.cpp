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
	Utility::protectsql(query);
	return query;
}

std::string CrystallographicInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string CrystallographicInfo::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

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





