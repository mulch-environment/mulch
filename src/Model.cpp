// Model.cpp

#include <typeinfo>
#include <string>
#include <iostream>
#include "Model.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
#include "Utility.h"
using namespace mulch;


Model::Model()
{
	_representationType = new RepresentationType();
	_structureTechniqueInfo = new StructureTechniqueInfo();

}

std::string Model::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Model (representation_type_ID, structure_technique_ID) VALUES";
	query += "(";
	query += std::to_string(_representationType->primaryId());
	query += ",";
	query += std::to_string(_structureTechniqueInfo->primaryId());
	query += ");";

	Utiliy::protectsql(&query);
	return query;
}


std::string Model::updateQuery()
{
	std::string query;
	query = "UPDATE Model SET comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += " WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";

	Utiliy::protectsql(&query);
	return query;
}

std::string Model::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Model WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";


	return query;
}

std::string Model::selectQueryModelsByType(RepresentationEnum rep)
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

  	std::string apostrophe = "'";
	std::string query;
	query = "SELECT model.model_id AS model_id, model.pdb_code,";
	query += table+".comments " + "FROM RepresentationType ";
	query += " JOIN "+table;
	query += " ON " + table + "." + id + " = RepresentationType."+id;
	query += " JOIN model ";
	query += "ON model.representation_type_id = RepresentationType.representation_type_id ";
	query += ";";

	Utiliy::protectsql(&query);
	return query;
}

void Model::updateDependencies(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}

void Model::retrieveDependencies(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}

void Model::fillInFromResults(const Result &res) 
{
	std::cout << typeid(res).name() << std::endl;
	// _comments = res["comments"];
	_representationType->getPidFromResults(res);
	_structureTechniqueInfo->getPidFromResults(res);

};


