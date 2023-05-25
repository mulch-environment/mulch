// CollectionHasDataset.cpp
#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "Collection.h"
using namespace mulch;

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

	return query;
}


std::string CollectionHasDataset::updateQuery()
{
	std::string query;
	query = " ";
	return query;
}

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


void CollectionHasDataset::setCollection(Collection* collection)
{
	std::cout<<"In CollectionHasDataset::setCollection"<<std::endl;
	_collection = collection;

}

void CollectionHasDataset::setModelDataPair(ModelDataPair* _MDpair)
{
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
	std::string collect_id = Collection::staticSqlIDName();


	if (!Utility::isNull(res[mdp_id]))
	{
		std::cout << "Retrieving from CollectionHasDataset->ModelDataPair \n" << std::endl;
		delete _modelDataPair;

		std::cout << "res[mdp_id] = " + res[mdp_id] << std::endl;
		 ModelDataPair* mdp = ModelDataPair::modelDataPairByPrimaryId(std::stoi(res[mdp_id]), db);
		_modelDataPair = mdp;
	}
	else if (!Utility::isNull(res[collect_id]))
	{
		std::cout << "Retrieving from PData->DataCrystallographicInfo \n" << std::endl;
		delete _collection;

		std::string collect_id = Collection::staticSqlIDName();
		std::cout << "res[collect_id] = " + res[collect_id] << std::endl;
		Collection* collect = Collection::collectByPrimaryId(std::stoi(res[collect_id]), db);	
		_collection = collect;
	}
}





