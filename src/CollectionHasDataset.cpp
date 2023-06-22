// CollectionHasDataset.cpp
#include "DebugLog.h"
#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "Collection.h"
#include "PCollection.h"


using namespace mulch;

bool enableDebug = true; // Set this flag to true to enable debug printing
DebugLog debugLog(enableDebug);

CollectionHasDataset::CollectionHasDataset()
{
	// _modelDataPair = new ModelDataPair();
	// _collection = new Collection();
	_modelDataPair = nullptr;
	_collection = nullptr;

}

std::string CollectionHasDataset::insertQuery()
{	
	std::string query;
	query = "INSERT INTO CollectionHasDataset (modeldatapair_ID, collection_id) VALUES";
	query += "(";
	query += std::to_string(_modelDataPair->primaryId());
	query += ",";
	query += std::to_string(_collection->primaryId());
	query += ");";
	std::cout << query <<std::endl;
	// Utility::protectsql(query);
	return query;
}


std::string CollectionHasDataset::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

// ------------------------------------------------------------------------------------------

std::string CollectionHasDataset::updateQueryTest(Database *db)
{

    std::string query = "";
    executeUpdateQuery(db, query, std::vector<std::string>());
    return query;
}

// ------------------------------------------------------------------------------------------


std::string CollectionHasDataset::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CollectionHasDataset WHERE collectionhasdataset_id =";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);
	return query;
}


void CollectionHasDataset::updateDependenciesBefore(Database *db)
{
	// send that representationType to the database
	_modelDataPair->updateDatabase(db);	
}


void CollectionHasDataset::setCollection(PCollection* pCollection)
{
	// debugLog << "In CollectionHasDataset::setCollection";
	_collection = pCollection;

}

void CollectionHasDataset::setModelDataPair(ModelDataPair* _MDpair)
{
	// debugLog << "In CollectionHasDataset::setModelDataPair" << std::endl;
	_modelDataPair = _MDpair;

}


void CollectionHasDataset::fillInFromResult(const Result &res)
{
	std::cout << typeid(res).name() << std::endl;
	_modelDataPair->getPidFromResults(res);
	_collection->getPidFromResults(res);
}

/// ------------------ RETRIEVING STUFF -----------------------
CollectionHasDataset* CollectionHasDataset::collectHasDatasetByPrimaryId(int id, Database *db)
{
    return Cache<CollectionHasDataset>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void CollectionHasDataset::retrieveDependencies(Result &res, Database *db)
{
	std::string mdp_id = ModelDataPair::staticSqlIDName();
	std::string collect_id = PCollection::staticSqlIDName();


	if (!Utility::isNull(res[mdp_id]))
	{
		// debugLog << "Retrieving from CollectionHasDataset->ModelDataPair" << std::endl;
		delete _modelDataPair;

		std::cout << "res[mdp_id] = " + res[mdp_id] << std::endl;
		 ModelDataPair* mdp = ModelDataPair::modelDataPairByPrimaryId(std::stoi(res[mdp_id]), db);
		_modelDataPair = mdp;
	}
	else if (!Utility::isNull(res[collect_id]))
	{
		// debugLog << "Retrieving from CollectionHasDataset->PCollection" << std::endl;
		delete _collection;

		std::string collect_id = PCollection::staticSqlIDName();
		std::cout << "res[collect_id] = " + res[collect_id] << std::endl;
		PCollection* pCollect = PCollection::pCollectionByPrimaryId(std::stoi(res[collect_id]), db);	
		_collection = pCollect;
	}
}





