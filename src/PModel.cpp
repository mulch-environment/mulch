// PModel.cpp

#include <typeinfo>
#include <string>
#include <iostream>
#include "PModel.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
#include "Utility.h"
using namespace mulch;


PModel::PModel()
{
	_representationType = new RepresentationType();
	_structureTechniqueInfo = new StructureTechniqueInfo();

}

std::string PModel::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Model (representation_type_ID, structure_technique_ID) VALUES";
	query += "(";
	query += std::to_string(_representationType->primaryId());
	query += ",";
	query += std::to_string(_structureTechniqueInfo->primaryId());
	query += ");";

	Utility::protectsql(query);
	return query;
}


std::string PModel::updateQuery()
{
	std::string query;
	query = "UPDATE Model SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += " WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";

	return query;
}

std::string PModel::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Model WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";


	return query;
}

std::string PModel::selectQueryModelsByType(RepresentationEnum rep)
{
	std::string table, id;
	switch (rep)
	{
		case Atomic:
		table = "AtomicModelInfo";
		id = "atomic_model_id";
		break;

		case BondBased:
		table = "bondbasedmodelinfo";
		id = "bondbased_model_id";
		break;

		case CG:
		table = "CoarseGrainingModelInfo";
		id = "coarsegraining_model_id";
		break;

		case Ensemble:
		table = "EnsembleRefineInfo";
		id = "ensemble_refine_id";
		break;

		default:
		std::cout << "default\n";
		break;	
	};

	std::string query;
	query = "SELECT model.model_id AS model_id, model.pdb_code,";
	query += table+".comments " + "FROM RepresentationType ";
	query += " JOIN "+table;
	query += " ON " + table + "." + id + " = RepresentationType."+id;
	query += " JOIN model ";
	query += "ON model.representation_type_id = RepresentationType.representation_type_id ";
	query += ";";

	Utility::protectsql(query);
	return query;
}

void PModel::updateDependencies(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}

void PModel::retrieveDependencies(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}

void PModel::fillInFromResults(const Result &res) 
{
	std::cout << typeid(res).name() << std::endl;
	// _comments = res["comments"];
	_representationType->getPidFromResults(res);
	_structureTechniqueInfo->getPidFromResults(res);

};

void PModel::setRepType(RepresentationEnum rep)
{	
	_representationType->setRepType(rep);

}

void PModel::setFileName(std::string pdbName)
{	

	_representationType->setFileName(pdbName);
}




	// _representationType->insertQuery();
	// _representationType->updatePid(db);
	// std::cout << _pid << std::endl;

	// std::string query;
	// query = "UPDATE " + table;
	// query += "SET pdb_code = " + pdbName; // repace xyz with input 'std::string pdbname' instead
	// query += "WHERE " + id + " IN ";
	// query += "(SELECT " + id + " FROM RepresentationType ";
	// query += "WHERE representation_type_id = ";
	// query += _pid;
	// query += ";";

	// Utility::protectsql(query);
	// std::cout<<query<<std::endl;


