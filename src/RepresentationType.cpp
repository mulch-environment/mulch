// RepresentationType.cpp

#include "RepresentationType.h"
#include "AtomicModelInfo.h"
#include "BondBasedModelInfo.h"
#include "CoarseGrainingModelInfo.h"
#include "EnsembleRefineInfo.h"
using namespace mulch;

RepresentationType::RepresentationType()
{
	_atomicModelInfo = new AtomicModelInfo();
	_bondBasedModelInfo = new BondBasedModelInfo();
	_coarseGrainingModelInfo = new CoarseGrainingModelInfo();
	_ensembleRefineInfo = new EnsembleRefineInfo();	
}

std::string RepresentationType::insertQuery()
{
	std::string query;
	query = "INSERT INTO RepresentationType DEFAULT VALUES;";
	return query;
}

std::string RepresentationType::updateQuery()
{
	std::string query;
	query = "UPDATE RepresentationType SET bondbased_model_ID = 1 WHERE representation_type_ID = 4";
	query += ";";
	return query;
	// return "";
}

void RepresentationType::updateDependencies(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	_atomicModelInfo->updateDatabase(db);
	_bondBasedModelInfo->updateDatabase(db);
	_coarseGrainingModelInfo->updateDatabase(db);
	_ensembleRefineInfo->updateDatabase(db);
}

