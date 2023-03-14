// Collection.cpp
#include <iostream>
#include "Collection.h"
#include "ModelDataPair.h"
#include "PData.h"
#include "PModel.h"
#include "EnumTables.h"



using namespace mulch;

Collection::Collection()
{
	_model = new PModel();	
	_data = new PData();
	_mdp = new ModelDataPair();
}

std::string Collection::insertQuery()
{
	std::string query;
	query = "INSERT INTO Collection DEFAULT VALUES;";
	return query;
}

std::string Collection::updateQuery()
{
	std::string query;
	// fixed = true or false vlaue, collectiontion_id = sql_id
	query = "UPDATE Collection SET fixed = 'blah' WHERE Collection_ID = 4;";

	return query;
}

std::string Collection::selectPidQuery()
{
	std::string query;
	query = "SELECT collection_id FROM Collection";
	query += ";";

	return query;
}

void Collection::addModel(RepresentationEnum rep, std::string pdbName)
{
	_model->setRepType(rep);
	_model->setFileName(pdbName);
}

void Collection::addData(DataEnum datatype, std::string datafile)
{
	_data->setFileName(datafile);
	_data->setDataInfo(datatype);
}


void Collection::addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
{
	_mdp->setRep(rep);
	_mdp->setFile(pdbName);
	_mdp->setDataType(datatype);
	_mdp->setDataFile(datafile);
}


