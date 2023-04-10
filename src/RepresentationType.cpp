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
	_atomicModelInfo = nullptr;
	_bondBasedModelInfo = nullptr;
	_coarseGrainingModelInfo = nullptr;
	_ensembleRefineInfo = nullptr;	
}

std::string RepresentationType::insertQuery()
{
	std::string query;
	query = "INSERT INTO RepresentationType DEFAULT VALUES;";
	Utility::protectsql(query);
	return query;
}

std::string RepresentationType::updateRepType(std::string repTypeIdName, int repTypeIdValue)
{
	std::string query;
	query = "UPDATE RepresentationType SET ";
	query += repTypeIdName; 
	query += " = ";
	query += std::to_string(repTypeIdValue); 
	query += " WHERE representation_type_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

std::string RepresentationType::updateQuery()
{
	std::string query;
	std::string repTypeIdName;
	int repTypeIdValue;

	if (_type == Atomic)
	{
		repTypeIdName = "atomic_model_id";
		repTypeIdValue = _atomicModelInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		std::cout << query << std::endl;
		return query;
	}
	else if (_type == BondBased)
	{
		repTypeIdName = "bondbased_model_id";
		repTypeIdValue = _bondBasedModelInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		std::cout << query << std::endl;
		return query;
	}
	else if (_type == CG)
	{
		repTypeIdName = "coarsegraining_model_id";
		repTypeIdValue = _coarseGrainingModelInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		std::cout << query << std::endl;
		return query;
		
	}
		else if (_type == Ensemble)
	{
		repTypeIdName = "ensemble_refine_id";
		repTypeIdValue = _ensembleRefineInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		std::cout << query << std::endl;
		return query;
	}
	else
	{
		throw std::runtime_error("Can't update RepresentationType: no representation type");
	}

}



std::string RepresentationType::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM RepresentationType WHERE representation_type_ID = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}


void RepresentationType::updateDependenciesBefore(Database *db)
{
	/* Foreign keys (FK): if a column is assigned a FK, each row of that column 
	MUST contain a value that exists in the foreigh column it references.
	**/
	if (_atomicModelInfo != nullptr)
	{
		std::cout << "Updating dependencies for RepresentationType->AtomicModelInfo \n" << std::endl;
		_atomicModelInfo->updateDatabase(db);
	}
	else if (_bondBasedModelInfo != nullptr)
	{
		std::cout << "Updating dependencies for RepresentationType->BondBasedModelInfo \n" << std::endl;
		_bondBasedModelInfo->updateDatabase(db);
	}
	else if (_coarseGrainingModelInfo != nullptr)
	{
		std::cout << "Updating dependencies for RepresentationType->CoarseGrainingModelInfo \n" << std::endl;
		_coarseGrainingModelInfo->updateDatabase(db);
	}
	else if (_ensembleRefineInfo != nullptr)
	{
		std::cout << "Updating dependencies for RepresentationType->EnsembleRefineInfo \n" << std::endl;
		_ensembleRefineInfo->updateDatabase(db);
	}
	else
	{
		throw std::runtime_error("Can't update dependencies for RepresentationType: no representation type");
	}
}

void RepresentationType::setRepType(RepresentationEnum rep)
{
	MulchExceptions::RepTypeIsNone(_type);
	_type = rep;
	std::cout<<_type<<std::endl;
	if (_type == Atomic)
	{
		std::cout<<"New instance for Atomistic model type"<<std::endl;
		_atomicModelInfo = new AtomicModelInfo();
	}
	else if (_type == BondBased)
	{
		std::cout<<"New instance for Bond-based model type"<<std::endl;
		_bondBasedModelInfo = new BondBasedModelInfo();
	}
	else if (_type == CG)
	{
		std::cout<<"New instance for CG model type"<<std::endl;
		_coarseGrainingModelInfo = new CoarseGrainingModelInfo();
	}
	else if (_type == Ensemble)
	{
		std::cout<<"New instance for Ensemble model type"<<std::endl;
		_ensembleRefineInfo = new EnsembleRefineInfo();
	}

};


void RepresentationType::setFileName(std::string pdbName)
{	
	if  (_atomicModelInfo!=nullptr)
	{
		_atomicModelInfo->setFileName(pdbName);
	}
}

RepresentationType* RepresentationType::representationTypeByPrimaryId(int id, Database *db)
{
	RepresentationType *representationType = new RepresentationType();
	representationType->retrieveExisting(id, db);
}



// ~RepresentationType() {
//     if (_atomicModelInfo) {
//         delete _atomicModelInfo;
//     }
//     if (_bondBasedModelInfo) {
//         delete _bondBasedModelInfo;
//     }
//     if (_coarseGrainingModelInfo) {
//         delete _coarseGrainingModelInfo;
//     }
//     if (_ensembleRefineInfo) {
//         delete _ensembleRefineInfo;
//     }
// }


