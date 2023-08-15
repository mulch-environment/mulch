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
	// Utility::protectsql(query);
	return query;
}


std::string PModel::updateQuery()
{
	std::string query;
	query = "UPDATE Model SET pdb_code = '";
	query += _pdbName;
	query +=  "', haspdb = '";
	query += _hasPdb;
	query += "' , comments = '";
	query += _comments;
	query += "' WHERE model_ID = (";
	query += std::to_string(primaryId());
	query += ");";
	debugLog << "Update query in PModel: ";
	debugLog << query;
	// Utility::protectParameter(_pdbName);
	// Utility::protectParameter(_hasPdb);
	// Utility::protectParameter(_comments);
    // Utility::protectsql(query);
    return query;
}



std::string PModel::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Model WHERE model_ID = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
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
	debugLog << "Update _representationType from PModelDataPair::updateDependenciesBefore";
	_representationType->updateDatabase(db);
	debugLog << "Update _structureTechniqueInfo from PModelDataPair::updateDependenciesBefore";
	_structureTechniqueInfo->updateDatabase(db);
	
}


/// ------------------ RETRIEVING STUFF -----------------------
PModel* PModel::modelByPrimaryId(int id, Database *db)
{
	// PModel *model = new PModel();
	// model->retrieveExisting(id, db);
	// return model;
	   return Cache<PModel>::cacheByPrimaryId(id, db); // Use the template function from the cache

}

void PModel::retrieveDependencies(Result &res, Database *db)
{
    delete _representationType;
    _representationType = nullptr;
    delete _structureTechniqueInfo;
    _structureTechniqueInfo = nullptr;

    std::string rep_id = RepresentationType::staticSqlIDName();
    std::string str_id = StructureTechniqueInfo::staticSqlIDName();
    
    if (!Utility::isNull(res[rep_id]) && !Utility::isNull(res[str_id]))
    {
    	debugLog << "Retrieving from PModel->RepresentationType \n";
    	int repId = std::stoi(res[rep_id]);
    	RepresentationType* repType = RepresentationType::representationTypeByPrimaryId(repId, db);
    	_representationType = repType;

    	debugLog << "Retrieving from PModel->StructureTechniqueInfo \n";
    	int strId = std::stoi(res[str_id]);
    	StructureTechniqueInfo* strTech = StructureTechniqueInfo::structureTechniqueInfoByPrimaryId(strId, db);
    	_structureTechniqueInfo = strTech;

	}
}
    // try {
    //     int repId = std::stoi(res[rep_id]);
    //     RepresentationType* repType = RepresentationType::representationTypeByPrimaryId(repId, db);
    //     _representationType = repType;
    // } 
    // catch (const std::invalid_argument& e) {
    //     // Handle the case when the conversion fails
    //     std::cerr << "Warning: converting res[rep_id] to integer not necessary " << std::endl;
    // }

    // try {
    //     int strId = std::stoi(res[str_id]);
    //     StructureTechniqueInfo* strTech = StructureTechniqueInfo::structureTechniqueInfoByPrimaryId(strId, db);
    //     _structureTechniqueInfo = strTech;
    // } 
    // catch (const std::invalid_argument& e) {
    //     // Handle the case when the conversion fails
    //     std::cerr << "Warning: converting res[str_id] to integer not necessary " << std::endl;
    // }



void PModel::fillInFromResults(const Result &res) 
{
    // std::cout << typeid(res).name() << std::endl;
    _comments = res.at("comments");
    _representationType->getPidFromResults(res);
    _structureTechniqueInfo->getPidFromResults(res);
}

// std::vector<Result> PModel::showRetrievedValues(int pid, Database *db)
// {
// 	PModel* model = modelByPrimaryId(pid, db);
// 	std::cout << "Retrieving values from Database" << std::endl;
// 	std::cout << "Model_id = " << pid << std::endl;	
// 	std::vector<Result> retrieved_res = db->results();
// 	// std::cout << retrieved_res << std::endl;
// 	for (const auto& res : retrieved_res) 
// 	{
//     	std::cout << "Result:" << std::endl;
//     	for (const auto& kv : res) 
//     	{
//     		if (Utility::isNull(kv.second)) 
//     		{
//     			kv.second = std::string("Not yet assigned");
//     		}
//         	std::cout << "Column: " << kv.first << ", Value: " << kv.second << std::endl;
//     	}
// 	}
//     return retrieved_res;
// }

std::vector<Result> PModel::showRetrievedValues(int pid, Database *db)
{
	std::cout << "--------------------"<< std::endl;
    std::cout << "Retrieving values from Database"<< std::endl;
    std::cout << "Model_id = "<< std::endl;
    std::cout << pid << std::endl;    
    std::vector<Result> retrieved_res = db->results();
    for (auto& res : retrieved_res) 
    {
        std::cout << "Results from Model:" << std::endl;
        for (auto& kv : res) 
        {
            if (Utility::isNull(kv.second)) 
            {
                std::string temp = std::string("Not yet assigned");
                kv.second = temp;
            }
            std::cout << "Column: " << kv.first << ", Value: " << kv.second << std::endl;
        }
    }
    std::cout << "--------------------"<< std::endl;
    return retrieved_res;
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
	debugLog << query;
	std::vector<Result> results = db->results();

	for (Result &res: results)
	{
		PModel *model = new PModel();
		model->retrieveFromResult(res, db);
		models.push_back(model);
	}
	return models;
}




