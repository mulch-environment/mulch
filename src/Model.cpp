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
	query = "UPDATE Model SET comments = ";
	query += " ' ";
	query += _comments;
	query += " ' ";
	query += " WHERE model_ID = ";
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

std::string Model::selectModelsByType()
{
	// change the type of the model to be able to select any RepresentationType 
	std::string query;
	query = "SELECT model.pdb_code, bondbasedmodelinfo.comments";
	query += "FROM RepresentationType";
	query += "JOIN bondbasedmodelinfo";
	query += "ON bondbasedmodelinfo.bondbased_model_id = RepresentationType.bondbased_model_id";
	query += "JOIN model";
	query += "ON model.representation_type_id = RepresentationType.representation_type_id";
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
	std::cout << typeid(res).name() << std::endl;
	// _comments = res["comments"];
	_representationType->getPidFromResults(res);
	_structureTechniqueInfo->getPidFromResults(res);

};

void Model::setComments(std::string comments)
{
	_comments = comments;	
	std::cout << _comments << std::endl;
}




