// CollectionHasDataset.cpp
#include "CollectionHasDataset.h"
#include "PModelDataPair.h"
#include "ModelDataPair.h"
#include "Collection.h"
#include "PCollection.h"



using namespace mulch;

CollectionHasDataset::CollectionHasDataset()
{
	_modelDataPair = nullptr;
	_collection = nullptr;
}

std::string CollectionHasDataset::insertQuery()
{	
	std::string query;
	query = "INSERT INTO CollectionHasDataset (modeldatapair_ID, collection_id) VALUES (";
	query += std::to_string(_modelDataPair->primaryId());
	query += ",";
	query += std::to_string(_collection->primaryId());
	query += ");";
	debugLog << query;

	return query;
}


std::string CollectionHasDataset::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
	return query;
}

std::string CollectionHasDataset::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM CollectionHasDataset WHERE collectionhasdataset_id = ";
	query += std::to_string(primaryId());
	query += ";";

	return query;
}


void CollectionHasDataset::updateDependenciesBefore(Database *db)
{
	// send that representationType to the database
	debugLog << "Update _modelDataPair from CollectionHasDataset::updateDependenciesBefore";
	_modelDataPair->updateDatabase(db);	
}


void CollectionHasDataset::setCollection(PCollection* pCollection)
{
	// DebugLog debugLog;
	// debugLog<< "In CollectionHasDataset::setCollection";
	_collection = pCollection;

}

void CollectionHasDataset::setModelDataPair(PModelDataPair* _MDpair)
{
	// // DebugLog debugLog;
	// debugLog<<"In CollectionHasDataset::setModelDataPair";
	_modelDataPair = _MDpair;

}


void CollectionHasDataset::fillInFromResults(const Result &res)
{
	debugLog << "Inside CollectionHasDataset::fillInFromResults(const Result &res)";
	_modelDataPair = new PModelDataPair();
	_modelDataPair->getPidFromResults(res);
	_collection = new PCollection();
	_collection->getPidFromResults(res);
}

/// ------------------ RETRIEVING STUFF -----------------------
CollectionHasDataset* CollectionHasDataset::collectHasDatasetByPrimaryId(int id, Database *db)
{
    return Cache<CollectionHasDataset>::cacheByPrimaryId(id, db); // Use the template function from the cache
}

void CollectionHasDataset::retrieveDependencies(Result &res, Database *db)
{
	std::string mdp_id = PModelDataPair::staticSqlIDName();
	std::string collect_id = PCollection::staticSqlIDName();


	if (!Utility::isNull(res[mdp_id]))
	{
		// debugLog << "Retrieving from CollectionHasDataset->PModelDataPair";
		delete _modelDataPair;
		_modelDataPair = nullptr;

		// debugLog << "res[mdp_id] = " + res[mdp_id];
		PModelDataPair* mdp = PModelDataPair::modelDataPairByPrimaryId(std::stoi(res[mdp_id]), db);
		_modelDataPair = mdp;
	}
	else if (!Utility::isNull(res[collect_id]))
	{
		// debugLog << "Retrieving from CollectionHasDataset->PCollection" << std::endl;
		delete _collection;
		_collection = nullptr;

		std::string collect_id = PCollection::staticSqlIDName();
		// debugLog << "res[collect_id] = " + res[collect_id];
		PCollection* pCollect = PCollection::pCollectionByPrimaryId(std::stoi(res[collect_id]), db);	
		_collection = pCollect;
	}
}





