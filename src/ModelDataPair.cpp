
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
ModelDataPair* ModelDataPair::modelDataPairByPrimaryId(int id, Database *db)
{
    return Cache<ModelDataPair>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void ModelDataPair::retrieveDependencies(Result &res, Database *db)
{

	delete _model;
	delete _data;

	std::string model_id = PModel::staticSqlIDName();
	std::string data_id =  PData::staticSqlIDName();

	std::cout << "res[model_id] = " << res[model_id] << std::endl;
    std::cout << "res[data_id] = " << res[data_id] << std::endl;

	bool allNull = Utility::isNull(res[model_id]) && Utility::isNull(res[data_id]);

    if (allNull)
    {
        throw std::runtime_error("In ModelDataPair: Unregistered values aftet this point.");
    }

    try {
        // std::cout << "res[model_id] = " + res[model_id] << std::endl;
		PModel* model = PModel::modelByPrimaryId(std::stoi(res[model_id]), db);
		_model = model;
    } catch (const std::invalid_argument& e) {
        // Handle the case when the conversion fails
        std::cerr << "Error converting res[model_id] to integer: " << e.what() << std::endl;
        // Perform appropriate error handling, such as setting _representationType to a default value or throwing an exception.
    }

    try {
        // std::cout << "res[data_id] = " + res[data_id] << std::endl;
		PData* data = PData::dataByPrimaryId(std::stoi(res[data_id]), db);
		_data = data;
    } catch (const std::invalid_argument& e) {
        // Handle the case when the conversion fails
        std::cerr << "Error converting res[data_id] to integer: " << e.what() << std::endl;
        // Perform appropriate error handling, such as setting _representationType to a default value or throwing an exception.
    }

}

