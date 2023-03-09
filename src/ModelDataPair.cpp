// PModel.cpp

#include <iostream>
#include "ModelDataPair.h"
#include "Data.h" // to change to DataInterface
#include "Model.h"
#include "PModel.h"
#include "EnumTables.h"

using namespace mulch;

ModelDataPair::ModelDataPair()
{
	// create new object
	_model = new PModel();
	_data = new Data();
}

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
	// query += std::to_string(primaryId());
	// query += ";";
	return query;

	// std::string query;
	// query = "UPDATE " + table;
	// query += "SET pdb_code = " + pdbName; // repace xyz with input 'std::string pdbname' instead
	// query += "WHERE " + id + " IN ";
	// query += "(SELECT " + id + " FROM RepresentationType ";
	// query += "WHERE representation_type_id = ";
	// query += _pid;
	// query += ";";

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
