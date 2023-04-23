// RepresentationType.cpp

#include "BondBasedModelInfo.h"
using namespace mulch;

BondBasedModelInfo::BondBasedModelInfo()
{

}

std::string BondBasedModelInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO BondBasedModelInfo DEFAULT VALUES;";
	return query;
}

std::string BondBasedModelInfo::updateQuery()
{
	return "";
}

std::string BondBasedModelInfo::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM BondBasedModelInfo";
	query += ";";

	return query;
}

/// ------------------ RETRIEVING STUFF -----------------------
BondBasedModelInfo* BondBasedModelInfo::bondModelByPrimaryId(int id, Database *db)
{
	BondBasedModelInfo *bondBasedModelInfo = new BondBasedModelInfo();
	bondBasedModelInfo->retrieveExisting(id, db);
	return bondBasedModelInfo;
}


