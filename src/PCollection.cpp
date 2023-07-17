// PCollection.cpp
#include <iostream>
#include "PCollection.h"
#include "Collection.h"
#include "CollectionHasDataset.h"
#include "ModelDataPair.h"
#include "PModelDataPair.h"
#include "PData.h"
#include "PModel.h"
#include "EnumTables.h"
#include "Utility.h"
#include "DebugLog.h"
using namespace mulch;

PCollection::PCollection()
{

}

int PCollection::getPrimaryId() const
{
	return primaryId();
}

int PCollection::getCountPids(Database* db) const
{
	int CURRENT_VERSION = 2;
    if (db == nullptr)
    {
        db = new Database("mulch.db");
        db->open(CURRENT_VERSION);
    }
    return db->countPids();
}

ModelDataPair* PCollection::getMDP(int index)
{
	const std::vector<CollectionHasDataset*>& chdsVector = getCHDsVector();
	if (chdsVector.size() == 0) 
	{
        throw std::runtime_error("Error: _chds vector is empty. Cannot retrieve ModelDataPair.");
    }
	const PModelDataPair* pmdp = chdsVector[index]->getModelDataPair();
	ModelDataPair* mdp = const_cast<ModelDataPair*>(static_cast<const ModelDataPair*>(pmdp));
	return mdp;
}

std::string PCollection::insertQuery()
{
	std::string query;
	query = "INSERT INTO Collection (fixed) VALUES ";
	query += "(";
	query += Utility::boolToString(_fixed);
	query += ");";
	Utility::protectsql(query);
	debugLog << query;
	return query;	
}

std::string PCollection::updateQuery()
{
	std::string query;
	query = "";
	Utility::protectsql(query);
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
    PModelDataPair *mdp = new PModelDataPair();
    mdp->setRep(rep);
    mdp->setFile(pdbName);
    sentToCHD(mdp);
}

void PCollection::addData(DataEnum datatype, std::string datafile)
{
    PModelDataPair *mdp = new PModelDataPair();
    mdp->setDataType(datatype);
    mdp->setDataFile(datafile);
    sentToCHD(mdp);
}

void PCollection::addModelDataPair(RepresentationEnum rep, std::string pdbName, DataEnum datatype, std::string datafile)
{
	debugLog << "Adding data to ModelDataPair";
    PModelDataPair *mdp = new PModelDataPair();
    mdp->setRep(rep);
    mdp->setFile(pdbName);
    mdp->setDataType(datatype);
    mdp->setDataFile(datafile);
    sentToCHD(mdp);
    mdp->persist();
    
}

void PCollection::sentToCHD(PModelDataPair *MDpair)
 {
// 	debugLog << "Adding data to CollectionHasDataset";
 	CollectionHasDataset *chd = new CollectionHasDataset();
 	chd->setCollection(this);
 	chd->setModelDataPair(MDpair);
 	_chds.push_back(chd);

 	std::cout << "Inside PCollection::sentToCHD, line 117" << std::endl;
 }

void PCollection::updateDependenciesAfter(Database *db) 
{
	std::cout << "IN UPDATEDATABASEAFTER, LINE 12" << std::endl; 
	std::cout << _chds.size() << std::endl; 
	for (CollectionHasDataset *chd: _chds)
	{
		chd->updateDatabase(db);
	}
}


/// ------------------ RETRIEVING STUFF -----------------------
int PCollection::countChdIds(Database *db) const
{
    int count = 0;
    std::string query = "SELECT collectionhasdataset_id FROM CollectionHasDataset WHERE collection_id = " + std::to_string(getPrimaryId()) + ";";
    
    int CURRENT_VERSION = 2;
    // Execute the query and retrieve the results
    if (db == nullptr)
    {
        db = new Database("mulch.db");
        // Open the database connection
        db->open(CURRENT_VERSION);
    }
    
    db->query(query);
    std::vector<Result> results = db->results();
    
    // Count the number of IDs returned
    count = results.size();

    
    return count;
}


PCollection* PCollection::pCollectionByPrimaryId(int id, Database *db)
{
    return Cache<PCollection>::cacheByPrimaryId(id, db); // Use the template function from the cache
}



