// Object.cpp
#include <iostream>
#include <sqlite3.h>
#include "Object.h"
#include "Database.h"
#include "Utility.h"

using namespace mulch;


void Object::initialInsert(Database *db)
{
	Utility::debugLogTest("Run insertQuery for ");
	Utility::debugLogTest(sqlIdName());

	std::string constrain_query = insertQuery();	
	db->query(constrain_query);	
	std::cout << constrain_query << std::endl; //debug
}

void Object::updateExisting(Database *db)
{
	Utility::debugLogTest("Run updateQuery for ");
	Utility::debugLogTest(sqlIdName());

	if (primaryId() < 0)
	{
		throw std::runtime_error("negative pid");
	}

	std::string query = updateQuery(); 
	std::cout << query << std::endl;
	db->query(query);
}

// void Object::executeUpdateQuery(Database *db, const std::string& query, const std::vector<std::string>& parameters) 
// {
//     sqlite3_stmt* statement;
//     if (sqlite3_prepare_v2(db->getSQLiteHandle(), query.c_str(), -1, &statement, nullptr) == SQLITE_OK)
//     {
//         // Bind the parameters if provided
//         for (size_t i = 0; i < parameters.size(); ++i)
//         {
//             sqlite3_bind_text(statement, i + 1, parameters[i].c_str(), -1, SQLITE_STATIC);
//         }

//         // Execute the statement
//         sqlite3_step(statement);

//         // Finalize the statement
//         sqlite3_finalize(statement);
//     }
// }

void Object::executeUpdateQuery(Database* db, const std::string& query, const std::vector<std::string>& parameters)
{
	if (query.empty())
    {
        // No query to execute, return early
        return;
    }
    sqlite3_stmt* statement = nullptr;

    if (sqlite3_prepare_v2(db->getSQLiteHandle(), query.c_str(), -1, &statement, nullptr) == SQLITE_OK)
    {
        int index = 1;
        for (const std::string& parameter : parameters)
        {
            sqlite3_bind_text(statement, index, parameter.c_str(), -1, SQLITE_STATIC);
            index++;
        }

        int result = sqlite3_step(statement);
        if (result != SQLITE_DONE)
        {
            const char* errorMessage = sqlite3_errmsg(db->getSQLiteHandle());
            // Handle the error, e.g., throw an exception or log the error message
            throw std::runtime_error("Failed to execute update query: " + std::string(errorMessage));
        }

        sqlite3_finalize(statement);
    }
    else
    {
        const char* errorMessage = sqlite3_errmsg(db->getSQLiteHandle());
        // Handle the error, e.g., throw an exception or log the error message
        throw std::runtime_error("Failed to prepare update query: " + std::string(errorMessage));
    }
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
	Utility::debugLogTest("After running the insert query, the updated Pid is:");
	Utility::debugLogTest(_pid);
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
	std::cout << "Beginning updating table... \n" << std::endl;
	std::string querySetForeignOn = Utility::SetForeignKeysOn();
	db->query(querySetForeignOn);
	Utility::debugLogTest("Which table are you currently updating the dependecies?");
	Utility::debugLogTest(sqlIdName());

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
	std::cout << "Finish updating dependecies for table: \n";	
	std::cout << sqlIdName() << std::endl;	

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
        throw std::runtime_error("While retrieveExisting: The id you are trying to call is not registered in the table.");
    }
    else
    {
    // Call fillInFromResults on each element of the vector
    	Utility::debugLogTest("Number of results: ");
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
    std::cout << nameId <<std::endl;
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


