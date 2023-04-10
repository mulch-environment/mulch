// PModel.cpp

#include <typeinfo>
#include <string>
#include <iostream>
#include "PModel.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
#include "Utility.h"
using namespace mulch;


PModel::PModel()
{
	_representationType = new RepresentationType();
	_structureTechniqueInfo = new StructureTechniqueInfo();
}

std::string PModel::insertQuery()
{	
	std::string query;
	query = "INSERT INTO Model (representation_type_ID, structure_technique_ID) VALUES";
	query += "(";
	query += std::to_string(_representationType->primaryId());
	query += ",";
	query += std::to_string(_structureTechniqueInfo->primaryId());
	query += ");";
	std::cout<<query<<std::endl;
	Utility::protectsql(query);
	return query;
}


std::string PModel::updateQuery()
{
	std::string query;
	query = "UPDATE Model SET pdb_code = ";
	query += "'";
	query += _pdbName;
	query += "'";
	query +=  ", haspdb = ";
	query += "'";
	query += _hasPdb;
	query += "'";
	query += ", comments = ";
	query += "'";
	query += _comments;
	query += "'";
	query += " WHERE model_ID = ";
	query += "(";	
	query += std::to_string(primaryId());
	query += ");";
	std::cout<<"Update query in PModel: "<<std::endl;
	std::cout<<query<<std::endl;
	return query;
}


std::string PModel::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Model WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";


	return query;
}

std::string PModel::selectQueryModelsByType(RepresentationEnum rep)
{
	std::string table, id;
	switch (rep)
	{
		case Atomic:
		table = "AtomicModelInfo";
		id = "atomic_model_id";
		break;

		case BondBased:
		table = "bondbasedmodelinfo";
		id = "bondbased_model_id";
		break;

		case CG:
		table = "CoarseGrainingModelInfo";
		id = "coarsegraining_model_id";
		break;

		case Ensemble:
		table = "EnsembleRefineInfo";
		id = "ensemble_refine_id";
		break;

		default:
		std::cout << "default\n";
		break;	
	};

	std::string query;
	query = "SELECT model.model_id AS model_id, model.pdb_code,";
	query += table+".comments " + "FROM RepresentationType ";
	query += " JOIN "+table;
	query += " ON " + table + "." + id + " = RepresentationType."+id;
	query += " JOIN model ";
	query += "ON model.representation_type_id = RepresentationType.representation_type_id ";
	query += ";";

	Utility::protectsql(query);
	return query;
}

void PModel::updateDependenciesBefore(Database *db)
{
	// send that representationType to the database
	_representationType->updateDatabase(db);
	_structureTechniqueInfo->updateDatabase(db);
	
}


/// ------------------ RETRIEVING STUFF -----------------------
PModel* PModel::modelByPrimaryId(int id, Database *db)
{
	PModel *model = new PModel();
	model->retrieveExisting(id, db);

}

void PModel::retrieveDependencies(Result &res, Database *db)
{

	delete _representationType;
	delete _structureTechniqueInfo;

	std::string rep_id = RepresentationType::staticSqlIDName();
	std::string str_id =  StructureTechniqueInfo::staticSqlIDName();
	std::cout << "res[rep_id] = " + res[rep_id] << std::endl;
	std::cout << "res[str_id] = " + res[str_id] << std::endl;
	// _representationType = RepresentationType::representationTypeByPrimaryId(res[rep_id], db);
	// _structureTechniqueInfo = StructureTechniqueInfo::structureTechniqueInfoByPrimaryId(res[str_id], db);
}

void PModel::fillInFromResults(const Result &res) 
{
    // std::cout << typeid(res).name() << std::endl;
    // _comments = res["comments"];
    _representationType->getPidFromResults(res);
    _structureTechniqueInfo->getPidFromResults(res);
}



void PModel::setRepType(RepresentationEnum rep)
{	
	_representationType->setRepType(rep);

}

void PModel::setFileName(std::string pdbName)
{	

	_representationType->setFileName(pdbName);
}


std::vector<PModel*> PModel::retrieveByType(RepresentationEnum rep, Database *db)
{
	std::vector<PModel*> models;
	std::string query;
	query = selectQueryModelsByType(rep);
	std::cout << query << std::endl;
	std::vector<Result> results = db->results();

	for (Result &res: results)
	{
		PModel *model = new PModel();
		model->retrieveFromResult(res, db);
		models.push_back(model);
	}
	return models;
}

// void PModel::retrieveDependencies(Database *db)
// {
// 	// send that representationType to the database
// 	_representationType->updateDatabase(db);
// 	_structureTechniqueInfo->updateDatabase(db);
	
// }



