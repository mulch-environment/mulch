// Object.cpp

#include "Object.h"
#include "Database.h"
#include <iostream>
using namespace mulch;

// private:
// void Object::initialInsert
// void Object::updatePid
// void Object::updateExisting

void Object::updateDatabase(Database *db)
{
	updateDependencies(db); 
	
	// if the object doesn't exist in the database yet,
	if (!alreadyInDatabase())
	{
		std::cout << alreadyInDatabase() << std::endl;  // debug
		std::cout << "Starting updating Database" << std::endl; //debug
		// first insert query that updates constrains columns 
		std::string constrain_query = insertQuery();		
		// we need to create an INSERT query (sqlite3)
		std::string query = updateQuery(); 
		std::cout << constrain_query << std::endl; //debug
		std::cout << query << std::endl; //debug

		// update dependencies
		db->query(constrain_query);
		// send that query to the database
		db->query(query);

		// we also need to get back the primary ID which has been assigned to our object
		std::string id_back = queryLastId();
		db->query(id_back);

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

