// RepresentationType.cpp
#include "MulchExceptions.h"
#include "RepresentationType.h"
#include "AtomicModelInfo.h"
#include "BondBasedModelInfo.h"
#include "CoarseGrainingModelInfo.h"
#include "EnsembleRefineInfo.h"
#include "Utility.h"
#include "DebugLog.h"


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
		debugLog << query;
		Utility::protectsql(query);
		return query;
	}
	else if (_type == BondBased)
	{
		repTypeIdName = "bondbased_model_id";
		repTypeIdValue = _bondBasedModelInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		debugLog << query;
		Utility::protectsql(query);
		return query;
	}
	else if (_type == CG)
	{
		repTypeIdName = "coarsegraining_model_id";
		repTypeIdValue = _coarseGrainingModelInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		debugLog << query;
		Utility::protectsql(query);
		return query;
		
	}
		else if (_type == Ensemble)
	{
		repTypeIdName = "ensemble_refine_id";
		repTypeIdValue = _ensembleRefineInfo->primaryId();
		query = updateRepType(repTypeIdName, repTypeIdValue);
		debugLog << query;
		Utility::protectsql(query);
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

		debugLog << "Updating dependencies for RepresentationType->AtomicModelInfo";
		_atomicModelInfo->updateDatabase(db);
	}
	else if (_bondBasedModelInfo != nullptr)
	{
		debugLog << "Updating dependencies for RepresentationType->BondBasedModelInfo";
		_bondBasedModelInfo->updateDatabase(db);
	}
	else if (_coarseGrainingModelInfo != nullptr)
	{
		debugLog << "Updating dependencies for RepresentationType->CoarseGrainingModelInfo";
		_coarseGrainingModelInfo->updateDatabase(db);
	}
	else if (_ensembleRefineInfo != nullptr)
	{
		debugLog << "Updating dependencies for RepresentationType->EnsembleRefineInfo";
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
	// debugLog<<_type;
	if (_type == Atomic)
	{
		// Utility::debugLogTest("New instance for Atomistic model type");
		_atomicModelInfo = new AtomicModelInfo();
	}
	else if (_type == BondBased)
	{
		// Utility::debugLogTest("New instance for Bond-based model type");
		_bondBasedModelInfo = new BondBasedModelInfo();
	}
	else if (_type == CG)
	{
		// Utility::debugLogTest("New instance for CG model type");
		_coarseGrainingModelInfo = new CoarseGrainingModelInfo();
	}
	else if (_type == Ensemble)
	{
		// Utility::debugLogTest("New instance for Ensemble model type");
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


/// ------------------ RETRIEVING STUFF -----------------------
RepresentationType* RepresentationType::representationTypeByPrimaryId(int id, Database *db)
{
    return Cache<RepresentationType>::cacheByPrimaryId(id, db); // Use the template function from the cache
}


void RepresentationType::retrieveDependencies(Result &res, Database *db)
{
	std::string atomic_id = AtomicModelInfo::staticSqlIDName();
	std::string bond_id = BondBasedModelInfo::staticSqlIDName();
	std::string cg_id = CoarseGrainingModelInfo::staticSqlIDName();
	std::string ensembl_id = EnsembleRefineInfo::staticSqlIDName();

	if (!Utility::isNull(res[atomic_id]))
	{
		// Utility::debugLogTest("Retrieving from RepresentationType->AtomicModelInfo");
		delete _atomicModelInfo;
		_atomicModelInfo = nullptr;

		// debugLog << "res[atomic_id] = " + res[atomic_id];
		AtomicModelInfo* atom = AtomicModelInfo::atomicModelByPrimaryId(std::stoi(res[atomic_id]), db);
		_atomicModelInfo = atom;
	}
	else if (!Utility::isNull(res[bond_id]))
	{
		// Utility::debugLogTest("Retrieving from RepresentationType->BondBasedModelInfo");
		delete _bondBasedModelInfo;
		_bondBasedModelInfo = nullptr;

		// debugLog << "res[atomic_id] = " + res[bond_id];
		BondBasedModelInfo* bondBase = BondBasedModelInfo::bondModelByPrimaryId(std::stoi(res[bond_id]), db);
		_bondBasedModelInfo = bondBase;
	}
	else if (!Utility::isNull(res[cg_id]))
	{
		// Utility::debugLogTest("Retrieving from RepresentationType->CoarseGrainingModelInfo");
		delete _coarseGrainingModelInfo;
		_coarseGrainingModelInfo = nullptr;
		
		
		// debugLog << "res[cg_id] = " + res[cg_id];
		CoarseGrainingModelInfo* cg = CoarseGrainingModelInfo::cgModelByPrimaryId(std::stoi(res[cg_id]), db);
		_coarseGrainingModelInfo = cg;

	}
	else if (!Utility::isNull(res[ensembl_id]))
	{
		// Utility::debugLogTest("Retrieving from RepresentationType->EnsembleRefineInfo");
		delete _ensembleRefineInfo;
		_ensembleRefineInfo = nullptr;


		// debugLog << "res[ensembl_id] = " + res[ensembl_id];
		EnsembleRefineInfo* ensembl = EnsembleRefineInfo::ensembleByPrimaryId(std::stoi(res[ensembl_id]), db);
		_ensembleRefineInfo = ensembl;
		
	}
	else
	{
		throw std::runtime_error("Can't retrieving dependencies for RepresentationType: no representation type");
	}

}

void RepresentationType::fillInFromResults(const Result &res) 
{

	std::string atomic_id = AtomicModelInfo::staticSqlIDName();
	std::string bond_id = BondBasedModelInfo::staticSqlIDName();
	std::string cg_id = CoarseGrainingModelInfo::staticSqlIDName();
	std::string ensembl_id = EnsembleRefineInfo::staticSqlIDName();

	if (!Utility::isNull(res.at(atomic_id)))
	{
		_atomicModelInfo = new AtomicModelInfo();
		_atomicModelInfo->getPidFromResults(res);
	}
	
	if (!Utility::isNull(res.at(bond_id)))
	{
		_bondBasedModelInfo = new BondBasedModelInfo();
		_bondBasedModelInfo->getPidFromResults(res);
	} 
	
	if (!Utility::isNull(res.at(cg_id)))
	{
		_coarseGrainingModelInfo = new CoarseGrainingModelInfo;
		_coarseGrainingModelInfo->getPidFromResults(res);
	}

	if (!Utility::isNull(res.at(ensembl_id)))
	{
		_ensembleRefineInfo = new EnsembleRefineInfo;
		_ensembleRefineInfo->getPidFromResults(res);
	}
}


