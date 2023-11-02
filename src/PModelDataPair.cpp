
// ModelDataPair.cpp

#include <iostream>
#include "PModelDataPair.h"
#include "RepresentationType.h"
#include "PData.h"
#include "PModel.h"

using namespace mulch;


PModelDataPair::PModelDataPair()
{
	_model = nullptr;
	_data = nullptr;
}

int PModelDataPair::returnPrimaryId() const
{
    return primaryId();
}

Model* PModelDataPair::getModel()
{
    debugLog << "In  PModelDataPair::getModel";
    PModel* pModel = _model;
    if (pModel != nullptr)
    {
        Model* model = (static_cast<Model*>(pModel));
        return model;
    } 
    else
    {
        std::runtime_error("In PModelDataPair::getModel: model vector does not exist for this MDP id");
    }
}


void PModelDataPair::setRep(RepresentationEnum rep)
{
	if (_model == nullptr)
	{
		_model = new PModel;
	}   
	_model->setRepType(rep);
}

Data* PModelDataPair::getData()
{
    debugLog << "In  PModelDataPair::getData";
    PData* pData = _data;
    if (pData != nullptr)
    {
        Data* data = (static_cast<Data*>(pData));
        return data;
    }
    else
    {
        std::runtime_error("In PModelDataPair::getData: data vector does not exist for this MDP id");
    }

}

void PModelDataPair::setFile(std::string pdbName)
{
	if (_model == nullptr)
	{
		_model = new PModel;
	}   
	_model->setFileName(pdbName);
}


void PModelDataPair::setDataType(DataEnum datatype)
{
	if (_data == nullptr)
	{
		_data = new PData;
	}   
	_data->setDataInfo(datatype);
}

void PModelDataPair::setDataFile(std::string datafile)
{
	if (_data == nullptr)
	{
		_data = new PData;
	}   
	_data->setFileName(datafile);
}

// void PModelDataPair::setDataComments(const std::string& comments)
// {
//     if (_data != nullptr)
//     {
//         _data->setComments(comments);
//     }
//     else
//     {
//         debugLog << "No _data object to set comments on.";
//     }
// }

void PModelDataPair::setDataComments(const std::string& comments)
{
    if (_data != nullptr)
    {
        _data->setComments(comments);
    }
    else
    {
        debugLog << "No _data object to set comments on.";
    }
}

void PModelDataPair::setModelComments(const std::string& comments)
{
    if (_model == nullptr)
    {
        _model = new PModel;
    } 
    debugLog << "Before _model->setComments: " << _model->getComments();
    _model->setComments(comments);
    debugLog << "After _model->setComments: " << _model->getComments();

}

std::string PModelDataPair::insertQuery()
{
    std::string query;
    query = "INSERT INTO ModelDataPair DEFAULT VALUES";
    Utility::protectsql(query);
    return query;
}



// std::string PModelDataPair::insertQuery()
// {    
//     std::string query;

//     if (_data != nullptr && _model != nullptr)
//     // if (_data->primaryId() > 0 && _model->primaryId() > 0 )
//     {

//         query = "INSERT INTO ModelDataPair (data_ID, model_ID) VALUES ";
//         query += "(";
//         query += std::to_string(_data->primaryId());
//         query += ",";
//         query += std::to_string(_model->primaryId());
//         query += ");";
//     }
//     else if (_data == nullptr)
//     {
//         query = "INSERT INTO ModelDataPair (model_ID) VALUES ";
//         query += "(";
//         query += std::to_string(_model->primaryId());
//         query += ");";
//         Utility::protectsql(query);    
//     }
//     else if (_model == nullptr)
//     {
//         query = "INSERT INTO ModelDataPair (data_ID) VALUES ";
//         query += "(";
//         query += std::to_string(_data->primaryId());
//         query += ");";
//         Utility::protectsql(query);    
//     }
//     else
//     {
//         throw std::runtime_error("Error: Cannot generate insert query with uninitialized data or model.");
//     }

//     debugLog << query;
//     return query;    
// }


// std::string PModelDataPair::updateQuery()
// {
// 	std::string query;
// 	query = " ";
// 	Utility::protectsql(query);
// 	return query;
// }

std::string PModelDataPair::updateQuery()
{
    std::string query;
    query = "UPDATE ModelDataPair SET ";
    bool hasUpdates = false;

    if (_data != nullptr && _model != nullptr)
    {
        query += "model_ID = ";
        query += std::to_string(_model->primaryId());
        query += ", data_ID = ";
        query += std::to_string(_data->primaryId());
        hasUpdates = true;
    }
    else if (_model != nullptr && _data == nullptr)
    {
        query += "model_ID = ";
        query += std::to_string(_model->primaryId());
        hasUpdates = true;
    }
    else if (_data != nullptr && _model == nullptr)
    {
        if (hasUpdates) {
            query += ", ";
        }
        query += "data_ID = ";
        query += std::to_string(_data->primaryId());
        hasUpdates = true;
    }
    if (hasUpdates) {
        query += " WHERE modeldatapair_id = (";
        query += std::to_string(PModelDataPair::primaryId());
        query += + ");";
        debugLog << "Update query in PModelDataPair: " << query;
        return query;
    } else {
        return ""; // No updates to perform
    }
}



std::string PModelDataPair::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM ModelDataPair WHERE modeldatapair_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}

void PModelDataPair::updateDependenciesBefore(Database *db)
{

    if (_model != nullptr && _data != nullptr)
    {
        debugLog << "Update _model and _data from PModelDataPair::updateDependenciesBefore";
        _model->updateDatabase(db);
        _data->updateDatabase(db);
    }	
	else if (_model != nullptr)
    {
        debugLog << "Update _model from PModelDataPair::updateDependenciesBefore";
        _model->updateDatabase(db);
    }
    else if (_data != nullptr)
    {
        debugLog << "Update _data from PModelDataPair::updateDependenciesBefore";
        _data->updateDatabase(db);
    }

}

std::vector<PModel*> PModelDataPair::retrieveModelByType(RepresentationEnum rep, Database *db)
{
	std::vector<PModel*> models;
	// debugLog << "In ModelDataPair::retrieveModelByType: All ok, continue";

	models = _model->retrieveByType(rep, db);
	return models;
}

/// ------------------ RETRIEVING STUFF -----------------------
PModelDataPair* PModelDataPair::modelDataPairByPrimaryId(int id, Database *db)
{
    return Cache<PModelDataPair>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void PModelDataPair::retrieveDependencies(Result &res, Database *db)
{

    std::string model_id = PModel::staticSqlIDName();
    std::string data_id =  PData::staticSqlIDName();
	// delete _model;
 //    _model = nullptr;
	// delete _data;
 //    _data = nullptr;



    if (!Utility::isNull(res[model_id]))
    {
        delete _model;
        _model  = nullptr;

        std::string model_id = PModel::staticSqlIDName();
        debugLog << "res[model_id] = " + res[model_id];

        PModel* model = PModel::modelByPrimaryId(std::stoi(res[model_id]), db);
        _model = model;
    }
    
    if (!Utility::isNull(res[data_id]))
    {
        delete _data;
        _data = nullptr;

        std::string data_id = PData::staticSqlIDName();
        debugLog << "res[data_id] = " + res[data_id];

        PData* data = PData::dataByPrimaryId(std::stoi(res[data_id]), db);
        _data = data;
    }

	bool allNull = Utility::isNull(res[model_id]) && Utility::isNull(res[data_id]);
    if (allNull)
    {
        throw std::runtime_error("In ModelDataPair: Unregistered values.");
    }

    // try {
    //     if (_model != nullptr)
    //     {
    //         delete _model;
    //     }
    //     if (!Utility::isNull(res[model_id]))
    //     {
    //         PModel* model = PModel::modelByPrimaryId(std::stoi(res[model_id]), db);
    //         _model = model;
    //     }
    // } catch (const std::invalid_argument& e) {
    //     std::cerr << "Error converting res[model_id] to integer: " << e.what() << std::endl;
    // }

    // try {
    //     if (_data != nullptr)
    //     {
    //         delete _data;
    //     }
    //     if (!Utility::isNull(res[data_id]))
    //     {
    //         PData* data = PData::dataByPrimaryId(std::stoi(res[data_id]), db);
    //         _data = data;
    //     }
    // } catch (const std::invalid_argument& e) {
    //     std::cerr << "Error converting res[data_id] to integer: " << e.what() << std::endl;
    // }

}


void PModelDataPair::fillInFromResults(const Result &res) 
{
    // Retrieve and populate model and data information
    std::string model_id = PModel::staticSqlIDName();
    std::string data_id = PData::staticSqlIDName();

    if (!Utility::isNull(res.at(model_id)))
    {
        debugLog << "Hi!! I'm in PModelDataPair::fillInFromResults, _model is not NULL";
        _model = new PModel();
        _model->getPidFromResults(res);
    }

    if (!Utility::isNull(res.at(data_id)))
    {
        _data = new PData();
        _data->getPidFromResults(res);
    }
}

