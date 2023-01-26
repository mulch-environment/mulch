// Model.cpp


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

void Model::updateDependencies(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}
