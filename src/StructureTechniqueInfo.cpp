// StructureTechniqueInfo.cpp

#include "StructureTechniqueInfo.h"
#include "CrystallographicInfo.h"
#include "NMRInfo.h"
#include "CryoEMInfo.h"
using namespace mulch;

StructureTechniqueInfo::StructureTechniqueInfo()
{
	_crystallographicInfo = new CrystallographicInfo();
	_nmrInfo = new NMRInfo();
	_cryoEMInfo = new CryoEMInfo();
}

std::string StructureTechniqueInfo::insertQuery()
{
	std::string query;
	query = "INSERT INTO StructureTechniqueInfo DEFAULT VALUES;";
	return query;
}

std::string StructureTechniqueInfo::updateQuery()
{
	std::string query;
	// query = "UPDATE StructureTechniqueInfo SET cryoem_info_ID = 1 WHERE structure_technique_ID = 3";
	// query += ";";
	// query = "UPDATE RepresentationType SET atomic_model_ID= 1 WHERE representation_type_ID = 4";
	// query += ";";
	// return query;
	return "";
}

void StructureTechniqueInfo::updateDependencies(Database *db)
{
	_crystallographicInfo->updateDatabase(db);
	_nmrInfo->updateDatabase(db);
	_cryoEMInfo->updateDatabase(db);	
}

