// StructureTechniqueInfo.cpp

#include "NMRInfo.h"
using namespace mulch;

NMRInfo::NMRInfo()
{

}

std::string NMRInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO NMRInfo DEFAULT VALUES;";
	return query;
}

std::string NMRInfo::updateQuery()
{
	return "";
}

std::string NMRInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM NMRInfo WHERE nmr_info_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}


/// ------------------ RETRIEVING STUFF -----------------------
NMRInfo* NMRInfo::nmrByPrimaryId(int id, Database *db)
{
    return Cache<NMRInfo>::cacheByPrimaryId(id, db); // Use the template function from the cache
}














