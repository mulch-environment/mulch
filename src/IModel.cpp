#include <typeinfo>
#include <string>
#include <iostream>
#include "IModel.h"
#include "Model.h"
#include "RepresentationType.h"
#include "StructureTechniqueInfo.h"
#include "AtomicModelInfo.h"
#include "Utility.h"
using namespace mulch;

std::vector<IModel*>  IModel::modelsByRepType(RepresentationEnum rep, Database *db)
{
	std::vector<IModel*> models;
	std::string query = Model::selectQueryModelsByType(rep);
	std::string idName = Model::staticSqlIDName(); 
	db->query(query);

	std::vector<Result> results = db->results();
	for (Result &res: results)
	{

		if (res.count(idName) >0)
	    {
	    	Model *model_pnt = new Model();
	        int pid = std::stoi(res.at(idName));

	        // model_pnt->setPrimaryId(pid);
	        // model_pnt->retrieveExisting(db);
	        // models.push_back(model_pnt);

	        model_pnt->setPrimaryId(pid);
	        model_pnt->retrieveExisting(db);
	        models.push_back(model_pnt);
	    }
	    else
	    {
	    	throw std::runtime_error("There is an issue with results in Model::modelsByRepType");
	    }
	}

	return models;
}


