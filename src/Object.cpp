// Object.cpp

#include "Object.h"
#include "Database.h"
#include "Utility.h"
#include <iostream>
using namespace mulch;

// Object::Object()
// {

// }

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

	if (primaryId() < 0)
	{
		throw std::runtime_error("negative pid");
	}

	std::string query = updateQuery(); 
	db->query(query);
}


void Object::selectExisting(Database *db)
{

	if (primaryId() < 0)
	{
		throw std::runtime_error("negative pid");
	}

	std::string query = selectPidQuery(); 
	db->query(query);
}


void Object::updatePid(Database *db)
{
	std::string id_back = queryLastId();
	db->query(id_back);
	std::vector<Result> res = db->results();

	std::string pid = res[0]["pid"];
	_pid = atoi(pid.c_str());	
	std::cout << "INSIDE updatePid: _pid = " << std::endl;
	std::cout << _pid << std::endl;
}


void Object::getPidFromResults(const Result &res)
{
	std::string nameofID = sqlIdName();
	std::cout << "Representation type ID from fillInFromResults \n" << std::endl;
	// std::cout << res[nameofID] << std::endl;
	int name_pid = atoi(res.at(nameofID).c_str());


	// set primary ID
	setPrimaryId(name_pid);
}

void Object::updateDatabase(Database *db)
{

	std::string querySetForeignOn = Utility::SetForeignKeysOn();
	db->query(querySetForeignOn);

	updateDependencies(db); 

	// if the object doesn't exist in the database yet,
	if (!alreadyInDatabase())
	{

		initialInsert(db);
		updatePid(db);
		updateExisting(db);
	}
		// now the database "results" should be populated with the last ID
		// for (const Result &r : res)
		// {
		// 	for (auto it = r.begin(); it != r.end(); it++)
		// 	{
		// 		std::cout << "result: " << it->first << " to " << it->second << std::endl;
		// 	}
		// }

	// }

	else
	{
		// we need to create an UPDATE query that only acts on our primary ID
		// send that query to the database
	}

	// and just make sure there are no errors
	
}

mulch::Result Object::retrieveExisting(Database *db)
{
	selectExisting(db);
	std::vector<Result> res = db->results();

	if (res.size() != 1)
	{
		throw std::runtime_error("something is wrong with res");
	}  

	for (int i = 0; i < res.size(); i++) {
        std::cout << res.at(i)["model_id"] << ' ';
    }
	return res[0];
}

std::string Object::queryLastId()
{
	return "SELECT last_insert_rowid() AS pid;"; // debug 
}



