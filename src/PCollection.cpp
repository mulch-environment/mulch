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

const PModelDataPair* PCollection::getModelDataPairFromCollection(int index) const
{
    if (index < 0 || index >= _chds.size())
    {
        return nullptr;
    }
    CollectionHasDataset* chd = _chds[index];
    return chd->getModelDataPair();
}


void PCollection::sentToCHD(PModelDataPair *MDpair)
 {
// 	debugLog << "Adding data to CollectionHasDataset";
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
int PCollection::countMDPId(int id, Database *db)
{
	int CURRENT_VERSION = 2;
    if (db == nullptr)
    {
        db = new Database("mulch.db");
        db->open(CURRENT_VERSION);
    }

	std::string query;
	query = "SELECT modeldatapair_id FROM CollectionHasDataset WHERE modeldatapair_id = ";
	query += std::to_string(id);
	query += ";";
	Utility::protectsql(query);

    // Execute the query
    db->query(query);

	// Retrieve the query results
    std::vector<Result> results = db->results();
    // Initialize chd_id as an empty vector
    std::vector<int> mdp_id; 
    std::string mdp_id_str;
    if (!results.empty())
    {
    	for (const auto& row : results)
		{	
			auto iter = row.find("modeldatapair_id");
			if (iter != row.end())
			{
			    mdp_id_str = iter->second;
			}
        	mdp_id.push_back(std::stoi(mdp_id_str)); 
    	}
    }
    return mdp_id.size();
}


PCollection* PCollection::pCollectionByPrimaryId(int id, Database *db)
{
    return Cache<PCollection>::cacheByPrimaryId(id, db); // Use the template function from the cache
}



