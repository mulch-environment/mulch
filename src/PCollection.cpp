// PCollection.cpp
#include <iostream>
#include "PCollection.h"
#include "Collection.h"
#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "PData.h"
#include "PModel.h"
#include "EnumTables.h"
#include "Utility.h"
using namespace mulch;

PCollection::PCollection()
{

}


std::string PCollection::insertQuery()
{
	std::string query;
	query = "INSERT INTO Collection (fixed) VALUES ";
	query += "(";
	query += Utility::boolToString(_fixed);
	query += ");";
	return query;	
}

std::string PCollection::updateQuery()
{
	std::string query;
	// fixed = true or false vlaue, collectiontion_id = sql_id
	query = " ";

	return query;
}

std::string PCollection::selectPidQuery()
{
	std::string query;
	query = "SELECT * FROM Collection WHERE collection_id = ";
	query += std::to_string(primaryId());
	query += ";";
	Utility::protectsql(query);

	return query;
}

void PCollection::addModel(RepresentationEnum rep, std::string pdbName)
{
    ModelDataPair *mdp = new ModelDataPair();
    mdp->setRep(rep);
    mdp->setFile(pdbName);
    sentToCHD(mdp);
}

void PCollection::addData(DataEnum datatype, std::string datafile)
{
    ModelDataPair *mdp = new ModelDataPair();
    mdp->setDataType(datatype);
    mdp->setDataFile(datafile);
    sentToCHD(mdp);
}

void PCollection::addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
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

const ModelDataPair* PCollection::getModelDataPairFromCollection(int index) const
{
    if (index < 0 || index >= _chds.size())
    {
        return nullptr;
    }
    CollectionHasDataset* chd = _chds[index];
    return chd->getModelDataPair();
}


void PCollection::sentToCHD(ModelDataPair *MDpair)
 {
 	std::cout<<"Adding data to CollectionHasDataset"<<std::endl;	
 	CollectionHasDataset *chd = new CollectionHasDataset();
 	chd->setCollection(this);
 	chd->setModelDataPair(MDpair);
 	_chds.push_back(chd);
 }

void PCollection::updateDependenciesAfter(Database *db) 
{
	for (CollectionHasDataset *chd: _chds)
	{
		chd->updateDatabase(db);
	}
}




/// ------------------ RETRIEVING STUFF -----------------------
std::vector<int> PCollection::retrieveCHDId(int id, Database *db)
{
	std::string query;
	query = "SELECT collectionhasdataset_id FROM CollectionHasDataset WHERE collection_id = ";
	query += std::to_string(id);
	query += ";";
	Utility::protectsql(query);

	std::cout << query << std::endl;
    // Execute the query
    db->query(query);

	// Retrieve the query results
    std::vector<Result> results = db->results();
    // Initialize chd_id as an empty vector
    std::vector<int> chd_id; 
    std::string chd_id_str;

    if (!results.empty())
    {
    	for (const auto& row : results)
		{	
			auto iter = row.find("collectionhasdataset_id");
			if (iter != row.end()) 
			{
			    chd_id_str = iter->second;
			}
        	// Add the integer value to the chd_id vector
        	chd_id.push_back(std::stoi(chd_id_str)); 
    	}
    }
    // for (const auto& id : chd_id)
    // {
    // 	std::cout << id << std::endl;
    // }
    std::cout << "How many CollectionHasDataset inputs?" << std::endl;
    std::cout << chd_id.size() << std::endl;
    return chd_id;
}


void PCollection::getDatasetCascade(int id, Database *db)
{	
	std::vector<int> chd_id = retrieveCHDId(id, db); 
	std::vector<CollectionHasDataset*> chds; // Vector to store all chdPair values
	for (const auto& chd_id_value : chd_id)
	{
		std::cout << "From Collection::getDatasetCascade, the chd_id is ";
		std::cout << chd_id_value  << std::endl;

        CollectionHasDataset* chd = CollectionHasDataset::collectHasDatasetByPrimaryId(chd_id_value, db);
        chds.push_back(chd); // Store the chdPair in the vector
	}


}


PCollection* PCollection::pCollectionByPrimaryId(int id, Database *db)
{
    return Cache<PCollection>::cacheByPrimaryId(id, db); // Use the template function from the cache
}




