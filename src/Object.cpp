// Object.cpp
#include <iostream>
#include "Object.h"
#include "Database.h"
#include "Utility.h"
using namespace mulch;


void Object::initialInsert(Database *db)
{
	std::cout << "Starting updating Database" << std::endl; //debug
	// first insert query that updates columns that have a no null constrain 
	std::string constrain_query = insertQuery();	
	db->query(constrain_query);	
	std::cout << constrain_query << std::endl; //debug
}

void Object::updateExisting(Database *db)
{
	std::cout << "Which table are you currently updating the dependecies?" << std::endl;
	std::cout << sqlIdName() << std::endl;	
	if (primaryId() < 0)
	{
		throw std::runtime_error("negative pid");
	}

	std::string query = updateQuery(); 
	std::cout << query << std::endl;
	db->query(query);
}


void Object::selectExisting(Database *db)
{
	if (primaryId() < 0)
	{
		_pid = _tableId;
	}
	std::string which_table = sqlIdName();
	std::cout << which_table << std::endl;
	std::string query = selectPidQuery(); 
	std::cout << query << std::endl;
	db->query(query);
}


void Object::updatePid(Database *db)
{
	std::string id_back = queryLastId();
	db->query(id_back);
	std::vector<Result> res = db->results();

	std::string pid = res[0]["pid"];
	_pid = atoi(pid.c_str());	
	std::cout << _pid << std::endl;
}


void Object::getPidFromResults(const Result &res)
{
	std::string nameofID = sqlIdName();
	std::cout << nameofID << std::endl;
	// std::cout << res[nameofID] << std::endl;
	int name_pid = atoi(res.at(nameofID).c_str());


	// set primary ID
	setPrimaryId(name_pid);
}

void Object::updateDatabase(Database *db)
{
	std::cout << "Beginning updating Database... \n" << std::endl;
	std::string querySetForeignOn = Utility::SetForeignKeysOn();
	db->query(querySetForeignOn);

	updateDependenciesBefore(db); 
	std::cout << "Finish updating dependecies.\n" << std::endl;
	// if the object doesn't exist in the database yet,
	if (!alreadyInDatabase())
	{
		initialInsert(db);
		updatePid(db);
		updateExisting(db);
	}
	else
	{
		// std::cout << "In updateDatabase, but something wrong. Do nothing for now. \n" << std::endl;
		// we need to create an UPDATE query that only acts on our primary ID
		// send that query to the database
	}

	std::cout << "Which table are you currently updating the dependecies?" << std::endl;
	std::cout << sqlIdName() << std::endl;	
	updateDependenciesAfter(db);	
}

// mulch::Result Object::retrieveExisting(int pid, Database *db)
// {
// 	setPrimaryId(pid);
// 	// fill al my other infos in the table
// 	selectExisting(db);
// 	std::vector<Result> results = db->results();

// 	fillInFromResults(results);
// 	//result[0] is a map. it will have: model_id = 3, rep_id = 3 ...
// 	retrieveDependencies(results[0] , db);
// }
mulch::Result Object::retrieveExisting(int pid, Database *db)
{

    setPrimaryId(pid);
    selectExisting(db);
    std::vector<Result> results = db->results();
    if (results.size() == 0)
    {
        throw std::runtime_error("While retrieveExisting: no existing value in the table");
    }
    else
    {
    // Call fillInFromResults on each element of the vector
	    std::cout << "Number of results: " << results.size() << std::endl;
	    for (const auto& res : results) 
	    {
	        fillInFromResults(res);
	    }
	}

    // Combine the results into a single mulch::Result object
    mulch::Result combinedResult;
    for (const auto& res : results) {
        for (const auto& kvp : res) {
            combinedResult[kvp.first] = kvp.second;
        }
    }
    retrieveDependencies(results[0] , db);

    return combinedResult;
}



std::string Object::queryLastId()
{
	return "SELECT last_insert_rowid() AS pid;"; // debug 
}

void Object::persist()
{
	Database *db = new Database("mulch.db");
	db->open();
	updateDatabase(db);
	db->close();
}


void Object::retrieveFromResult(const mulch::Result &res, Database *db)
{
    std::string nameId = sqlIdName();
    // debug 
	for (auto it = res.begin(); it != res.end(); ++it) 
	{
	    const std::string& key = it->first;
	    const std::string& value = it->second;
	    std::cout << "Key: " << key << ", Value: " << value << std::endl;
	}

    int pid = std::stoi(res.at(nameId));

    setPrimaryId(pid);

    mulch::Result copyOfRes = res; // create a non-const copy of the res object
    fillInFromDatabase(copyOfRes, db);
}


void Object::fillInFromDatabase(Result &res, Database *db)
{

	mulch::Result fullRes = retrieveExisting(_pid, db);
	fillInFromResults(fullRes);
	retrieveDependencies(res, db);

}


