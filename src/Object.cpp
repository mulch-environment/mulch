// Object.cpp
#include <iostream>
#include <sqlite3.h>
#include "Object.h"
#include "Database.h"
#include "Utility.h"

using namespace mulch;

void Object::initialInsert(Database *db)
{
	debugLog << "Run insertQuery for ";
	debugLog << sqlIdName();

	std::string constrain_query = insertQuery();	
	db->query(constrain_query);	
	debugLog << constrain_query; //debug
}

void Object::updateExisting(Database *db)
{
	debugLog << "Run updateQuery for ";
	debugLog << sqlIdName();

	if (primaryId() < 0)
	{
		throw std::runtime_error("negative pid");
	}

	std::string query = updateQuery(); 
	debugLog << query;
	db->query(query);
}



void Object::selectExisting(Database *db)
{
	if (primaryId() < 0)
	{
		_pid = _tableId;
	}
	std::string which_table = sqlIdName();
	debugLog << which_table;
	std::string query = selectPidQuery(); 
	debugLog << query;
	db->query(query);
}


void Object::updatePid(Database *db)
{
	std::string id_back = queryLastId();
	db->query(id_back);
	std::vector<Result> res = db->results();

	std::string pid = res[0]["pid"];
	_pid = atoi(pid.c_str());	
	// debugLog<<"After running the insert query, the updated Pid is:";
	// debugLog << _pid;
}


void Object::getPidFromResults(const Result &res)
{
	std::string nameofID = sqlIdName();
	debugLog << nameofID;
	int name_pid = atoi(res.at(nameofID).c_str());


	// set primary ID
	setPrimaryId(name_pid);
}

void Object::updateDatabase(Database *db)
{
	debugLog << "Beginning updating table... \n";
	std::string querySetForeignOn = Utility::SetForeignKeysOn();
	db->query(querySetForeignOn);
	// debugLog << "Which table are you currently updating the dependecies?";
	// debugLog << sqlIdName();

	updateDependenciesBefore(db); 
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

	updateDependenciesAfter(db);
	debugLog << "Finish updating dependecies for table: \n";	
	debugLog << sqlIdName();	

}

mulch::Result Object::retrieveExisting(int pid, Database *db)
{
    setPrimaryId(pid);
    selectExisting(db);

    std::vector<Result> results = db->results();
    if (results.size() == 0)
    {
        throw std::runtime_error("While retrieveExisting: The id you are trying to call is not registered in the table.");
    }
    else
    {
    // Call fillInFromResults on each element of the vector
    	// debugLog << "Number of results: ";
	    for (const auto& res : results) 
	    {
	        fillInFromResults(res);
	    }
	}
    // Combine the results into a single mulch::Result object
    mulch::Result combinedResult;
    for (const auto& res : results) 
    {
        for (const auto& kvp : res) 
        {
            combinedResult[kvp.first] = kvp.second;
        }
    }
    retrieveDependencies(results[0] , db);
    std::string nameId = sqlIdName();
    debugLog << nameId;
    return combinedResult;
}



std::string Object::queryLastId()
{
	return "SELECT last_insert_rowid() AS pid;"; // debug 
}

void Object::persist()
{
	Database *db = new Database("mulch.db");
	int version;
	version = db->getVersion(); // Set the version number in the Database object
	db->open(version);
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


