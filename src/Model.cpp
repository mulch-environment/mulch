// Model.cpp

#include <typeinfo>
#include <string>
#include <iostream>
#include "Model.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
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

	return query;
}


std::string Model::updateQuery()
{
	std::string query;
	query = "UPDATE Model SET comments = 'blahblah' WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";


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
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!! typeid(res).name() = "<< std::endl;
	std::cout << typeid(res).name() << std::endl;
	// _comments = res["comments"];
	_representationType->getPidFromResults(res);
	_structureTechniqueInfo->getPidFromResults(res);

};



