
// ModelDataPair.cpp

#include <iostream>
#include "ModelDataPair.h"
#include "RepresentationType.h"
#include "PData.h"
#include "PModel.h"

using namespace mulch;

ModelDataPair::ModelDataPair()
{
	_model = nullptr;
	_data = nullptr;
}



void ModelDataPair::setRep(RepresentationEnum rep)
{
	if (_model == nullptr)
	{
		_model = new PModel;
	}   
	_model->setRepType(rep);
}


void ModelDataPair::setFile(std::string pdbName)
{
	if (_model == nullptr)
	{
		_model = new PModel;
	}   
	_model->setFileName(pdbName);
}


void ModelDataPair::setDataType(DataEnum datatype)
{
	if (_data == nullptr)
	{
		_data = new PData;
	}   
	_data->setDataInfo(datatype);
}

void ModelDataPair::setDataFile(std::string datafile)
{
	if (_data == nullptr)
	{
		_data = new PData;
	}   
	_data->setFileName(datafile);
}


std::string ModelDataPair::insertQuery()
{    
    std::string query;

    if (_data != nullptr && _model != nullptr)
    {
        query = "INSERT INTO ModelDataPair (data_ID, model_ID) VALUES ";
        query += "(";
        query += std::to_string(_data->primaryId());
        query += ",";
        query += std::to_string(_model->primaryId());
        query += ");";
    }
    else if (_data == nullptr)
    {
        query = "INSERT INTO ModelDataPair (model_ID) VALUES ";
        query += "(";
        query += std::to_string(_model->primaryId());
        query += ");";
        Utility::protectsql(query);    
    }
    else if (_model == nullptr)
    {
        query = "INSERT INTO ModelDataPair (data_ID) VALUES ";
        query += "(";
        query += std::to_string(_data->primaryId());
        query += ");";
        Utility::protectsql(query);    
    }
    else
    {
        throw std::runtime_error("Error: Cannot generate insert query with uninitialized data or model.");
    }

    return query;    
}


std::string ModelDataPair::updateQuery()
{
	std::string query;
	query = " ";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string ModelDataPair::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
}

// ------------------------------------------------------------------------------------------

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
	if (_model != nullptr)
    {
        _model->updateDatabase(db);
    }
    if (_data != nullptr)
    {
        _data->updateDatabase(db);
    }

}

std::vector<PModel*> ModelDataPair::retrieveModelByType(RepresentationEnum rep, Database *db)
{
	std::vector<PModel*> models;
	Utility::debugLogTest("In ModelDataPair::retrieveModelByType: All ok, continue");

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
        if (_model != nullptr)
        {
            delete _model;
        }
        if (!Utility::isNull(res[model_id]))
        {
            PModel* model = PModel::modelByPrimaryId(std::stoi(res[model_id]), db);
            _model = model;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting res[model_id] to integer: " << e.what() << std::endl;
    }

    try {
        if (_data != nullptr)
        {
            delete _data;
        }
        if (!Utility::isNull(res[data_id]))
        {
            PData* data = PData::dataByPrimaryId(std::stoi(res[data_id]), db);
            _data = data;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting res[data_id] to integer: " << e.what() << std::endl;
    }

}

