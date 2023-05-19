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
std::vector<int> Collection::retrieveCHDId(int id, Database *db)
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


std::vector<const Collection*> Collection::collectByPrimaryId(int id, Database *db)
{
	std::vector<int> chd_id = retrieveCHDId(id, db); 

	std::vector<CollectionHasDataset*> chds; // Vector to store all chdPair values
    std::vector<const Collection*> collections; // Vector to store the retrieved collections

	for (const auto& chd_id_value : chd_id)	
	{
        // std::cout << chd_id_value << std::endl; // Print each chd_id value
        CollectionHasDataset* chd = CollectionHasDataset::collectHasDatasetByPrimaryId(chd_id_value, db);
        chds.push_back(chd); // Store the chdPair in the vector
        const Collection* collection = chd->getCollection(); // Retrieve the collection
        collections.push_back(collection); // Store the collection pointer

	}

    return collections; // Return the vector of collection pointers
}






























