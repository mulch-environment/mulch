// Object.cpp

#include "Object.h"
#include "Database.h"
#include "Utility.h"
#include <iostream>
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
	std::string query = updateQuery(); 
	std::cout << query << std::endl; //debug
	db->query(query);
}

void Object::updatePid(Database *db)
{
	std::string id_back = queryLastId();
	db->query(id_back);
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
		updateExisting(db);
		updatePid(db);
		// now the database "results" should be populated with the last ID
		std::vector<Result> res = db->results();

		for (const Result &r : res)
		{
			for (auto it = r.begin(); it != r.end(); it++)
			{
				std::cout << "result: " << it->first << " to " << it->second << std::endl;
			}
		}

		if (res.size() != 1)
		{
		//	throw mulch::SQLiteError("ID of inserted object not available");
		}

		std::string pid = res[0]["pid"]; // haven't actually tested this - hope it works!
		std::cout << pid << std::endl; // this still needs converting into an integer and putting into _pid
		_pid = atoi(pid.c_str());	

	}

	else
	{
		// we need to create an UPDATE query that only acts on our primary ID
		// send that query to the database
	}

	// and just make sure there are no errors
}

std::string Object::queryLastId()
{
	return "SELECT last_insert_rowid() AS pid;"; // debug 
}

