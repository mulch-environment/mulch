// StructureTechniqueInfo.cpp

#include "CryoEMInfo.h"
using namespace mulch;

CryoEMInfo::CryoEMInfo()
{

}

std::string CryoEMInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO CryoEMInfo DEFAULT VALUES;";
	return query;
}

std::string CryoEMInfo::updateQuery()
{
	return "";
}

std::string CryoEMInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CryoEMInfo WHERE cryoem_info_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);

	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------

CryoEMInfo* CryoEMInfo::cryoByPrimaryId(int id, Database *db)
{
	CryoEMInfo *cryoEMInfo = new CryoEMInfo();
	cryoEMInfo->retrieveExisting(id, db);
	return cryoEMInfo;
}