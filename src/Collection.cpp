// Collection.cpp
#include <iostream>
#include "Collection.h"
#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "PData.h"
#include "PModel.h"
#include "EnumTables.h"
#include "Utility.h"

using namespace mulch;

Collection::Collection()
{

}


std::string Collection::insertQuery()
{
	std::string query;
	query = "INSERT INTO Collection (fixed) VALUES ";
	query += "(";
	query += Utility::boolToString(_fixed);
	query += ");";
	return query;	
}

std::string Collection::updateQuery()
{
	std::string query;
	// fixed = true or false vlaue, collectiontion_id = sql_id
	query = " ";

	return query;
}

std::string Collection::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Collection WHERE collection_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);

	return query;
}

void Collection::addModel(RepresentationEnum rep, std::string pdbName)
{
	ModelDataPair *mdp = new ModelDataPair();
	mdp->setRep(rep);
	mdp->setFile(pdbName);
	sentToCHD(mdp);
}

void Collection::addData(DataEnum datatype, std::string datafile)
{
	ModelDataPair *mdp = new ModelDataPair();
	mdp->setDataType(datatype);
	mdp->setDataFile(datafile);
	sentToCHD(mdp);
}

void Collection::addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
{
	std::cout<<"Adding data to ModelDataPair"<<std::endl;
	ModelDataPair *mdp = new ModelDataPair();
	mdp->setRep(rep);
	mdp->setFile(pdbName);
	mdp->setDataType(datatype);
	mdp->setDataFile(datafile);
	sentToCHD(mdp);
	// mdp->persist();

}

void Collection::sentToCHD(ModelDataPair *MDpair)
{
	std::cout<<"Adding data to CollectionHasDataset"<<std::endl;	
	CollectionHasDataset *chd = new CollectionHasDataset();
	chd->setCollection(this);
	chd->setModelDataPair(MDpair);
	_chds.push_back(chd);
}

void Collection::updateDependenciesAfter(Database *db) 
{
	for (CollectionHasDataset *chd: _chds)
	{
		chd->updateDatabase(db);
	}
}


const ModelDataPair* Collection::getModelDataPairFromCollection(int index) const
{
	if (index < 0 || index >= _chds.size())
	{
		return nullptr;
	}
	CollectionHasDataset* chd = _chds[index];
	return chd->getModelDataPair();
}

/// ------------------ RETRIEVING STUFF -----------------------
std::pair<Collection*, int> Collection::collectByPrimaryId(int id, Database *db)
{
    return Cache<Collection>::cacheByPrimaryId(id, db); // Use the template function from the cache
}



// std::vector<Collection*> Collection::retrieveCollection(Database *db)
// {
// 	std::vector<Result> results = db->results();
// 	std::vector<Collection*> collects;
// 	for (Result &res: results)
// 	{
// 		Collection *collect = new Collection();
// 		collect->retrieveFromResult(res, db);
// 		collects.push_back(collect);
// 	}
// 	return collects;
// }

// New stuff 30.03.2023 --------------------
// void Collection::retrieveDependenciesBefore(Database* db, RepresentationEnum rep)
// {
//     mulch::Result res;
//     // send that _mdp to the database
//     std::cout<<"Starting retrieval"<<std::endl;
//     res = retrieveMPD(db); 
//     if (rep != RepresentationEnum::NoneRepresentation)
//     {
//         std::vector<PModel*> modelsByType;
//         std::cout<< "Retrieving model of type " + std::to_string(static_cast<int>(rep)) <<std::endl;
//         modelsByType = retrieveModelByType(rep, db);
//     }
//     else
//     {
//         // handle the case when `rep` is not provided
//     }
// }

// void Collection::fillInFromResult(const Result &res)
// {
// 	std::cout << typeid(res).name() << std::endl;
// 	_mdp->getPidFromResults(res);
// }

// int Collection::numModelDataPairs() const 
// {
//     return _chds.size();
// }
































