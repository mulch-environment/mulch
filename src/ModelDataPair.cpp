
// ModelDataPair.cpp

#include <iostream>
#include "ModelDataPair.h"
#include "RepresentationType.h"
#include "PData.h"
#include "PModel.h"

using namespace mulch;

ModelDataPair::ModelDataPair()
{
	// _model = nullptr;
	// _data = nullptr;

	// change: only allocate when you set up the representationtype 
	_model = new PModel();
	// change: only allocate when you set up the datatype
	_data = new PData();
}

// RepresentationEnum ModelDataPair::representationType()
// {	
// 	return _model->_representationType;
// }

void ModelDataPair::setRep(RepresentationEnum rep)
{
	_model->setRepType(rep);
}


void ModelDataPair::setFile(std::string pdbName)
{
	_model->setFileName(pdbName);
}


void ModelDataPair::setDataType(DataEnum datatype)
{
	_data->setDataInfo(datatype);
}

void ModelDataPair::setDataFile(std::string datafile)
{
	_data->setFileName(datafile);
}


std::string ModelDataPair::insertQuery()
{	
	std::string query;
	query = "INSERT INTO ModelDataPair (data_ID, model_ID) VALUES ";
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
	query = " ";
	return query;
}

std::string ModelDataPair::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM ModelDataPair WHERE modeldatapair_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);

	return query;
}

void ModelDataPair::updateDependenciesBefore(Database *db)
{
	// send that representationType to the database
	_model->updateDatabase(db);
	_data->updateDatabase(db);

}

std::vector<PModel*> ModelDataPair::retrieveModelByType(RepresentationEnum rep, Database *db)
{
	std::vector<PModel*> models;
	std::cout << "In ModelDataPair::retrieveModelByType: All ok, continue" << std::endl;

	models = _model->retrieveByType(rep, db);
	return models;
}

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<ModelDataPair*, int> ModelDataPair::modelDataPairByPrimaryId(int id, Database *db)
{
    return Cache<ModelDataPair>::cacheByPrimaryId(id, db); // Use the template function from the cache
}



