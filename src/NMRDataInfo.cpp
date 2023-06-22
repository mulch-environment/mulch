// RepresentationType.cpp

#include "NMRDataInfo.h"
using namespace mulch;

NMRDataInfo::NMRDataInfo()
{

}

std::string NMRDataInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRDataInfo DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string NMRDataInfo::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string NMRDataInfo::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

/// ------------------ RETRIEVING STUFF -----------------------
NMRDataInfo* NMRDataInfo::nmrDataInfoByPrimaryId(int id, Database *db)
{
    return Cache<NMRDataInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}







