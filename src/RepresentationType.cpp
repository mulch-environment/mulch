// RepresentationType.cpp
#include <iostream>
#include "MulchExceptions.h"
#include "RepresentationType.h"
#include "AtomicModelInfo.h"
#include "BondBasedModelInfo.h"
#include "CoarseGrainingModelInfo.h"
#include "EnsembleRefineInfo.h"
#include "Utility.h"
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
	Utility::protectsql(query);
	return query;
}

std::string RepresentationType::updateQuery()
{
	std::string query;
	query = "UPDATE RepresentationType SET bondbased_model_ID = 1 WHERE representation_type_ID = 3";
	query += ";";
	// query = "UPDATE RepresentationType SET atomic_model_ID= 1 WHERE representation_type_ID = 4";
	// query += ";";
	return query;
	// return "";
}

std::string RepresentationType::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM RepresentationType WHERE representation_type_ID = ";
	query += std::to_string(primaryId());
	query += ";";

	return query;
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

void RepresentationType::setRepType(RepresentationEnum rep)
{
	MulchExceptions::RepTypeIsNone(_type);
	_type = rep;
	if (_type == Atomic)
	{
		_atomicModelInfo = new AtomicModelInfo();
	}
	else if (_type == BondBased)
	{
		_bondBasedModelInfo = new BondBasedModelInfo();
	}
	else if (_type == CG)
	{
		_coarseGrainingModelInfo = new CoarseGrainingModelInfo();
	}
	else if (_type == Ensemble)
	{
		_ensembleRefineInfo = new EnsembleRefineInfo();
	}

};

void RepresentationType::setFileName(std::string pdbName)
{
	MulchExceptions::FileNameIsNone(_pdbCode);
	std::string _pdbCode = pdbName;

};