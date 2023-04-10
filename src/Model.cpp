#include <typeinfo>
#include <string>
#include <iostream>
#include "Model.h"
#include "PModel.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
#include "Utility.h"
using namespace mulch;

void  Model::modelsByRepType(RepresentationEnum rep, Database *db)
{
// 	std::vector<Model*> models;
// 	std::string query = PModel::selectQueryModelsByType(rep);
// 	std::string idName = PModel::staticSqlIDName(); 
// 	db->query(query);

// 	std::vector<Result> results = db->results();
// 	for (Result &res: results)
// 	{

// 		if (res.count(idName) >0)
// 	    {
// 	    	PModel *model_pnt = new PModel();
// 	        int pid = std::stoi(res.at(idName));

// 	        // model_pnt->setPrimaryId(pid);
// 	        // model_pnt->retrieveExisting(db);
// 	        // models.push_back(model_pnt);

// 	        model_pnt->setPrimaryId(pid);
// 	        model_pnt->retrieveExisting(db);
// 	        models.push_back(model_pnt);
// 	    }
// 	    else
// 	    {
// 	    	throw std::runtime_error("There is an issue with results in Model::modelsByRepType");
// 	    }
// 	}

// 	return models;
}


