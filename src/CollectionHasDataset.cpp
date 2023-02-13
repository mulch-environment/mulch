// CollectionHasDataset.cpp


#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "Collection.h"
using namespace mulch;

CollectionHasDataset::CollectionHasDataset()
{
	_modelDataPair = new ModelDataPair();
	_collection = new Collection();

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
	query = "UPDATE CollectionHasDataset SET modeldatapair_id =  WHERE Collectionhasdataset_id = 2";
	query += std::to_string(primaryId());
	query = " ";

	return query;
}

std::string CollectionHasDataset::selectPidQuery()
{
	std::string query;
	query = "SELECT collectionhasdataset_id FROM CollectionHasDataset";
	query += ";";

	return query;
}


void CollectionHasDataset::updateDependencies(Database *db)
{
	// send that representationType to the database
	_modelDataPair->updateDatabase(db);
	_collection->updateDatabase(db);
	
}



