// Model.cpp


#include "ModelDataPair.h"
#include "Data.h"
#include "Model.h"
using namespace mulch;

ModelDataPair::ModelDataPair()
{
	_model = new Model();
	_data = new Data();

}

std::string ModelDataPair::insertQuery()
{	
	std::string query;
	query = "INSERT INTO ModelDataPair (data_ID, model_ID) VALUES";
	query += "(";
	query += std::to_string(_data->primaryId());
	query += ",";
	query += std::to_string(_model->primaryId());
	query += ");";

	return query;
}


std::string ModelDataPair::updateQuery()
{
	std::string query;
	query = "";

	return query;
}

std::string ModelDataPair::selectQuery()
{
	std::string query;
	query = "SELECT modeldatapair_id FROM ModelDataPair";
	query += ";";

	return query;
}

void ModelDataPair::updateDependencies(Database *db)
{
	// send that representationType to the database
	_model->updateDatabase(db);
	_data->updateDatabase(db);
	
}



ModelDataPair ModelDataPair::modelDataPairFromResult(const Result &res)
{
	ModelDataPair exportedmodelDataPair;
	int pid = atoi(res.at("modeldatapair_id").c_str());
	exportedmodelDataPair.setPrimaryId(pid);
	return exportedmodelDataPair;
}


