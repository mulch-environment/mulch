// Model.cpp

#include <iostream>
#include "ModelDataPair.h"
#include "Data.h" // to change to DataInterface
#include "IModel.h"
#include "Model.h"
#include "EnumTables.h"

using namespace mulch;

ModelDataPair::ModelDataPair(std::string pdbName, std::string datafile, RepresentationEnum rep, DataEnum datatype)
{
	// create new object
	_model = new Model();
	_model->setRepType(rep);
	_model->setFileName(pdbName);
	_data = new Data();
	_data->setDataInfo(datatype);
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

std::string ModelDataPair::selectPidQuery()
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





// std::vector<ModelDataPair*>  ModelDataPair::setRepType(RepresentationEnum rep, Database *db)
// {
// 	std::vector<IModel*> models;
// 	std::string query = Model::selectQueryModelsByType(rep);
// 	std::string idName = Model::staticSqlIDName(); 
// 	db->query(query);
// }




// ModelDataPair ModelDataPair::modelDataPairFromResult(const Result &res)
// {
// 	ModelDataPair exportedmodelDataPair;
// 	int pid = atoi(res.at("modeldatapair_id").c_str());
// 	exportedmodelDataPair.setPrimaryId(pid);
// 	return exportedmodelDataPair;
// }


